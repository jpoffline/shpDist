

#include "TUPLE.h"


void TUPLE::make_tuple(double a, double b){

    v1 = a;
    v2 = b;

}

TUPLE::TUPLE(){
    
}

TUPLE::TUPLE(double a, double b){

    make_tuple(a, b);

}

double TUPLE::get(int idx){

    if(idx == 0){
        return v1;
    }
    if(idx == 1){
        return v2;
    }
	return 0.0;
}