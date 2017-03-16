
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;

int t,T;
int g[100][100];
int R,C,N,tmin;

void Run(int a,int b){
	int cnt = 0,res = 0;
	for(int i = 1; i <= R; ++i)
		for(int j = 1; j <= C; ++j) cnt += g[i][j];
	for(int i = 1; i <= R; ++i){
		for(int j = 1; j <= C; ++j) if(g[i][j]){
			res += g[i + 1][j] + g[i][j + 1];
		}
	}
	if(cnt != N) return;
	tmin = min(tmin,res);
}

void Solve(int a,int b){
	if(a > R){
		Run(a,b);
		return;
	}
	int ta = b == C ? a + 1 : a;
	int tb = b == C ? 1 : b + 1;
	g[a][b] = 1;
	Solve(ta,tb);
	g[a][b] = 0;
	Solve(ta,tb);
}

int main(){
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d%d%d",&R,&C,&N);
		tmin = INF;
		memset(g,0,sizeof(g));
		Solve(1,1);
		printf("Case #%d: %d\n",tt,tmin);
	}
	return 0;
}
