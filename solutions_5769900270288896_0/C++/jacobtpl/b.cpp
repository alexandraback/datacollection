#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define INF 1000000000
#define UNIQUE(x) (x).resize(distance((x).begin(),unique(all(x))))
int r,c,n;
int main() {
	int tc;
	scanf("%d",&tc);
	for (int kk=0;kk<tc;kk++) {
		scanf("%d%d%d",&r,&c,&n);
		int k=r*c,ans=INF;
		for (int b=0;b<(1<<k);b++) {
			if (__builtin_popcount(b)==n) {
				int a=0;
				for (int i=0;i<r;i++) {
					for (int j=1;j<c;j++) {
						int x=i*c+j;
						if ((b&(1<<x))&&(b&(1<<(x-1)))) a++;
					}
				}
				for (int j=0;j<c;j++) {
					for (int i=1;i<r;i++) {
						int x=i*c+j;
						if ((b&(1<<x))&&(b&(1<<(x-c)))) a++;
					}
				}
				ans=min(ans,a);
			}
		}
		printf("Case #%d: %d\n", kk+1,ans);
	}
}