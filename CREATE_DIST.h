
#include <vector>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */

#include <iostream>
#include <fstream>
#include <string>

#ifndef _CREATE_DIST__
#define _CREATE_DIST__

#include "TEST_LOCATION.h"
#include "TUPLE.h"
#include "COORD_CONVERT.h"
#include "HISTOGRAM.h"

class CREATE_DIST{
    
    private:
        std::vector<TEST_LOCATION> _locations;
		std::vector<double> _distances;
        int _n_locations;
		int _nbins;
        void add_location(TEST_LOCATION);
        TUPLE conv_pol2cart(double, double);
		TUPLE conv_cart2pol(double, double);
		double get_field_value(double, double);
		
		COORD_CONVERT _convert;
		
		double _largest_dist;
		double _smallest_dist;
		double _rmax;
		double compute_dist(int, int);

		
		
    public:
        CREATE_DIST();
        CREATE_DIST(int);
        void create_dist();
		void print_point_locations();
		void scan_distances();		
  		void print_distances();  
		void dump_distances(std::string);
		void print_distance_stats();
		void set_rmax(double);
		void bin_distances(std::string);
};

#endif