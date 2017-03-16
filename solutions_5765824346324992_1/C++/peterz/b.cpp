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
#define PII pair<LL,LL>
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define INF (1LL << 30)
#define EPS (1e-9)
#define REP(i,n) FOR(i,0,n)
#define LL long long
#define N 2000
LL m, B;
LL a[N], lo, hi, mid, n;
int main(){
	int T;
	scanf("%d", &T);
	FOE(cc,1,T){
		printf("Case #%d: ", cc);
		scanf("%lld%lld", &B, &n);
		FOR(i,0,B) scanf("%lld", a + i);
		lo = 0;
		hi = 1 + INF * a[0];
		//		printf("lo: %lld hi: %lld\n", lo, hi);
		FOR(i,1,B) hi = min(hi,  1000000000LL* a[i]);
		//		printf("lo: %lld hi: %lld\n", lo, hi);
		int ans = -1;
		while(lo <= hi){
			mid = (lo + hi) / 2;
			LL fin = 0, free = 0, cut = 0;
			FOR(i,0,B) fin += mid / a[i];
			FOR(i,0,B) if (mid % a[i] == 0) free++;
			cut = B - free;
			if (fin + cut < n){
				if (fin + B >= n){
					LL rem = n - fin - cut;
					/*
					vector<PII> vec;
					vec.clear();
					//printf("mid %d\n", mid);
					FOR(i,0,B) vec.PB(PII(a[i] * (mid / a[i]), i));
					sort(vec.begin(), vec.end());
	//				printf("%lld %lld %lld %lld %lld %lld %lld\n", lo, hi, mid, fin, free, n, n - fin);
					int sum = 0;
					FOR(i,0,B) sum += mid / a[i];
					//FOR(i,0,B) printf("%lld %lld\n", vec[i].X, vec[i].Y);
					//puts("asdasd");
					*/
					FOR(i,0,B){
						if (mid % a[i] == 0) rem--;
						if (!rem){
							ans = i + 1;
							break;
						}
					}
					break;
				}
				else{
					lo = mid + 1;
				}
			}
			else hi = mid - 1;
			/*
			   else if (fin + (B - free) >= n){
			   hi = mid - 1;
			   }
			   else{
			   lo = mid + 1;
			   }
			   */
		}
		printf("%d\n", ans);
	}
	return 0;
}

