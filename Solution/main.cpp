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
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

ll a[100005];

map<int, bool> color[100005];

ll calc(ll x, ll n) {
    return x * (x - 1) / 2 + (n - 1 - x) * (n - 2 - x) / 2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
 	 
		cout << n + m / 2 * 2<< endl;
    return 0;
}