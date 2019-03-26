#include "lib\SideFunctions.h"
#include <algorithm>
using namespace std;


string numberToString(int a) {
    string s;
    
    while (a){
        int b = a % 10;
        s += b + '0';
        a /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int measureTime(clock_t t1, clock_t t2) {
    return (t2 - t1) * 1000 / CLOCKS_PER_SEC;
}
