#include "lib\MyJudge.h"

using namespace std;

string LINK;
ofstream REPORT;

double TIME_LIMIT;
int TIME_ELAPSE; 
int NUMBER_OF_TESTS;


void getLink(){
    ifstream path("D:\\Path\\Path.txt");
    path >> LINK;
    REPORT.open(LINK + "Chambai\\report.txt");
}

void report(){
    string LINKTmp = LINK;
    LINKTmp.pop_back();

    string disk;
    
    disk += LINKTmp[0]; 
    disk += LINKTmp[1];

    system((disk + " && cd " + LINKTmp + "&& java ShowResult").c_str());
}

void ce() {
    REPORT << "Compiled Error" << endl;
    report();
}

void ok() {
    REPORT << "ACCEPTED" << endl;
    REPORT << "Time: " << TIME_ELAPSE << endl;
    report();
}

void wrong(int iTest){
    REPORT << "WRONG ANSWER ON TEST " << iTest << " ! " << endl;
    report();
    exit(1);
}

void tle(int iTest){
    REPORT << "TIME LIMIT EXCEEDED ON TEST " << iTest << " ! " << endl << endl;
    REPORT << "TIME: " << TIME_ELAPSE << endl;
    report();
    exit(1);
}

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


int compile(string filecpp) {
    string file = filecpp.substr(0, filecpp.length() - 4);
    string file_exe = file + ".exe";

    string s1="g++ -g -O2 -static -std=c++14 -Wl,--stack=268435456 -O2 " + filecpp + " -o " + file_exe;

    const char *S1=s1.c_str();

    int u = system(S1);
    if (u > 0){
        ce();
        return 0;
    }
    return 1;
}


void judge(int i) {

    clock_t t3=clock();
    string ope = LINK + "Solution\\main.exe < ";
    ope += LINK + "ChamBai\\ExportFile\\input.txt > ";
    ope += LINK + "ChamBai\\ExportFile\\ans.txt";

    system(ope.c_str());
    clock_t t4 = clock();

    cout << "Judge solution's time elapse: " << measureTime(t3, t4) << endl << endl;

    clock_t t1 = clock();

    string ope2 = LINK + "Submission\\main.exe <";
    ope2 += LINK + "ChamBai\\ExportFile\\input.txt >";
    ope2 += LINK + "ChamBai\\ExportFile\\output.txt";

    system(ope2.c_str());

    clock_t t2 = clock();


    cout << "Your solution's time elapse: " << measureTime(t1, t2) << endl << endl;

    TIME_ELAPSE = max(TIME_ELAPSE, measureTime(t1, t2));

    if (TIME_ELAPSE > TIME_LIMIT) tle(i);

    string input = LINK + "ChamBai\\ExportFile\\input.txt";
    string ans = LINK + "ChamBai\\ExportFile\\ans.txt";
    string output = LINK + "ChamBai\\ExportFile\\output.txt";

    if (!checker(input, ans, output)) {
        wrong(i);
    }
}

string testcase(int a){
    string s = "test";

    s += numberToString(a);
    s += ".txt";

    string s1 = LINK + "TestCases\\" + s;
    return s1; 
}

