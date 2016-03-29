
#include <vector>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iostream>

#include "TEST_LOCATION.h"
#include "COORD_CONVERT.h"

#ifndef _CREATE_DIST__
#define _CREATE_DIST__



class CREATE_DIST{
    
    private:
        std::vector<TEST_LOCATION> _locations;
        int _n_locations;
        void add_location(TEST_LOCATION);
        TUPLE conv_pol2cart(double, double);
		TUPLE conv_cart2pol(double, double);
		double get_field_value(double, double);
		
		COORD_CONVERT _convert;
		
    public:
        CREATE_DIST();
        CREATE_DIST(int);
        void create_dist();
		void print_point_locations();
		
        
};

#endif