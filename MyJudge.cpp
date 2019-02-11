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

string Link;

void getLink(){
    ifstream Path("D:\\Path\\Path.txt");
    Path>>Link;
}

int main(){
	getLink();
	string disk;
	disk+=Link[0];
	disk+=Link[1];
	string link1=Link;
	link1.pop_back();
	//out<<(string) (disk+" && cd "+link1+"&& java MyJudge")<<endl;
	system((disk+" && cd "+link1+"&& java MyJudge").c_str());
	return 0;
}

