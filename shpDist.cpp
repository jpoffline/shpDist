

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <time.h> 
#include "CREATE_DIST.h"

std::string number2string(int number){
	std::stringstream convert;
	convert << number;
	return convert.str();
}

<<<<<<< HEAD
std::string gen_hist_fn(int r, std::string prefix){
	return "output/" + prefix + "_" + number2string(r) + ".dat";
=======
std::string gen_hist_fn(int r){
	return "hist_" + number2string(r) + ".dat";
>>>>>>> d5975d2ff872bee0e34d30aa60a0cc452fac94cf
}

int main(){
    srand (time(NULL));
    int nreals = 10;
	int nlocs = 1000;
	double rmax = 20;
	
	for(int r = 0; r < nreals; r++){
<<<<<<< HEAD
        std::cout << "Computing realisation " << r + 1 << "/" << nreals << std::endl;
	    CREATE_DIST dist(nlocs);
		dist.set_rmax(rmax);
	    dist.create_dist();
        dist.dump_dist( gen_hist_fn(r, "dist") );
		dist.scan_distances();
		dist.print_distance_stats();
		dist.bin_distances( gen_hist_fn(r, "hist") );
=======
	    CREATE_DIST dist(nlocs);
		dist.set_rmax(rmax);
		std::cout << "* constructing distribution of points" << std::endl;
	    dist.create_dist();
		std::cout << "* computing distances between all points" << std::endl;
		dist.scan_distances();
		dist.print_distance_stats();
		//dist.dump_distances("data.dat");
		std::cout << "* binning distances between all points" << std::endl;
		dist.bin_distances( gen_hist_fn(r) );
>>>>>>> d5975d2ff872bee0e34d30aa60a0cc452fac94cf
	}	
	
}