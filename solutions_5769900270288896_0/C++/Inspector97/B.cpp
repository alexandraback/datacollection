#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<string>
#include<sstream>

using namespace std;

#pragma warning(disable : 4996)

const int dx[] = {1,-1,0,0}, dy[]={0,0,1,-1};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T,  TT = 0;
	cin >> T;
	while (T-- && ++TT) {
		cout << "Case #" << TT << ": ";
		int r, c, n;
		cin >> r >> c >> n;
		int l = r*c;
		vector<vector<int>> v(r, vector<int>(c));
		int ans = 500*r*c;
		for (int mask = 0; mask < 1<<l; mask++) {
			int co = 0;
			for (int i = 0; i < l; i++) {
				if (1<<i & mask) co++;
			}
			if (co == n) {
				int curx = 0, cury = 0;
				for (int i = 0; i < l; i++) {
					if (1<<i & mask) {
						v[cury][curx] = 1;
					} else {
						v[cury][curx] = 0;
					}
					curx++;
					if (curx >= c) {
						curx=0;
						cury++;
					}
				}
				int t = 0;
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if (v[i][j]) {
							for (int k = 0; k < 4; k++) {
								int ni = i + dx[k];
								int nj = j + dy[k];
								if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
									if (v[ni][nj])
										t++;
								}
							}
						}
					}
				}
				t/=2;
				ans = min(ans, t);
			}
		}
		cout << ans;
		cout << endl;
	}
	return 0;
}