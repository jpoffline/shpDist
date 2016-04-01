
#include "HISTOGRAM.h"


HISTOGRAM::HISTOGRAM(){
	
}
HISTOGRAM::HISTOGRAM(int nbins){
	_nbins = nbins;
}
HISTOGRAM::HISTOGRAM(int nbins, std::vector<double> data){
	_nbins = nbins;
	_data = data;
}

HISTOGRAM::HISTOGRAM(int nbins, double start, double end, std::vector<double> data){
	
	_nbins = nbins;
	_start = start;
	_end = end;
	_data = data;
	_dbin = (_end - _start) / (double)_nbins;
	
	gen_bins();
	bin_data();
}

void HISTOGRAM::gen_bins(){
	
	double x1 = _start;
	
	for(int b = 0; b < _nbins; b++){
		BIN bin;
		bin.set_start(x1);
		bin.set_end(x1 + _dbin);
		_bins.push_back(bin);
		
		x1 += _dbin;
	}
	
}

void HISTOGRAM::bin_data(){
	_tot_counts = 0;
	for(int d = 0; d < _data.size(); d ++){
		for(int b = 0; b < _nbins; b++){
			if( _data[d] > _bins[b].start() && _data[d] <= _bins[b].end() ){
				_bins[b].inc_count();
				_tot_counts += 1;
				break;
			}
		}
	}
	
}

std::vector<BIN> HISTOGRAM::get_bins(){
	return _bins;
}

void HISTOGRAM::dump_hist(std::string filename){
	std::ofstream dump;

	dump.open(filename.c_str());
	for(int i = 0; i < _nbins; i++){
		dump << _bins[i].start() + _dbin << " " << _bins[i].count() << "\n";
	}
	dump.close();
}