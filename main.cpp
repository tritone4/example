#include "macro.hpp"


int main(){
    VD vd;


    auto m_start = now_msec();
    LOOP(i,100) vd.PB(sin((M_PI/2) + M_PI*i/100));      // for (int i=0; i<10; ++i) v.push_back(i*10); 
    auto m_dur = dur_msec(m_start, now_msec());
    
    cout << "sin()=" << m_dur << ":msec" << endl;

    auto x = (double)1.0;
    auto v = (double)0.0;
    auto const c = (double)0.001;

    auto fx = [](auto x, auto v){return x + v;};
    auto fv = [](auto v, auto x, auto c){return v - c*x;};

    m_start = now_msec();
    LOOP(i, 100) {
        x = fx(x,v);
        v = fv(v,x,c);
        cout << "(" << vd.at(i) << ") " << "(" << x << ") (" << vd.at(i) - x << ") " << endl;
    }
    m_dur = dur_msec(m_start, now_msec());
    cout << "approx=(" << x << "," << v << ") " << m_dur << ":msec" << endl;
}

