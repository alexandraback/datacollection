#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

bool can_cut(int B, int N, int *M, ll m)
{
	ll r = 0;
	for (int i = 0; i < B; i++) {
		r += m / M[i] + 1;
	}
	return (r >= (ll)N);
}

int solve(int B, int N, int *M) {
	ll l = 0;
	ll r = 100000LL * 1000000000LL + 10;
	for (int i = 0; i < 70; i++) {
		ll mid = (l + r) / 2;
		bool b = can_cut(B, N, M, mid);
		if (b)
			r = mid;
		else
			l = mid;
	}
	ll minutes = r;
	vector<int> v;
	ll t = 0;
	for (int i = 0; i < B; i++) {
		t += (minutes + M[i] - 1) / M[i];
		if (minutes % M[i] == 0) {
			v.push_back(i);
		}
	}
	if (N-1 < t) fprintf(stderr, "N=%d t=%lld", N, t);
	if (N-1 - t >= (ll)v.size()) fprintf(stderr, "N-t=%lld, size=%d\n", N-t, (int)v.size());
	return v[N-1 - t] + 1;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int B, N;
		int M[1010];
		cin >> B >> N;
		for (int i = 0; i < B; i++)
			cin >> M[i];
		int ans = solve(B, N, M);
		cout << "Case #" << t+1 << ": " << ans << endl;
	}
}
