#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tests,i,j,k,n,a[51],t1,t2,sum,tc;
int main(){
	for (tc=1,scanf("%d",&tests);tests--;tc++){
		fprintf(stderr,"* %d\n",tc);
		scanf("%d",&n);
		for (i=1;i<=n;i++) scanf("%d",&a[i]);
		printf("Case #%d:",tc);
		while (1){
			if (a[1]>=a[2]) t1=1,t2=2;else t1=2,t2=1;
			for (i=3,sum=a[1]+a[2];i<=n;i++){
				sum+=a[i];
				if (a[i]>a[t1]) t2=t1,t1=i;
				else if (a[i]>a[t2]) t2=i;
			}
			if (!sum) break;
			if (sum!=3&&a[t1]==a[t2]){
				a[t1]--;a[t2]--;printf(" %c%c",t1+'A'-1,t2+'A'-1);
			}else{
				a[t1]--;printf(" %c",t1+'A'-1);
			}
		}
		puts("");
	}
	return 0;
}
