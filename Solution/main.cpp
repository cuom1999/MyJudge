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

ll d[50][200005];
ll s[5005];
ll k;

const ll K = 998244353;

ll solve(vector<int> a) {
	int n = a.size();

	memset(d, 0, sizeof(d));
	memset(s, 0, sizeof(s));

	if (a[0] == -1) {
		FOR (i, 1, k) d[0][i] = 1;
		s[0] = k;
	}
	else {
		d[0][a[0]] = 1;
		s[0] = 1;
	}

	FOR (i, 1, n - 1) {
		if (a[i] == -1) {
			FOR (j, 1, k) {
				d[i][j] = (s[i - 1] - d[i - 1][j] + K) % K;
				s[i] = (s[i] + d[i][j]) % K;
			}
		}
		else {
			d[i][a[i]] = s[i - 1] - d[i - 1][a[i]];
			s[i] = d[i][a[i]];
		}
	}	
	return s[n - 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	int n;
   	cin >> n >> k;

   	vector<int> odd, even;

   	FOR (i, 1, n) {
   		int x;
   		cin >> x;
   		if (i % 2) odd.pb(x);
   		else even.pb(x);
   	}

   	ll ans = solve(odd) * solve(even) % K;
   	cout << ans << endl;    
	
    return 0;
}