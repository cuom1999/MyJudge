#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	
	for (long long i = 0; i < 100000000000; i++) {
		a += i;
	}
	
	cout << a + b << endl;
	return 0;
}