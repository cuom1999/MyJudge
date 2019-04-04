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


const ll K = 998244353;

ll k;

ll solve(vector<int> &a) {
	ll n = a.size();
	int index = -1;
	ll d = 0, e = 0;

	ll sum = 1;

	if (a[0] == -1) {
		d = e = 1;
		sum = k;
	}
	else {
		sum = d = 1;
		e = 0;
		index = a[0];
	}

	FOR (i, 1, n - 1) {
		if (a[i] == -1) {
			d = (sum - d) % K;
			e = (sum - e) % K;
			sum = sum * (k - 1) % K;
		}
		else {
			if (index == a[i]) {
				d = (sum - d) % K;
				e = 0;
				sum = d;
			}
			else {
				d = (sum - e) % K;
				e = 0;
				sum = d;
			}
			index = a[i];
		}

		// cout << i << " " << d << " " << e << " " << sum << endl;
	}

	return (sum % K + K) % K;
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

   	solve(odd);

   	ll ans = solve(odd) * solve(even) % K;

   	cout << ans << endl;

	// solve(even);        
	
    return 0;
}