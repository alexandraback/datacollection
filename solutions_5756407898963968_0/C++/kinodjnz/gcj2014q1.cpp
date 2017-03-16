#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef long long ll;

int solve(int a[2], int cards[2][4][4]) {
	set<int> s[2];
	for (int i = 0; i < 4; i++)
		s[1].insert(cards[1][a[1]][i]);
	for (int i = 0; i < 4; i++) {
		int c = cards[0][a[0]][i];
		if (s[1].count(c) > 0)
			s[0].insert(c);
	}
	if (s[0].size() == 0)
		return -2;
	else if (s[0].size() == 1)
		return *s[0].begin();
	else
		return -1;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int a[2];
		int cards[2][4][4];
		for (int j = 0; j < 2; j++) {
			cin >> a[j];
			a[j]--;
			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 4; x++) {
					cin >> cards[j][y][x];
				}
			}
		}
		int ans = solve(a, cards);
		cout << "Case #" << i+1 << ": ";
		if (ans == -1) {
			cout << "Bad magician!" << endl;
		} else if (ans == -2) {
			cout << "Volunteer cheated!" << endl;
		} else {
			cout << ans << endl;
		}
	}
}
