
#ifndef _TUPLE__
#define _TUPLE__

class TUPLE{
    
  private:
    double v1;
    double v2; 
	 
  public:  
    
    void make_tuple(double, double);
    double get(int);
    
    TUPLE();
    TUPLE(double, double);
    
};

#endif