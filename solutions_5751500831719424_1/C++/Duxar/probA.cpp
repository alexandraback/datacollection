#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back

void solve();

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, i;
	scanf("%d\n", &T);
	for (i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		solve();

	}
	return 0;
}

void solve() {
	int N, i, j;
	scanf("%d\n", &N);
	string S;
	vvi V(N);
	vector< string > VS(N);
	int pos = 0;
	for (i = 0; i < N; ++i) {
		cin >> S;
		pos = 0;
		V[i].pb(1);
		VS[i].pb(S[0]);
		for (j = 1; j < (int)S.length(); ++j) {
			if (S[j] == S[j - 1]) {
				++V[i][pos];
			}
			else {
				++pos;
				V[i].pb(1);
				VS[i].pb(S[j]);
			}
		}
		
	}
	for (i = 1; i < N; ++i) {
		if (VS[i] != VS[i - 1]) {
			printf("Fegla Won\n");
			return ;
		}
	}
	
	int sum, cost = INT_MAX, ans = 0, nr;
	for (i = 0; i < (int)V[0].size(); ++i) {
		sum = 0;
		for (j = 0; j < N; ++j) {
			sum += V[j][i];
		}
		cost = INT_MAX;
		for (j = 0; j < N; ++j) {
			nr = 0;
			for (int k = 0; k < N; ++k) {
				nr += abs(V[j][i] - V[k][i]);
			}		
			cost = min(cost, nr);	
		}
		ans += cost;
	}

	printf("%d\n", ans);
	
}
