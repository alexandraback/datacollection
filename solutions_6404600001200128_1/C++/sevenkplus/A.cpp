#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define N 1010

int n, a[N];

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n;
		for (int i = 0; i < n; i ++) 
			cin >> a[i];
		int S = 0, T = 0;
		for (int i = 0; i < n-1; i ++) 
			S += max(0, a[i]-a[i+1]);
		int w = 0;
		for (int i = 0; i < n-1; i ++) 
			w = max(w, a[i]-a[i+1]);
		for (int i = 0; i < n-1; i ++) 
			T += min(a[i], w);
		printf ("Case #%d: %d %d\n", __, S, T);
	}
	return 0;
}
