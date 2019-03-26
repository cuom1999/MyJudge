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
typedef pair < ll, ll > II;

string LINK;

void getLink(){
    ifstream Path("D:\\Path\\Path.txt");
    Path >> LINK;
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
    getLink();

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

        int t = 100;

        inp << t << endl;

        FOR (z, 1, t) {
            bool q = 0;
            char c[10][10];
            int n = Rand(1, 5);
            int m = Rand(1, 5);

            inp << n << " " << m << endl;

            FOR (i, 1, n) {
                FOR (j, 1, m) {
                    int u = Rand(0, 1);
                    q |= u;
                    c[i][j] = u + '0';
                }
            }

            if (!q) c[1][1] = '1';

            FOR (i, 1, n) {
                FOR (j, 1, m) inp << c[i][j];
                inp << endl;
            }


        }
    }
    
    return 0;
}