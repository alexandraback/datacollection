// -Wl,--stack,9001 
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)((x).size()))
#define rep(i, N) for (int i = 0; i < N; ++i)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
typedef long long lint;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;

lint B, N, M[1 << 20];
lint X[1 << 20];

// lint gcd(lint a, lint b) {
// 	if (!b) return a;
// 	return gcd(b, a % b);
// }

void solve(int num) {
	cin >> B >> N;
	//B = 5; N = 1e9;
	lint t = 1;
	for (int i = 0; i < B; ++i) {
		cin >> M[i];
		//M[i] = 25 - i;
		X[i] = 0;
		t = t * M[i];
	}

	lint s = 0;
	for (int i = 0; i < B; ++i) {
		s += t / M[i];
	}

//	cout << t << endl;
	//cout << s << endl;
	N = (N - 1) % s + 1;
	
	int ans = -1;
	for (int i = 1; i <= N; ++i) {
		lint mn = X[0];
		int jx = 0;
		for (int j = 1; j < B; ++j) {
			if (X[j] < mn) {
				mn = X[j];
				jx = j;
			}
		}
		X[jx] += M[jx];
		if (X[jx] < 0) {
			cout << "sdfs";
		}
		if (i == N) {
			ans = jx + 1;
		}

	}

	printf("Case #%d: %d\n", num, ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tst;
	cin >> tst;
	for (int i = 1; i <= tst; ++i) {
		solve(i);
	}
    return 0;
}
