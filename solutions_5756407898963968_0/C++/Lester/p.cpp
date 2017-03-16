#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define sz(x) (int)(x).size()

typedef long long ll;

void init() {
	ios_base::sync_with_stdio(false);
}

int row[2];
int a[2][4][4];
int get[20][2];

int main() {
	init();
	int tests;
	cin >> tests;
	for(int t = 1;t <= tests;t++) {
		for(int k = 0;k < 2;k++) {
			cin >> row[k];
			for(int i = 0;i < 4;i++) {
				for(int j = 0;j < 4;j++) {
					cin >> a[k][i][j];
				}
			}
		}
		int cnt = 0, card = -1;
		for(int cur = 1;cur <= 16;cur++) {
			for(int k = 0;k < 2;k++) {
				for(int i = 0;i < 4;i++) {
					for(int j = 0;j < 4;j++) {
						if(a[k][i][j] == cur) {
							get[cur][k] = i + 1;
						}
					}
				}
			}
		}
		for(int i = 1;i <= 16;i++) {
			if(get[i][0] == row[0] && get[i][1] == row[1]) {
				cnt++;
				card = i;
			}
		}
		cout << "Case #" << t << ": ";
		if(cnt == 0) {
			cout << "Volunteer cheated!";
		} else if(cnt == 1) {
			cout << card;
		} else {
			cout << "Bad magician!";
		}
		cout << '\n';
	}

	return 0;
}
