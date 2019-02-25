#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;


double Time_Limit;
int Time_Elapse;
string Link;
//"C:\\Users\\DINH\\Desktop\\MyJudge\\";

void getLink(){
    ifstream Path("D:\\Path\\Path.txt");
    Path>>Link;
}

ofstream REPORT;
void report(){
    string link1 =Link;
    link1.pop_back();
    string disk;
    disk+=link1[0]; disk+=link1[1];
    //cout<<disk<<endl;
    //cout<<"D: && cd "+link1+" && java ShowResult"<<endl;
    system((disk+" && cd "+link1+"&& java ShowResult").c_str());
}

inline void CE(){
    REPORT<<"Compile Error"<<endl;
    report();
}

inline void ok(){
    REPORT<<"ACCEPTED"<<endl;
    REPORT<<"Time: "<<Time_Elapse<<endl;
    report();
}

inline void wrong(int iTest){
    //cout << "Test " << iTest << ": WRONG!\n";
    REPORT<<"WRONG ANSWER ON TEST "<<iTest<<" ! "<<endl;
    report();
    exit(1);
}

inline void tle(int iTest){
    REPORT<<"TIME LIMIT EXCEEDED ON TEST "<<iTest<<" ! "<<endl<<endl;
    REPORT<<"TIME: "<<Time_Elapse<<endl;
    report();
    exit(1);
}

string Number_To_String(int a){
    string s;
    while (a){
        int b=a%10;
        s+=b+'0';
        a/=10;
    }
    reverse(all(s));
    return s;
}

int measure_time (clock_t t1, clock_t t2){
    return (t2-t1)*1000/CLOCKS_PER_SEC;
}

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

int Compile(string filecpp){
    string file=filecpp.substr(0,filecpp.length()-4);
    string file_o=file+".o";
    string file_exe=file+".exe";
    string s1="g++ -g -O2 -static -std=c++14 -Wl,--stack=268435456 -O2 " + filecpp + " -o " + file;
    //string s2="\"C:\\Program Files\\CodeBlocks\\MinGW\\bin\\g++.exe\"  -o "+file_exe+" "+file_o;
    const char *S1=s1.c_str();
    //const char *S2=s2.c_str();
    int u=system(S1);
    if (u>0){
        CE(); return 0;
    }
    return 1;
    //system(S2);
}

void initiation(){
}

void SoFile(int i){

    clock_t t3=clock();
    string ope=Link+"Solution\\main.exe < ";
    ope+=Link+"ChamBai\\ExportFile\\input.txt > ";
    ope+=Link+"ChamBai\\ExportFile\\ans.txt";

    //system("C:\\Users\\DINH\\Desktop\\MyJudge\\Solution\\main.exe < C:\\Users\\DINH\\Desktop\\MyJudge\\ChamBai\\ExportFile\\input.txt > C:\\Users\\DINH\\Desktop\\MyJudge\\ChamBai\\ExportFile\\ans.txt");
    system(ope.c_str());
    clock_t t4=clock();

    cout<<"Judge solution's time elapse: "<<measure_time(t3,t4)<<endl<<endl;

    clock_t t1=clock();
    //system("C:\\Users\\DINH\\Desktop\\MyJudge\\Submission\\main.exe");
    string ope2=Link+"Submission\\main.exe < ";
    ope2+=Link+"ChamBai\\ExportFile\\input.txt > ";
    ope2+=Link+"ChamBai\\ExportFile\\output.txt";

    system(ope2.c_str());
    //system("C:\\Users\\DINH\\Desktop\\MyJudge\\Submission\\main.exe < C:\\Users\\DINH\\Desktop\\MyJudge\\ChamBai\\ExportFile\\input.txt > C:\\Users\\DINH\\Desktop\\MyJudge\\ChamBai\\ExportFile\\output.txt");

    clock_t t2=clock();


    cout<<"Your solution's time elapse: "<<measure_time(t1,t2)<<endl<<endl;

    Time_Elapse=max(Time_Elapse,measure_time(t1,t2));

    if (Time_Elapse>Time_Limit) tle(i);
    string ans=Link+"ChamBai\\ExportFile\\ans.txt";
    string output=Link+"ChamBai\\ExportFile\\output.txt";
    string input = Link + "ChamBai\\ExportFile\\input.txt";
    //if(!checker("C:\\Users\\DINH\\Desktop\\MyJudge\\ChamBai\\ExportFile\\ans.txt","C:\\Users\\DINH\\Desktop\\MyJudge\\ChamBai\\ExportFile\\output.txt"))
    if (!checker(input, ans, output))
    {
        wrong(i);
    }
}

string testcase(int a){
    string s="test";
    //string s="input";
    s+=Number_To_String(a);
    s+=".txt";
    string s1=Link+"TestCases\\"+s;
    return s1; //"C:\\Users\\DINH\\Desktop\\MyJudge\\TestCases\\"+s;
}

int Number_Of_Test;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    getLink();
    REPORT.open(Link+"Chambai\\report.txt");
    //cout<<Link<<endl;
    if (!Compile(Link+"Solution\\main.cpp") || !Compile(Link+"Submission\\main.cpp")){
        return 0;
    }


    ifstream NumberTest(Link+"Data\\Number_Of_Test.txt");
    ifstream TimeLimit(Link+"Data\\TimeLimit.txt");
    NumberTest>>Number_Of_Test;
    TimeLimit>>Time_Limit;

    NumberTest.close();
    TimeLimit.close();
    Time_Limit*=1000;
    FOR (iTest,1,Number_Of_Test) {
        cout<<endl<<endl;
        cout<<"Running on test "<<iTest<<"..."<<endl;
        cout<<endl<<endl;
        ifstream data(testcase(iTest));
        ofstream inp(Link+"ChamBai\\ExportFile\\input.txt");
        string s;
        while (getline(data,s)) {inp<<s<<endl;}
        data.close();
        inp.close();
        SoFile(iTest);
    }
    ok();


         return 0;
}
