#include <bits/stdc++.h>
#define maxn 30
using namespace std;
int n,p[maxn];
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int tt,cot=1;
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&p[i]);
		}
		printf("Case #%d:",cot++);
		while(1){
			int sum=0;
			for(int i=0;i<n;i++)
				sum+=p[i];
			if(sum==0)
				break;
			int mx=-1,val=-1;
			for(int i=0;i<n;i++){
				if(p[i]>mx){
					mx=p[i];
					val=i;
				}
			}
			p[val]--;
			mx=-1;
			for(int i=0;i<n;i++){
				mx=max(mx,p[i]);
			}
			if(2*mx<=(sum-1)){
				printf(" %c",'A'+val);
				continue;
			}
			mx=-1;
			int tmp=-1;
			for(int i=0;i<n;i++){
				if(p[i]>mx){
					mx=p[i];
					tmp=i;
				}
			}
			p[tmp]--;
			printf(" %c%c",'A'+val,'A'+tmp);
		}
		puts("");
	}
	//system("pause");
	return 0;
}