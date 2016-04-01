
#include <cmath>
#include <math.h>



#ifndef _COORD_CONVERT__
#define _COORD_CONVERT__

#include "TUPLE.h"

class COORD_CONVERT{
	
	public:
		
		COORD_CONVERT();
		
		double cart2r(double, double);
		double cart2t(double, double);
		double pol2x(double, double);
		double pol2y(double, double);
		
		TUPLE cart2pol(double, double);
		TUPLE  pol2cart(double, double);
	
};

#endif