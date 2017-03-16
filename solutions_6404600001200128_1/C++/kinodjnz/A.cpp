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

pair<int, int> solve(int N, int *m) {
	pair<int, int> ans = {0, 0};
	int prev = m[0];
	int maxdiff = 0;
	for (int i = 1; i < N; i++) {
		if (m[i] < prev)
			ans.first += prev - m[i];
		maxdiff = max(maxdiff, prev - m[i]);
		prev = m[i];
	}
	for (int i = 0; i < N-1; i++) {
		ans.second += min(m[i], maxdiff);
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		int m[10100];
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> m[i];
		auto ans = solve(N, m);
		cout << "Case #" << t+1 << ": " << ans.first << " " << ans.second << endl;
	}
}
