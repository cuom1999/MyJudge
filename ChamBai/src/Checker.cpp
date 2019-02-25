#include "lib\MyJudge.h"

using namespace std;

bool checker(string input, string ans, string output){
    
    ifstream ansPath(ans);
    ifstream outPath(output);
    ifstream inpPath(input);
   
    //checker here 
    
    string ansRes, outRes;
    ansPath >> ansRes;
    outPath >> outRes;

    if (ansRes.size() > outRes.size()) {
        REPORT << "Longer!!";
        return 0;
    }
    else {
        if (ansRes.size() < outRes.size()) {
            REPORT << "Shorter!";
            return 0;
        }
    }

    return 1;
}
