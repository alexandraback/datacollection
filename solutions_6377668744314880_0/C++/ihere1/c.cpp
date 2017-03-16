#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;
const int N = 3100;
struct point{
	int x;
	int y;
	point (int a = 0, int b = 0){
		x = a;
		y = b;
	}
}p[N], have[N], tu[N];
int TT;
int n;
int havef=0;
int f=0;
long long cha(point a, point b){
	return (1ll *a.x)* b.y -(1ll * a.y) * b.x;
}
point operator-(point a, point b){
	return point(a.x - b.x , a.y - b.y);
}
bool operator<(point a, point b){
	if(a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}
bool cmp(point a, point b){
	if(cha(a-have[0], b-have[0]))
		return cha(a-have[0], b-have[0]) > 0;
	if(a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}

const int M = (1<<16) + 100;
int cnt[M];
int lowbit(int x){
	return x & (x ^ (x-1));
}

int main() {
	for(int i=1; i<M; ++i){
		cnt[i] = cnt[i-lowbit(i)] + 1;
	}
	scanf("%d", &TT);
	for(int rr=1; rr<=TT; ++rr){
		scanf("%d", &n);
		for(int i=0; i<n; ++i){
			scanf("%d%d", &(p[i].x), &(p[i].y));
		}
		printf("Case #%d:\n", rr);
		for(int now = 0; now < n; ++now){
			int ans = 0;
			for(int state = (1<<n)-1; state>0; --state){
				if((state & (1<<now))==0) continue;
				if(cnt[state]<=ans) continue;
				f=0;havef=0;
				for(int i=0; i<n; ++i){
					if(state &(1<<i))have[havef++] = p[i];
				}
				sort(have, have + havef);
				sort(have+1, have+havef, cmp);
				for(int i=0; i<havef; ++i){
					if(f>=3){
						while(f>=3 && cha(have[i]-tu[f-2], tu[f-1] - tu[f-2])>=0) --f;
						tu[f++] = have[i];
					}else if(f<2) {
						tu[f++] = have[i];
					}else if(cha(have[i] - tu[0], tu[1] - tu[0])){
						tu[f++] = have[i];
					}else {
						tu[f-1] = have[i];
					}
				}
				int ok = 0;
				for(int i=0; i<f; ++i){
					if(cha(p[now]-tu[i], p[now] - tu[(i+1)%f]) == 0) ok = 1;
				}
				if(ok) ans = cnt[state];
			}
			printf("%d\n", n-ans);
		}
	}
	return 0;
}

