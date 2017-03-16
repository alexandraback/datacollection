#include<stdio.h>
#include<map>
using namespace std;
typedef pair<long long,long long> P;

P p[15];

P dir(P a,P b){
	return P(b.first-a.first,b.second-a.second);
}

long long cross(P a,P b){
	return a.first*b.second-a.second*b.first;
}

int main(){
	int dn;
	scanf("%d",&dn);
	for(int di=0;di<dn;di++){
		int n,i,j,k;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			p[i]=P(x,y);
		}
		printf("Case #%d:\n",di+1);
		for(i=0;i<n;i++){
			int ans=n-1;
			for(j=0;j<n;j++){
				if(j==i)continue;
				int a=0,b=0,c=0;
				for(k=0;k<n;k++){
					long long cr=cross(dir(p[i],p[j]),dir(p[k],p[i]));
					if(cr<0)a++;
					if(cr==0)b++;
					if(cr>0)c++;
				}
				ans=min(ans,a);
				ans=min(ans,c);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}