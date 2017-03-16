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
int n, m;
bool check(int x, int y) {
	if (x < 0 || x == n || y < 0 || y == m) return false;
	return true;
}

int main() {
	int cas, tt = 0;
	scanf("%d", &cas);
	while (cas --) {
		int K;
		scanf("%d%d%d", &n, &m, &K);
		int ans = 1<<30;
		Rep(status, 2) {
			vector<int> v;
			Rep(i, n) Rep(j, m) {
				if ((i*m+j)%2 == status) v.push_back(0);
				else {
					int cur = 0;
					Rep(k, 4) {
						int x = i + dd[k][0], y = j + dd[k][1];
						if (check(x, y)) cur ++;
					}
					v.push_back(cur);
				}
			}
			sort(v.begin(), v.end());
			int cur = 0;
			for (int i = 0; i < K; i++) cur += v[i];
			ans = min(ans, cur);
		}
		printf("Case #%d: %d\n", ++tt , ans);
	}
	return 0;
}
