/*!
 *  \file CARDINAL_CloudIC.h
 *	\brief Initial Condition kernel for a Puff of Particles based from a CARDINAL simulation
 *	\details This file creates an initial condition for a non-linear variable
 *			that is dispersed in a debris cloud whose size and shape and concentration
 *			values all come from the simulation results from CARDINAL. The user MUST
 *			couple this kernel with the CARDINAL_Object UserObject in order to determine
 *			concentration values of this variable in space. Also, user MUST provide a
 *			local variable size index, which denotes the size class of this non-linear
 *			variable. That index is based on the ordering of the non-linear variables
 *			when coupled in a list in any other kernel. The list should also be in
 *			increasing size order.
 *
 *  \author Austin Ladshaw
 *	\date 08/28/2019
 *	\copyright This kernel was designed and built at the Georgia Institute
 *             of Technology by Austin Ladshaw for PhD research in the area
 *             of radioactive particle transport and settling following a
 *			   nuclear event. It was developed for the US DOD under DTRA
 *			   project No. 14-24-FRCWMD-BAA. Portions Copyright (c) 2019, all
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

#include "CARDINAL_CloudIC.h"

/**
 * All MOOSE based object classes you create must be registered using this macro.  The first
 * argument is the name of the App with an "App" suffix (i.e., "fennecApp"). The second
 * argument is the name of the C++ class you created.
 */
registerMooseObject("fennecApp", CARDINAL_CloudIC);

template<> InputParameters validParams<CARDINAL_CloudIC>()
{
    InputParameters params = validParams<InitialCondition>();
    
    params.addRequiredParam<Real>("x_center","Center of x-coordinate radius");
    params.addRequiredParam<Real>("y_center","Center of y-coordinate radius");
    params.addRequiredParam<unsigned int>("local_size_index","Local size index for the concentration variable this kernel acts on (that index is based on ordering of the coupled lists of concentration variables used in other kernels)");
    params.addRequiredParam<UserObjectName>("cardinal_object","Name of the CARDINAL_Object object");
    
    return params;
}

CARDINAL_CloudIC::CARDINAL_CloudIC(const InputParameters & parameters) :
InitialCondition(parameters),
_x_center(getParam<Real>("x_center")),
_y_center(getParam<Real>("y_center")),
_local_size_index(getParam<unsigned int>("local_size_index")),
_user_object(getUserObject<CARDINAL_Object>("cardinal_object"))
{
    
}

Real CARDINAL_CloudIC::value(const Point & p)
{
	// Convention:		p(0) == x,  p(1) == y,  p(2) == z
    Real val = 0.0;
    int parcels = _user_object.return_num_parcels();
    int sizes = _user_object.return_size_bins();
    unsigned int j = _local_size_index;
    
    //Boundary check
    if (_local_size_index >= sizes)
    	moose::internal::mooseErrorRaw("Indexing Error! Local size bin index for CARDINAL_CloudIC is invalid...");
    
    double r_dist_from_center = sqrt( (_x_center-p(0))*(_x_center-p(0)) + (_y_center-p(1))*(_y_center-p(1)) );
    double parcel_radius = 0.0;
    
    //if r_dist_from_center > parcel_radius(@ z), then no debris particles present
    //if r_dist_from_center <= parcel_radius(@ z), then return parcel_conc(@ z)
    
    //Loop through all parcels
    for (int i=0; i<parcels; i++)
    {
        //Calculate parcel radius at given z [p(2) == z]
        if (p(2) > _user_object.return_parcel_alt_top(i,j) || p(2) < _user_object.return_parcel_alt_bot(i,j))
        {
            parcel_radius = -1;
        }
        else
        {
            double slope = (_user_object.return_parcel_rad_bot(i,j) - _user_object.return_parcel_rad_top(i,j))/(_user_object.return_parcel_alt_bot(i,j) - _user_object.return_parcel_alt_top(i,j));
            parcel_radius = slope*(p(2) - _user_object.return_parcel_alt_top(i,j)) + _user_object.return_parcel_rad_top(i,j);
        }
        
        if (r_dist_from_center > parcel_radius)
        {
            val = 0.0;
        }
        else
        {
            val = _user_object.return_parcel_conc(i,j)/1.0e9;
            break;
        }
    }
    
	return val;
}
