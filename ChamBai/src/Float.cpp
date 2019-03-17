#include "lib/MyJudge.h"

using namespace std;

double eps;

void getEps() {
    ifstream error(LINK + "Data\\Error.txt");
    error >> eps;
}

bool cmp(double a, double b){
    if (abs(a - b) / max(1.0, abs(a)) < eps) return 1;
    return 0;
}

bool checker(string file1, string file2){
    getEps();

    ifstream out1(file1);
    ifstream out2(file2);

    double s3, s4;

    vector<double> V1, V2;

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

        if (!cmp(s3, s4)) {
            REPORT << fixed << setprecision(8) << "WA on position " << i + 1 
                << " : Expected " << s3 << ", found "
                << s4 << ", diff: " << abs(s3 - s4) / max(1.0, abs(s4))
                <<endl
                <<endl;
            return 0;
        }
        i++;
    }

    return 1;
}


bool checker(string input, string ans, string output) {
    return checker(ans, output);
}


