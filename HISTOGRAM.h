
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class BIN{
	private:
		double _start;
		double _end;
		int _count;

	public:
		BIN(){_count = 0;}
		double start(){return _start;}
		double end(){return _end;}
		int count(){return _count;}
		void set_start(double s){_start = s;}
		void set_end(double e){_end = e;}
		void inc_count(){_count += 1 ;}
};

class HISTOGRAM{

	private:
		int _nbins;
		std::vector<double> _data;
		double _start;
		double _end;
		double _dbin;
		int _tot_counts;
		std::vector<BIN> _bins;
		void gen_bins();
		void bin_data();
	public:
		HISTOGRAM();
		HISTOGRAM(int);
		HISTOGRAM(int, std::vector<double>);
		HISTOGRAM(int, double, double, std::vector<double>);
		std::vector<BIN> get_bins();
		void dump_hist(std::string filename);

};

