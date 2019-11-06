/*!
 *  \file AccumulatedMaterial.h
 *	\brief Auxillary kernel to keep track of the total accumulated amount of a variable on a surface
 *	\details This file creates an auxillary kernel that computes the total accumulated amount
 *			of a non-linear variable that has passed through a particular boundary in the mesh.
 *			This kernel couples with a non-linear variable and integrates it over the flux
 *			accross the current boundary. That integrated amount is then continuously added to
 *			prior integrals calculated to create a running total of material that has passed
 *			through the boundary.
 *
 *  \author Austin Ladshaw
 *	\date 05/18/2018
 *	\copyright This kernel was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for PhD research in the area
 *             of radioactive particle transport and settling following a
 *			   nuclear event. It was developed for the US DOD under DTRA
 *			   project No. 14-24-FRCWMD-BAA. Portions Copyright (c) 2018, all
 *             rights reserved.
 *
 *			   Austin Ladshaw does not claim any ownership or copyright to the
 *			   MOOSE framework in which these kernels are constructed, only
 *			   the kernels themselves. The MOOSE framework copyright is held
 *			   by the Battelle Energy Alliance, LLC (c) 2010, all rights reserved.
 */

/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "AccumulatedMaterial.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", AccumulatedMaterial);

template<>
InputParameters validParams<AccumulatedMaterial>()
{
	InputParameters params = validParams<AuxKernel>();
	params.addCoupledVar("coupled_vars", "List of non-linear variables coupled to this object");
    params.addCoupledVar("vxs", "List of x-direction velocities coupled to this object");
    params.addCoupledVar("vys", "List of y-direction velocities coupled to this object");
    params.addCoupledVar("vzs", "List of z-direction velocities coupled to this object");
	return params;
}

AccumulatedMaterial::AccumulatedMaterial(const InputParameters & parameters) :
AuxKernel(parameters)
{
	unsigned int n = coupledComponents("coupled_vars");
    unsigned int nx = coupledComponents("vxs");
    unsigned int ny = coupledComponents("vys");
    unsigned int nz = coupledComponents("vzs");
    
    if (n != nx || n != ny || n != nz)
    	moose::internal::mooseErrorRaw("Invalid number of variables for velocities and concentrations!");
    
	_coupled_u.resize(n);
    _coupled_u_old.resize(n);
    _vx.resize(n);
    _vy.resize(n);
    _vz.resize(n);
	
	for (unsigned int i = 0; i<_coupled_u.size(); ++i)
	{
		_coupled_u[i] = &coupledValue("coupled_vars",i);
        _coupled_u_old[i] = &coupledValueOld("coupled_vars",i);
        _vx[i] = &coupledValue("vxs",i);
        _vy[i] = &coupledValue("vys",i);
        _vz[i] = &coupledValue("vzs",i);
	}
	
}

Real AccumulatedMaterial::computeValue()
{
	Real _total = 0.0;
    
    // Velocity vector in the system or at the boundary (different for each variable)
    RealVectorValue velocity;
	
    // Only perform computations if element is on a boundary (i.e., there is a surface available for deposition)
    if (_current_elem->on_boundary() == true) //see elem.h in MOOSE framework files
    {
        
        int sides = _current_elem->n_sides();
        std::vector<BoundaryID> bid;
        //Iterate through the sides of the boundary element
        for (int i = 0; i<sides; i++)
        {
            //NOTE: BoundaryIDs are integers that identify the side sets that are boundaries
            bid = _mesh.getBoundaryIDs(_current_elem, i);
            
            //Create a normal vector for the given size and initialize to all zeros
            RealVectorValue normal;
            double area = _current_elem->side_ptr(i)->volume();
            normal(0) = 0.0;
            normal(1) = 0.0;
            normal(2) = 0.0;
            
            //normal will be zero if not a bounary side
            //This checks if the current side of the current element is on a boundary
            if (bid.size() > 0)
            {
            	//A given side should only exist on one boundary id
            	if (bid.size() > 1)
                	moose::internal::mooseErrorRaw("Invalid boundaries for element!");
                
                //NOW it is necessary to calculate the normal vector from the boundary nodes
                //This calculation is dependent on the number of nodes the side contains (i.e., dimensionality of the mesh)
                int nodes = _current_elem->side_ptr(i)->n_nodes();
                
                //this is a surface (from 3D mesh)
                if (nodes > 2)
                {
                    //Cross product of two non-parallel vectors in the plane/surface produce a normal for that surface
                    RealVectorValue a,b;
                    a(0) = _current_elem->side_ptr(i)->point(1)(0) - _current_elem->side_ptr(i)->point(0)(0);
                    a(1) = _current_elem->side_ptr(i)->point(1)(1) - _current_elem->side_ptr(i)->point(0)(1);
                    a(2) = _current_elem->side_ptr(i)->point(1)(2) - _current_elem->side_ptr(i)->point(0)(2);
                    
                    b(0) = _current_elem->side_ptr(i)->point(2)(0) - _current_elem->side_ptr(i)->point(0)(0);
                    b(1) = _current_elem->side_ptr(i)->point(2)(1) - _current_elem->side_ptr(i)->point(0)(1);
                    b(2) = _current_elem->side_ptr(i)->point(2)(2) - _current_elem->side_ptr(i)->point(0)(2);
                    
                    //Normal is the cross-product of a and b
                    normal = a.cross(b);
                    
                    //Make normal a unit vector
                    normal = normal/normal.norm();
                    
                    //Fix the direction of the normal vector (must always point away from the centroid)
                    RealVectorValue v;
                    v(0) = _current_elem->centroid()(0) - _current_elem->side_ptr(i)->point(0)(0);
                    v(1) = _current_elem->centroid()(1) - _current_elem->side_ptr(i)->point(0)(1);
                    v(2) = _current_elem->centroid()(2) - _current_elem->side_ptr(i)->point(0)(2);
                    
                    double dist = (v*normal);
                    
                    Point p;
                    p(0) = _current_elem->centroid()(0) - dist*normal(0);
                    p(1) = _current_elem->centroid()(1) - dist*normal(1);
                    p(2) = _current_elem->centroid()(2) - dist*normal(2);
                    
                    RealVectorValue normal_leaving;
                    normal_leaving(0) = p(0) - _current_elem->centroid()(0);
                    normal_leaving(1) = p(1) - _current_elem->centroid()(1);
                    normal_leaving(2) = p(2) - _current_elem->centroid()(2);
                    
                    //Direction corrected normal 
                    normal = normal_leaving/normal_leaving.norm();
                }
                //this is a line (from 2D mesh)
                else if (nodes == 2)
                {
                    //Leave blank for now, deposition on a line doesn't make sense
                }
                //this is a point (from 1D mesh)
                else if (nodes == 1)
                {
                    //Leave blank for now, deposition on a point doesn't make sense
                }
                else
                {
                    moose::internal::mooseErrorRaw("Invalid nodes for boundary!");
                }
            }//End if bid.size() > 0
            
            for (unsigned int i = 0; i<_coupled_u.size(); ++i)
            {
            	//Update velocity to the current variable's velocity
                velocity(0)=(*_vx[i])[_qp];
                velocity(1)=(*_vy[i])[_qp];
                velocity(2)=(*_vz[i])[_qp];
                
                if ((*_coupled_u[i])[_qp] > 0.0 && (normal*velocity) > 0.0)
                {
                	_total = _total + (normal*velocity)*area*_dt*(*_coupled_u[i])[_qp];
                }
            }
        }
        
    }
	return _u_old[_qp] + _total;
}
