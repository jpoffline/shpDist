#include "CREATE_DIST.h"

CREATE_DIST::CREATE_DIST(){
    _n_locations = 100;
}
CREATE_DIST::CREATE_DIST(int nlocs){
    _n_locations = nlocs;
}

void CREATE_DIST::add_location(TEST_LOCATION location){
    
    _locations.push_back(location);
    
}

double uniform_random(){
	
    return ((double) rand() / (RAND_MAX));
	
}

double pi(){
	
    return 3.1412;
	
}
    
TUPLE CREATE_DIST::conv_pol2cart(double r, double t){
	
    return _convert.pol2cart(r,t);
	
} 

TUPLE CREATE_DIST::conv_cart2pol(double x, double y){
	
    return _convert.cart2pol(x,y);
	
}    
   
void CREATE_DIST::print_point_locations(){
	
	for(int i = 0; i < _locations.size(); i++){
		std::cout << _locations[i].get(0) << " " << _locations[i].get(1) << " " << _locations[i].get_field() << std::endl;
	}
	
}   

double CREATE_DIST::get_field_value(double r, double t){
	
	return std::exp( - r );
	
}
    
void CREATE_DIST::create_dist(){
    
    srand (time(NULL));
    
    double rmax = 10;
    
    for(int i = 0; i < _n_locations; i++){
        TEST_LOCATION loc;
        
        double ran_r = uniform_random() * rmax;
        double theta_r = uniform_random() * 2.0 * pi();
        
        loc.set_loc(conv_pol2cart(ran_r,theta_r));
		
        loc.set_field(get_field_value(ran_r, theta_r));
        add_location(loc);
    }
    
}