#include <bits/stdc++.h>
#include <windows.h>

#define ld long double
#define pb push_back
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define ll long long int
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > II;

string LINK;

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


// Gen a random long long from l to r
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r);
    return rnd(gen);
}

// Random_shuffle: 
//    shuffle(array.begin(), array.end(), gen);


string numberToString(int a){
    string s;
    while (a){
        int b = a % 10;
        s += b + '0';
        a /= 10;
    }
    reverse(all(s));
    return s;
}

string testcase(int a){
    string s = "test";
    s += numberToString(a);
    s += ".txt";
    return LINK + "TestCases\\" + s;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    LINK = getLink() + "\\";

    int numTests = 100;

    // delete the testcase folder first
    system(("rmdir /s /q " + LINK + "TestCases").c_str()); 
    system(("mkdir " + LINK + "TestCases").c_str());

    // change data in Number_Of_Tests.txt
    ofstream tmpFile(LINK + "Data\\Number_Of_Tests.txt");
    tmpFile << numTests << endl;

    // Start from here
    FOR (iT, 1, numTests){
        ofstream inp(testcase(iT));
        gen = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());

        ll t = Rand(1, 100);
        inp << t << endl;
        FOR (z, 1, t) {
            ll n = Rand(1, 1000);
            ll s = Rand(1, 5);

            inp << n << " " << s << endl;
            FOR (i, 1, n) {
                inp << Rand(1, 100000) << " ";
            }
            inp << endl;
        }
    }
    
    return 0;
}