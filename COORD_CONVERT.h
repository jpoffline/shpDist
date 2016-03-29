
#include <cmath>
#include <math.h>

#include "TUPLE.h"

#ifndef _TUPLE__
#define _TUPLE__



class COORD_CONVERT{
	
	public:
		double cart2r(double, double);
		double cart2t(double, double);
		double pol2x(double, double);
		double pol2y(double, double);
		
		TUPLE cart2pol(double, double);
		TUPLE  pol2cart(double, double);
	
};

#endif