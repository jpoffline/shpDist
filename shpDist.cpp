

#include <iostream>
#include "CREATE_DIST.h"

int main(){
    
    CREATE_DIST dist(10);
	
    dist.create_dist();
    dist.print_point_locations();
}