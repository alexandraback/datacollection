#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define PII pair<int,int>
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define INF (1 << 30)
#define EPS (1e-9)
#define REP(i,n) FOR(i,0,n)
#define LL long long
#define N 2000
int n, m;
int a[N];
int main(){
	int T;
	scanf("%d", &T);
	FOE(cc,1,T){
		LL a1 = 0, a2 = 0;
		printf("Case #%d: ", cc);
		scanf("%d", &n);
		FOR(i,0,n) scanf("%d", a + i);
		int tmp = 0, diff = 0;
		FOR(i,0,n){
			if (a[i] < tmp) a1 += tmp - a[i];
			tmp = a[i];
		}
		FOR(i,0,n-1) diff = max(diff, a[i] - a[i + 1]);
		tmp = a[0];
		FOR(i,0,n - 1){
			LL sub = min(tmp, diff);
			a2 += sub;
			tmp = a[i + 1];
		}
		printf("%lld %lld\n", a1, a2);
	}
	return 0;
}

