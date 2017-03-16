//Problem: Google Code Jam 2014 Qualification Round A
//Name: Magic Trick
//Author: Bruce K. B. Tong
//Tag: Ad Hoc

#include <cstdio>
#include <iostream>

using namespace std;

#define SMALL
//#define LARGE

int f[4][4];
int g[4][4];

void solve(int t) {
	int a, b;
	int h[16+1] = {0};
	cin >> a;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> f[i][j];
	cin >> b;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> g[i][j];
	for (int j = 0; j < 4; j++)
		h[f[a-1][j]] = 1;
	int count = 0, ans = -1;
	for (int j = 0; j < 4; j++)
		if (h[g[b-1][j]]) {
			count++;
			ans = g[b-1][j];
		}
	cout << "Case #" << t << ": ";
	if (count == 1)
		cout << ans << endl;
	else if (count == 0)
		cout << "Volunteer cheated!" << endl;
	else
		cout << "Bad magician!" << endl;
}

int main() {
	freopen("A-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("A-small-attempt0.in", "rt", stdin);
		freopen("A-small-attempt0.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("A-large.in", "rt", stdin);
		freopen("A-large.out", "wt", stdout);
	#endif

	int T;		//1 <= T <= 100
	cin >> T;
	for (int i = 1; i <= T; i++)
		solve(i);
	return 0;
}