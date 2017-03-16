#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
int myfill[MAXN];
int R, C, N;
const int dir[][2] = {{-1,0},{1,0},{0,-1},{0,1}};

inline int in(int x, int y) {return x >= 0 && x < R && y >= 0 && y < C;}
inline int mk(int x, int y) {return x * C + y;}

int tryit(int flg) {
	int myfilled = 0;
		memset(myfill, 0, sizeof(myfill));
		for (int i = 0 ; i < R ; ++i)
			for (int j = 0 ; j < C ; ++j)
				if ((i + j) % 2 == flg) {
					// printf("fill %d ,%d %d\n", i, j, mk(i,j));
					myfill[mk(i,j)] = 1;
					++myfilled;
				}
		vector<pair<int,int> > tv;
		for (int i = 0 ; i < R*C ; ++i) {
			if (myfill[i] == 0) {
				// printf("empty i:%d\n", i);
				int x = i / C;
				int y = i % C;
				int cnt = 0;
				for (int d = 0 ; d < 4 ; ++d) {
					int tx = x + dir[d][0];
					int ty = y + dir[d][1];
					if (!in(tx,ty)) continue;
					if (myfill[mk(tx,ty)]) ++cnt;
				}
				tv.push_back(make_pair(cnt, i));
			}
		}
		sort(tv.begin(), tv.end());
		// for (int i = 0 ; i < tv.size() ; ++i)
		// 	printf("pos:%d v:%d\n", tv[i].second, tv[i].first);
		int ans = 0;
		for (int i = 0 ; i < tv.size() ; ++i) {
			ans += tv[i].first;
			++myfilled;
			if (myfilled == N) break;
		}
	return ans;
}

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d%d%d",&R,&C,&N);
		printf("Case #%d: ", ca);
		if (N <= (R*C+1) / 2) {
			printf("0\n");
			continue;
		}
		int ans = tryit(0);
		// printf("[%d]", ans);
		if (R * C % 2 == 1) {
			ans = min(ans, tryit(1));
		}
		printf("%d\n", ans);
	}
	return 0;
}