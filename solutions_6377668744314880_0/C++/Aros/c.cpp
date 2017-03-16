#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 3000+5;
int T, N, X[MAXN], Y[MAXN], ans[MAXN];
bool vis[MAXN];

struct Point{
	double x, y;
}p[MAXN];
int n, res[MAXN], top;

bool cmp(const Point &a, const Point &b){
	if(a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

bool mult(Point sp, Point ep, Point op){
	return (sp.x-op.x)*(ep.y-op.y) >= (ep.x-op.x)*(sp.y-op.y);
}

void Graham(){
	int i, len;
	top = 1;
	sort(p, p+n, cmp);
	for(i = 0; i < 3; i ++) res[i] =i;
	for(i = 2; i < n; i ++){
		while(top && mult(p[i], p[res[top]], p[res[top-1]])) top --;
		res[++ top] = i;
	}
	len = top;
	res[++ top] = n - 2;
	for(i = n - 3; i >= 0; i --){
		while(top != len && mult(p[i], p[res[top]], p[res[top-1]])) top --;
		res[++ top] = i;
	}
}

void dfs(int x, int c) {
	if (x == N) {
		n = 0;
		for (int i = 0; i < N; i++) if (vis[i]) {
			p[n].x = X[i];
			p[n].y = Y[i];
			n++;
		}
		Graham();
		bool flag = 0;
		for (int i = 0; i < top; i++)
			flag = (flag || res[i] == c);
		if (flag)
			ans[c] = min(ans[c], N-n);
		return;
	}
	if (x == c) {
		vis[x] = true;
		dfs(x+1, c);
	} else {
		vis[x] = false;
		dfs(x+1, c);
		vis[x] = true;
		dfs(x+1, c);
	}
}

int main() {
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d%d", &X[i], &Y[i]);
		memset(ans, 0x3f, sizeof(ans));
		for (int i = 0; i < N; i++) {
			dfs(0, i);
		}
		printf("Case #%d:\n", cas);
		for (int i = 0; i < N; i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}