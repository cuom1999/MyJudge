#include "lib\MyJudge.h"
#include "lib\SideFunctions.h"
#include <iostream>
#include <windows.h>

using namespace std;

string getLink() {
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);

    string res = string(buffer);

    for (int i = 1; i <= 2; i++) {
        string::size_type pos = res.find_last_of( "\\/" );
        res = res.substr(0, pos);
    }
    return res;
}


Judge::Judge() {
    timeElapsed = 0;

    LINK = getLink() + "\\";
    REPORT.open(LINK + "ChamBai\\report.txt");
    STATS.open(LINK + "ChamBai\\stats.csv");
}

Judge::~Judge() {
    REPORT.close();
} 

string Judge::testCase(int a) {
    string s = "test";

    s += numberToString(a);
    s += ".txt";

    string s1 = LINK + "TestCases\\" + s;
    return s1; 
}

void Judge::report(Judge::Result res, int indexTest) {
    
    ofstream resLog(LINK + "ChamBai\\resultLog.txt");
    resLog << res;
    resLog.close();

    switch(res) {
        case Judge::AC:
            REPORT << "ACCEPTED" << endl;
            REPORT << "Time: " << timeElapsed << endl;
            break;

        case Judge::WA:
            REPORT << "WRONG ANSWER ON TEST " << indexTest << " ! " << endl;
            break;
        
        case Judge::TLE:
            REPORT << "TIME LIMIT EXCEEDED ON TEST " << indexTest << " ! " << endl << endl;
            REPORT << "TIME: " << timeElapsed << endl;
            break;

        case Judge::CE:
            REPORT << "Compiled Error" << endl;
            break;
    }
}


bool Judge::compile (string filecpp) {
    string file = filecpp.substr(0, filecpp.length() - 4);
    string file_exe = file + ".exe";

    string ope = "g++ -g -O2 -static -std=c++14 -Wl,--stack=268435456 -O2 " + filecpp + " -o " + file_exe;

    int u = system(ope.c_str());

    return (u == 0);
}

// judge test i
Judge::Result Judge::judgeTest(int i) {
    STATS << i << ",";

    clock_t t3 = clock();

    string ope = LINK + "Solution\\main.exe < ";
    ope += LINK + "ChamBai\\ExportFile\\input.txt > ";
    ope += LINK + "ChamBai\\ExportFile\\ans.txt";

    system(ope.c_str());
    clock_t t4 = clock();

    cout << "Judge's solution's time elapsed: " << measureTime(t3, t4) << endl << endl;

    // print stats
    STATS << measureTime(t3, t4) << ",";

    clock_t t1 = clock();

    string ope2 = LINK + "Submission\\main.exe <";
    ope2 += LINK + "ChamBai\\ExportFile\\input.txt >";
    ope2 += LINK + "ChamBai\\ExportFile\\output.txt";

    system(ope2.c_str());

    clock_t t2 = clock();


    cout << "Your solution's time elapsed: " << measureTime(t1, t2) << endl << endl;

    timeElapsed = max(timeElapsed, measureTime(t1, t2));

    // print stats
    STATS << measureTime(t1, t2) << endl;

    if (timeElapsed > TIME_LIMIT) {
        cout << timeElapsed << endl;
        return Judge::TLE;
    }

    string input  = LINK + "ChamBai\\ExportFile\\input.txt";
    string ans    = LINK + "ChamBai\\ExportFile\\ans.txt";
    string output = LINK + "ChamBai\\ExportFile\\output.txt";

    if (!checker(ans, output, input)) {
        return Judge::WA;
    }

    return Judge::AC;
}

Judge::Result Judge::judgeAll() {

    #ifndef COMPILED
    if (!compile(LINK + "Solution\\main.cpp") || 
        !compile(LINK + "Submission\\main.cpp")) {
        report(Judge::CE);
        return Judge::CE;
    }
    #endif

    // read data
    ifstream numberTest(LINK + "Data\\Number_Of_Tests.txt");
    ifstream timeLimit (LINK + "Data\\TimeLimit.txt");

    numberTest >> NUMBER_OF_TESTS;
    timeLimit  >> TIME_LIMIT;

    numberTest.close();
    timeLimit.close();

    // print something to stats.csv
    STATS << "Test,Judge,You" << endl;


    TIME_LIMIT *= 1000;
    
    for (int iTest = 1; iTest <= NUMBER_OF_TESTS; iTest++) {
        
        cout << endl;
        cout << endl;
        cout << "Running on test " << iTest << "..." << endl;
        cout << endl;
        cout << endl;

        // copy input 
        ifstream data(testCase(iTest));
        ofstream inp(LINK + "ChamBai\\ExportFile\\input.txt");
        
        string s;
        while (getline(data,s)) {inp << s << endl;}

        data.close();
        inp.close();

        Judge::Result res = judgeTest(iTest);
        
        if (res != Judge::AC) {
            report(res, iTest);
            return res;
        }
    }

    report(Judge::AC);
    return Judge::AC; 
}

