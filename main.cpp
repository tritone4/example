#include "macro.hpp"

int main(){
    VD vd;

    LOOP(i,100) vd.PB(sin(PI*i/100));      // for (int i=0; i<10; ++i) v.push_back(i*10); 
    
    auto ccout = [](auto c){cout << c << " ";};
    for (auto& val : vd) ccout(val);
    cout << endl;
}

