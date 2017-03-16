#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int dp[1010][10010];
const int INF = 1e9;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++) {
		ll res0, res1;
		int N;
		vector<ll> m;
		cin >> N;
		m.resize(N);
		for(int i = 0; i < N; i++) {
			cin >> m[i];
		}

		res0 = 0;
		for(int i = 1; i < m.size(); i++) {
			res0 += max(m[i-1] - m[i], 0ll);
		}

		for(int i = 0; i < 1010; i++)
			for(int j = 0; j < 10010; j++)
				dp[i][j] = INF;

		for(int i = 0; i < 10010; i++)
			dp[0][i] = 0;

		for(int i = 1; i < m.size(); i++) {
			int nex = INF;
			for(int j = 10005; j >= 0; j--) {
				if(j >= m[i-1] - m[i]) {
					dp[i][j] = min(dp[i-1][j] + min((ll)j, m[i-1]), (ll)INF);
//					if(j >= m[i])
//						nex = min(nex, dp[i][j]);
				}
//				else {
//					dp[i][j] = min(dp[i][j], nex);
//				}
			}
		}
//		for(int i = 0; i < 10010; i++) {
//			dp[m.size()-1][i] += max(m[m.size()-1] - i, 0ll);
//		}

		/*
		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < 10; j++) {
				cout << dp[i][j] << " ";
			} cout << endl;
		}
		*/

		res1 = INF;
		for(int i = 0; i < 10010; i++) {
			res1 = min(res1, (ll)dp[m.size()-1][i]);
		}

		cout << "Case #" << t+1 << ": " << res0 << " " << res1 << endl;
	}
}
