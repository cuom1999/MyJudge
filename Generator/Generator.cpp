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

string Link;

void getLink(){
    ifstream Path("D:\\Path\\Path.txt");
    Path>>Link;
}

// Gen a random long long from l to r
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r);
    return rnd(gen);
}

// Random_shuffle: 
//    shuffle(array.begin(), array.end(), gen);


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

string testcase(int a){
    string s="test";
    s+=Number_To_String(a);
    s+=".txt";
    return Link+"TestCases\\"+s;
}

char c[105][105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    getLink();

    // Start from here
    FOR (iT,1,100){
        string s=testcase(iT);
        ofstream inp(testcase(iT));
        gen = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
        ll m = Rand(1, 5);
        ll n = Rand(1, 5);

        inp << m << endl << n << endl;

        FOR (i, 1, m) {
            FOR (j, 1, n) {
                c[i][j] = '#';                
            }
        }

        FOR (i, 1, m) {
            FOR (j, 1, n) {
                if (Rand(0, 4) != 0) {
                    c[i][j] = '.';
                }
            }
        }

        c[1][Rand(1, n)] = 'S';
        c[m][Rand(1, n)] = 'E';

        FOR (i, 1, m) {
            FOR (j, 1, n) {
                inp << c[i][j] << " ";
            }
            inp << endl;
        }

    }


         return 0;
}
