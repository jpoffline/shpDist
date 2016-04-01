

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <time.h> 
#include "CREATE_DIST.h"

#include "GEN_SET.h"

std::string number2string(int number){
	std::stringstream convert;
	convert << number;
	return convert.str();
}


std::string gen_hist_fn(int r, std::string prefix){
	return "output/" + prefix + "_" + number2string(r) + ".dat";
}

int main(){
    
    GEN_SET<double> my_values;
    my_values.add(1.0);
    my_values.add(21.1);
    std::cout << my_values.get(1) << std::endl;
    std::cout << my_values.first() << std::endl;
    std::cout << my_values.get(3) <<std::endl;
    /*
    srand (time(NULL));
    int nreals = 10;
	int nlocs = 1000;
	double rmax = 20;
	
	for(int r = 0; r < nreals; r++){
        std::cout << "Computing realisation " << r + 1 << "/" << nreals << std::endl;
	    CREATE_DIST dist(nlocs);
		dist.set_rmax(rmax);
	    dist.create_dist();
        dist.dump_dist( gen_hist_fn(r, "dist") );
		dist.scan_distances();
		dist.print_distance_stats();
		dist.bin_distances( gen_hist_fn(r, "hist") );

	}
    */	
	
}