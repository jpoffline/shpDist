
#include "COORD_CONVERT.h"


double COORD_CONVERT::cart2r(double x, double y){
	return std::sqrt(x * x + y * y);
}
double COORD_CONVERT::cart2t(double x, double y){
	return atan2(y, x);
}
double COORD_CONVERT::pol2x(double r, double t){
	return r * std::sin( t );
}

double COORD_CONVERT::pol2y(double r, double t){
	return r * std::cos( t );
}

TUPLE COORD_CONVERT::cart2pol(double x, double y){
	return TUPLE(cart2r(x,y), cart2t(x,y));
}

TUPLE COORD_CONVERT::pol2cart(double r, double t){
	return TUPLE(pol2x(r,t), pol2y(r,t));
}