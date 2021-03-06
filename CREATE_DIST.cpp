#include "CREATE_DIST.h"

CREATE_DIST::CREATE_DIST(){
    _n_locations = 100;
	_smallest_dist = 1000000.0;
	_largest_dist = 0.0;
	_nbins = 100;
	
}
CREATE_DIST::CREATE_DIST(int nlocs){
    _n_locations = nlocs;
	_nbins = 100;
	
	_smallest_dist = 1000000.0;
	_largest_dist = 0.0;

}

void CREATE_DIST::set_rmax(double rmax){
	_rmax = rmax;
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
    

double get_rsign(){
    if(uniform_random() < 0.5){
        return -1.0;
    }
    else{
        return 1.0;
    }
}    
    
double get_rand_pm_window(double plength){
    // Function to return a random number
    // in the range [-plength, + plength]
    
    return get_rsign() * uniform_random() * plength;
}    
    
void CREATE_DIST::create_dist(){
    
    for(int i = 0; i < _n_locations; i++){
        TEST_LOCATION loc;
        

        double testR = _rmax + 0.1;
        double x, y;
        while(testR > _rmax){
            x = get_rand_pm_window( _rmax );
            y = get_rand_pm_window( _rmax );
            testR = std::sqrt( x * x + y * y);
        }
        loc.set_loc(x,y);
        
        loc.set_field(1.0);

        add_location(loc);
    }
    
}


double CREATE_DIST::compute_dist(int idx_src, int idx_tgt){
	double dx = _locations[idx_src].get(0) - _locations[idx_tgt].get(0);
	double dy = _locations[idx_src].get(1) - _locations[idx_tgt].get(1);
	double dist = std::sqrt(dx * dx + dy * dy);
	
	if( dist > _largest_dist ){
	
		_largest_dist = dist;
	
	}	
	
	if( dist < _smallest_dist ){
	
		_smallest_dist = dist;
	
	}
	
	return(dist);
}

void CREATE_DIST::scan_distances(){
	int nlocs = _locations.size();
	for(int i = 0; i < nlocs; i++){
		for(int j = 0; j < nlocs; j++){
			if( i != j ){
				_distances.push_back( compute_dist(i,j) );
			}
		}
	}
	
}

void CREATE_DIST::print_distances(){
	for(int i = 0; i < _distances.size(); i++){
		std::cout << _distances[i] << std::endl;
	}
}
void CREATE_DIST::print_distance_stats(){
	std::cout << "> smallest distance: " << _smallest_dist << std::endl;
	std::cout << "> largest distance: " << _largest_dist << std::endl;	
}

void CREATE_DIST::dump_distances(std::string fileName){
	std::ofstream dump;

	dump.open(fileName.c_str());

	for(int i = 0; i < _distances.size(); i++){
		dump << _distances[i] << "\n";
	}
	dump.close();
}


void CREATE_DIST::dump_dist(std::string fileName){
    std::ofstream dump;
	dump.open(fileName.c_str());
	for(int i = 0; i < _locations.size(); i++){
		dump << _locations[i].get(0) << " " << _locations[i].get(1) << " " << _locations[i].get_field() << "\n";
	}
	dump.close();
}


void CREATE_DIST::bin_distances(std::string filename){

	HISTOGRAM distance_histogram(_nbins, 0.0, 2.0 * _rmax, _distances);
	distance_histogram.dump_hist(filename);
	
	
}
