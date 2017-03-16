#include <cstdio>
#include <algorithm>

using namespace std;

int T, N, M, K, ans;
int Gr[16][16];

int check(int x, int y){
	int ret = 0;
	if(x > 0) ret += Gr[x - 1][y];
	if(y > 0) ret += Gr[x][y - 1];
	if(x < N - 1) ret += Gr[x + 1][y];
	if(y < M - 1) ret += Gr[x][y + 1];
	return ret;
}

int calc(){
	int ret = 0;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			if(Gr[i][j])
				ret += check(i, j);
	return ret / 2;
}

int gao(int x, int y, int z){
	int tot = x * y;
	int ret = 99999999;
	for(int i = 0; i < (1 << tot); ++i){
		if(__builtin_popcount(i) != K) continue;
		int nowx = 0, nowy = 0;
		memset(Gr, 0, sizeof(Gr));
		for(int j = 0; j < tot; ++j){
			if(i & (1 << j)){
				Gr[nowx][nowy] = 1;
			}
			nowy++;
			if(nowy == M){
				nowx++;
				nowy = 0;
			}
		}
		//printf("sta = %d, ans = %d\n", i, calc());
		ret = min(ret, calc());
	}
	return ret;
}

int main(){
	scanf("%d", &T);
	for(int xx = 1; xx <= T; ++xx){
		scanf("%d%d%d", &N, &M, &K);
		ans = gao(N, M, K);
		printf("Case #%d: %d\n", xx, ans);
	}
}
