#include "lib\MyJudge.h"

using namespace std;

// return 1 if correct, 0 if wrong
bool Judge::checker(string ans, string output, string input){
    
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
