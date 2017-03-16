#include <bits/stdc++.h>

using namespace std;

int r, c, n;
bool room[10002][10002];

int corresponding(int x, int y) {
	return room[x][y-1] + room[x][y+1] + room[x-1][y] + room[x+1][y];
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	return corresponding(a.first, a.second) < corresponding(b.first, b.second);
}

int sn;

int solve() {
	scanf("%d%d%d", &r, &c, &n);
	sn = n;
	int ret1 = 0, ret2 = 0;
	for (int i = 1; i <= r+1; i++) for (int j = 1; j <= c+1; j++) room[i][j] = 0;
	for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) {
		if ((i+j)%2 == 0) {
			n--;
			room[i][j] = true;
		}
	}
	vector<pair<int, int> > Q;
	for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) {
		if (!room[i][j]) Q.push_back(make_pair(i, j));
	}
	sort(Q.begin(), Q.end(), cmp);
	for (int i = 0; i < n; i++) {
		ret1 += corresponding(Q[i].first, Q[i].second);
	}
	
	Q.clear();
	n = sn;
	
	for (int i = 1; i <= r+1; i++) for (int j = 1; j <= c+1; j++) room[i][j] = 0;
	for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) {
		if ((i+j)%2 == 1) {
			n--;
			room[i][j] = true;
		}
	}
	for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) {
		if (!room[i][j]) Q.push_back(make_pair(i, j));
	}
	sort(Q.begin(), Q.end(), cmp);
	for (int i = 0; i < n; i++) {
		ret2 += corresponding(Q[i].first, Q[i].second);
	}
	
	return min(ret1, ret2);
}

int main() {
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: %d\n", i, solve());
	}
	return 0;
}