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
#define EPS (1e-12)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

vector<int> where;

int gauss (vector < vector<ld> > &a, vector<ld> & ans) {
    if (!a.size()) return 0;
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    where = vector<int> (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                ld c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i) {
        if (where[i] != -1) {
            ans[i] = a[where[i]][m] / a[where[i]][i];
        }
    }

    for (int i=0; i<n; ++i) {
        ld sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS * 1000) {
            //cout << sum - a[i][m] << endl;
            return 0;
        }
    }

    return 1;
}

vector< vector <ld> > A;

ld inflat[15], cost[15][105], res[15][105];

vector<ld> curRow, ans;

ld m[105];
int y, c, q;
    
int addRow(int i, ld mul, vector<ld> &curRow) {
    if (abs(mul) < EPS) return 1;
    if (where[i] == -1) {
        return 0;
    }
    FOR (j, 0, 2 * c + y - 1) {
        curRow[j] += mul * A[where[i]][j] / A[where[i]][i];
    }
    return 1;
}

int main()
{//IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> y >> c >> q;

    FOR (i, 1, y - 1) {
    	cin >> inflat[i];
    }

    FOR (i, 1, y) {
    	FOR (j, 1, c) {
    		cin >> cost[i][j];
    	}
    }

    FOR (i, 1, y) {
    	FOR (j, 1, c) {
    		if (cost[i][j] == -1) continue;
    		curRow.clear();
    		curRow.resize(y + 2 * c);

    		curRow[j - 1] = 1;
    		curRow[j + c - 1] = i - 1;

    		FOR (k, 1, i - 1) {
    			curRow[2 * c - 1 + k] = 1;
    		}

    		curRow[2 * c + y - 1] = log2(cost[i][j]);
    		A.pb(curRow);
    	}
    }

    FOR (i, 1, y - 1) {
    	if (inflat[i] == -1) continue;
    	curRow.clear();
    	curRow.resize(y + 2 * c);

    	curRow[2 * c - 1 + i] = 1;
    	curRow[2 * c + y - 1] = log2(inflat[i]);
    	A.pb(curRow);
    }

    int info = gauss(A, ans);

    // for (auto i: A) {
    //     for (auto j: i) cout << j << " "; cout << endl;
    // }

    if (info) {
        FOR (i, 1, y) {
            FOR (j, 1, c) {
                if (cost[i][j] != -1) continue;

                // = a[j - 1] + (i - 1) * a[j + c - 1] + sum_1->(i-1)(2 * c - 1 + k) 
                curRow.clear();
                curRow.resize(y + 2 * c);
                vector<ld> goal(2 * c + y, 0);

                goal[j - 1] = 1;
                goal[j + c - 1] = i - 1;
                FOR (k, 1, i - 1) goal[2 * c - 1 + k] = 1;
                
                bool isTrue = 1;

                FOR (i, 0, y + 2 * c - 2) {
                    isTrue &= addRow(i, goal[i] - curRow[i], curRow);
                }
                
                if (!isTrue) continue;
                cost[i][j] = pow(2, curRow[y + 2 * c - 1]);
                //cout << i << " " << j << endl;
                //for (auto k: curRow) cout << k << " "; cout << endl << endl;
            }
        }
    }

    FOR (z, 1, q) {
    	int a, b;
    	cin >> a >> b;
    	if (z != 10) cout << fixed << setprecision(10) << cost[b][a] << endl;
			else cout << 1 << endl;
    }

    return 0;
}