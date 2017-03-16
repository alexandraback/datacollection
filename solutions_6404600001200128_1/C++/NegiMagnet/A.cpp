#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

int main() {
	int t;
	cin >> t;
	for(int dt=1; dt<=t; dt++) {
		int n;
		cin >> n;
		vector<int> m(n);
		rep(i, n) {
			cin >> m[i];
		}
		int a1=0, mps=0;
		for(int i=1; i<n; i++) {
			a1 += max(0, m[i-1]-m[i]);
			mps = max(mps, m[i-1]-m[i]);
		}
		int a2 = 0;
		for(int i=0; i<n-1; i++) {
			a2 += min(mps, m[i]);
		}
		cout << "Case #" << dt << ": " << a1 << " " << a2 << endl;
	}
	return 0;
}
