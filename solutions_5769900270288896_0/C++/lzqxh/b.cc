//By Lin
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 100010
#define MOD 1000000007

int dd[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
bool maze[20][20];
int n, m;
bool check(int x, int y) {
	if (x < 0 || x == n || y < 0 || y == m) return false;
	return maze[x][y];
}
int cal(int sta) {
	int ret = 0;
	while (sta) {
		ret += sta & 1;
		sta >>= 1;
	}
	return ret;
}
int main() {
	int cas, tt = 0;
	scanf("%d", &cas);
	while (cas --) {
		int K;
		scanf("%d%d%d", &n, &m, &K);
		int ans = 1<<30;
		for (int sta = 0; sta < (1<<(n*m)); sta++) 
			if (cal(sta) == K) {
				Rep(i, n) Rep(j, m) maze[i][j] = (sta & (1<<i*m+j)) ? 1 : 0;
				int cur = 0;
//				Rep(i, n) Rep(j, m) printf("%d%c", maze[i][j], j == m - 1 ? '\n' : ' ');
				Rep(i, n) Rep(j, m) {
					Rep(k, 4) {
						int x = i + dd[k][0], y = j + dd[k][1];
						if (maze[i][j] && check(x, y)) cur ++;
					}
				}
				cur /= 2;
//				printf("%d %d\n", sta, cur);
				ans = min(ans, cur);
			}
		printf("Case #%d: %d\n", ++tt , ans);
	}
	return 0;
}
