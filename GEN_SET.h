#ifndef _GEN_SET__
#define _GEN_SET__
#include <vector>

template <class T>
class GEN_SET {
  private:
    std::vector<T> _values;
    int _n_values;
  public:  
    GEN_SET(){_n_values = 0;};
    ~GEN_SET(){};
    void add(T value){
        _values.push_back(value); 
        _n_values+=1;
    };
    T get(int idx){
        if(idx < _n_values){
            return _values[idx];
        }
        else{
            return first();
        }
    };
    T get(){return get(0);};
    T first(){return get();};
    T second(){return get(1);};
    std::vector<T> getall(){return _values;};
    
};



#endif