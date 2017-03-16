#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long

LL n,a[10005];
int b;

int main() {
	int tc;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++) {
		scanf("%d%lld",&b,&n);
		for (int i=0; i<b; i++)
			scanf("%lld",&a[i]);
		LL mi = 0,mx = 100000LL*10000LL*100000LL,mid;
		LL best = -1,now,num;
		while (mi < mx) {
			mid = (mi+mx)/2;
			now = 0;
			for (int i=0; i<b; i++)
				now += (mid-1)/a[i]+1;
			//printf("%lld->%lld %lld: %lld\n",mi,mx,mid,now);
			if (now < n) {
				mi = mid+1;
				if (mid > best) {
					best = mid; num = n-now-1;
				}
			}
			else {
				mx = mid;
			}
		}
		//printf("best %lld %lld\n",best,num);
		for (int i=0; i<b; i++)
			if (best%a[i] == 0) {
				if (num == 0) {
					printf("Case #%d: %d\n",t,i+1);
					break;
				}
				num--;
			}
	}
    return 0;
}
