#include <stdio.h>

int t,r,c,n;
int M[20][20];

int main(){
	scanf("%d",&t);
	for(int tt=1;tt<=t;++tt){
		scanf("%d%d%d",&r,&c,&n);
		printf("Case #%d: ",tt);
		int k=r*c;
		int res=-1;
		for(int i=0;i<(1<<k);++i){
			if (__builtin_popcount(i)!=n) continue;
			int q=0;
			for(int a=1;a<=r;++a){
				for(int b=1;b<=c;++b){
					if (i&(1<<q)) M[a][b]=1;
					else M[a][b]=0;
					++q;
				}
			}
			q=0;
			for(int a=1;a<=r;++a){
				for(int b=1;b<=c;++b){
					if (M[a][b]&&M[a-1][b]) ++q;
					if (M[a][b]&&M[a][b-1]) ++q;
				}
			}
			if (res==-1||q<res) res=q;
		}
		printf("%d\n",res);
	}
	return 0;
}
