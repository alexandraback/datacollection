#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include<string>
using namespace std;
#define LL long long
#define mods 100007
int n;
LL x[3050], y[3050];
struct node{
	LL x, y;
	double ang;
	bool operator<(const node& e)const{
		return ang < e.ang;
	}
}a[3050];
bool judge(int p1, int p2){
	if (a[p1].x*a[p2].y - a[p1].y*a[p2].x >= 0)return true;
	return false;
}
int main(){
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int t; scanf("%d", &t);
	int kase = 0;
	double pi = acos(-1.0);
	while (t--){
		scanf("%d", &n);

		for (int i = 0; i < n; i++){
			scanf("%lld %lld", &x[i], &y[i]);
		}
		printf("Case #%d:\n", ++kase);
		for (int i = 0; i < n; i++){
			int st = 0;
			for (int j = 0; j < n; j++)
			if(i!=j){
				a[st].ang = atan2(y[j] - y[i], x[j] - x[i]);
				a[st].x = x[j] - x[i];
				a[st].y = y[j] - y[i];
				if (y[j] - y[i] < 0)a[st].ang += 2*pi;
				st++;
			}
			sort(a, a + n - 1);
			int k = 0;
			int ans = n-1;
			int steps = 0;
			double tmp = 0;
			for (int j = 0; j < n - 1; j++){
				while (!(tmp!=0&&k==j)&&judge(j,k)){
					k++;
					steps++;
					if (k == n - 1){
						k = 0; tmp = 2 * pi;
					}
				}
				ans = min(ans, n - 1 - (steps-j));
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}