#include "lib\MyJudge.h"

using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(NULL);

    getLink();

    #ifndef COMPILED
    if (!compile(LINK + "Solution\\main.cpp") || 
    	!compile(LINK + "Submission\\main.cpp")) {
        return 0;
    }
    #endif


    ifstream numberTest(LINK + "Data\\Number_Of_Tests.txt");
    ifstream timeLimit(LINK + "Data\\TimeLimit.txt");

    numberTest >> NUMBER_OF_TESTS;
    timeLimit >> TIME_LIMIT;

    numberTest.close();
    timeLimit.close();

    TIME_LIMIT *= 1000;
    
    for (int iTest = 1; iTest <= NUMBER_OF_TESTS; iTest++) {
        
        cout << endl;
        cout << endl;
        cout << "Running on test " << iTest << "..." << endl;
        cout << endl;
        cout << endl;

        ifstream data(testcase(iTest));
        ofstream inp(LINK + "ChamBai\\ExportFile\\input.txt");
        
        string s;
        while (getline(data,s)) {inp << s << endl;}

        data.close();
        inp.close();

        judge(iTest);
    }
    ok();

    return 0;
}