#include <stdio.h>

int all[1005];

int main()
{
	int cas;
	int n;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("pa0.out","w",stdout);
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		int mmin=0,mmax=0,v;
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			scanf("%d",&all[i]);
		}
		v=0;
		for(int i=1; i<n; i++){
			if(all[i-1]>all[i]){
				mmin+=all[i-1]-all[i];
				if(v<all[i-1]-all[i])
					v=all[i-1]-all[i];
			}
		}
		for(int i=0; i<n-1; i++){
			if(all[i]>=v)
				mmax+=v;
			else
				mmax+=all[i];
		}
		printf("Case #%d: %d %d\n",T,mmin,mmax);
	}
	return 0;
}
