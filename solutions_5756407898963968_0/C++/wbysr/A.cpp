#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
bool f[100];
using namespace std;
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("asmall.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++){
		memset(f,0,sizeof(f));
		int ans1,ans2,res=0;
		scanf("%d",&ans1);
		for (int i=1;i<=4;i++)
			for (int j=1;j<=4;j++){
				int x;
				scanf("%d",&x);
				if (i==ans1) f[x]=1;
			}
		scanf("%d",&ans2);
		bool f1=0;
		for (int i=1;i<=4;i++)
			for (int j=1;j<=4;j++){
				int x;
				scanf("%d",&x);
				if (i==ans2){
					if (!f1&&f[x]){
						res=x;f1=1;
					}
					else if (f1&&f[x]) res=-1;
				}
			}
		if (res==0) printf("Case #%d: Volunteer cheated!\n",t);
		else if (res!=-1) printf("Case #%d: %d\n",t,res);
		else printf("Case #%d: Bad magician!\n",t);
	}
	return 0;
}
