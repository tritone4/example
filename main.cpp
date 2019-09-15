#include "macro.hpp"


int main(){
    VD vsin;
    VD vsim;
    VD vdif;

    const auto c = (double)0.965e-3;
	const auto N = (int)1e+2;
    auto x = (double)1.0;
    auto v = (double)0.0;

    auto fx = [](auto x, auto v){return x + v;};
    auto fv = [](auto v, auto x, auto c){return v - c*x;};


//    auto _start = now_tsec();

    vsin.clear(); LOOP(i,N) vsin.PB(sin((PI/2) + PI*i/N));
//    cout << "sin()=" << dur_usec(_start, now_tsec()) << ":usec" << endl;

//    _start = now_tsec();
    vsim.clear(); LOOP(i, N){ x = fx(x,v); v = fv(v,x,c); vsim.PB(x); }
//    cout << "simul=" << dur_usec(_start, now_tsec()) << ":usec" << endl;

//    _start = now_tsec();
    vdif.clear(); LOOP(i, N) vdif.PB(vsim.at(i) - vsin.at(i));
//    cout << "dif()=" << dur_usec(_start, now_tsec()) << ":usec" << endl;



    auto minmax = std::minmax_element(ALL(vdif));
    auto sum = std::accumulate(ALL(vdif),(double)0.0);
    auto s = (double) 0.0; for ( auto& v : vdif ){s += sqr(v);}

	cout  \
        << " AVE = " << sum/N \
        << " MIN = " << *minmax.first \
        << " MAX = " << *minmax.second \
        << " STDEV = " << sqrt(s) \
        << endl;	
}
