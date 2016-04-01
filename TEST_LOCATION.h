
#include <vector>



#ifndef _TEST_LOCATION__
#define _TEST_LOCATION__

#include "TUPLE.h"

class TEST_LOCATION{
    
    private:
        std::vector<double> _location;
        double _scalar_field;
        
    public:
        double get_scalar_field();
        void set_loc(double, double);
        void set_loc(TUPLE);
        void set_field(double);
		std::vector<double> get();
		double get(int);
        double get_field();
};

#endif