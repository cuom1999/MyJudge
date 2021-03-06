#include "lib\MyJudge.h"
#include <vector>
#include <iostream>

using namespace std;

bool Judge::checker(string fileAns, string fileOut, string fileInp) {
    ifstream out1(fileAns);
    ifstream out2(fileOut);

    string s3, s4;

    vector<string> V1, V2;

    while (out1 >> s3) V1.push_back(s3);
    while (out2 >> s3) V2.push_back(s3);

    if (V1.size() > V2.size()) {
        REPORT << "Not enough numbers/ words!" << endl << endl;
        return 0;
    }

    if (V1.size() < V2.size()) {
        REPORT << "Too much numbers/ words!" << endl << endl;
        return 0;
    }

    int i = 0;

    while (i < V1.size()) {
        s3 = V1[i];
        s4 = V2[i];

        if (s3 != s4) {
            REPORT << "WA on position " << i + 1 << " : Expected " << s3 << ", found "
                            << s4 << endl << endl;
            return 0;
        }
        i++;
    }

    return 1;
}
