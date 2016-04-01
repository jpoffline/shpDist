#include "TEST_LOCATION.h"


double TEST_LOCATION::get_scalar_field(){
    return _scalar_field;
} 

void TEST_LOCATION::set_loc(double x, double y){
    _location.push_back(x);
    _location.push_back(y);
}

void TEST_LOCATION::set_loc(TUPLE loc){
    _location.push_back(loc.get(0));
    _location.push_back(loc.get(1));
}

void TEST_LOCATION::set_field(double f){
    _scalar_field = f;
}

std::vector<double> TEST_LOCATION::get(){
	return _location;
}

double TEST_LOCATION::get(int idx){
	return _location[idx];
}

double TEST_LOCATION::get_field(){
	return _scalar_field;
}