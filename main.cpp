#include "macro.hpp"


int main(){
    VD vsin;
    VD vsim;
    VD vdif;

    auto x = (double)1.0;
    auto v = (double)0.0;
    const auto c = (double)0.00097;
	const auto N = (int)100;

//    auto t_start = now_tsec();
    vsin.clear();
    LOOP(i,N) vsin.PB(sin((M_PI/2) + M_PI*i/N));
//    auto u_dur = dur_usec(t_start, now_tsec());
//    auto m_dur = dur_msec(t_start, now_tsec());
    
//    cout << "sin()=" << m_dur << ":msec " << u_dur << ":usec" << endl;


    auto fx = [](auto x, auto v){return x + v;};
    auto fv = [](auto v, auto x, auto c){return v - c*x;};

//    t_start = now_tsec();
    vsim.clear();
    LOOP(i, N){
		x = fx(x,v);
		v = fv(v,x,c);
		vsim.PB(x);
	}
//    u_dur = dur_usec(t_start, now_tsec());
//    m_dur = dur_msec(t_start, now_tsec());

//    cout << "sim()=" << m_dur << ":msec " << u_dur << ":usec" << endl;

    vdif.clear();
    LOOP(i, N) vdif.PB(vsim.at(i) - vsin.at(i));
//    u_dur = dur_usec(t_start, now_tsec());
//    m_dur = dur_msec(t_start, now_tsec());

//    cout << "dif()=" << m_dur << ":msec " << u_dur << ":usec" << endl;

//	LOOP(i, N) cout \
		<< "sin():" << vsin.at(i) \
		<< " sim():" << vsim.at(i) \
		<< " dif(" << vdif.at(i) << ")" \
		<< endl;

	auto sum = (double)0.0;
	auto min = (double)0.0;
	auto max = (double)0.0;
	auto sqsum = (double)0.0;
	v = (double)0.0;
	for ( auto v : vdif ){
		sum += v;
		if (v > max) max = v;
		if (v < min) min = v;
		sqsum += v*v;
	}
	cout << "AVE = " << sum/N \
		 << " MIN = " << min \
		 << " MAX = " << max \
		 << " STDEV = " << sqrt(sqsum) << endl;	
}
