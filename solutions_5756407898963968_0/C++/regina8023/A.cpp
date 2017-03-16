#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<map>
#include<vector>
bool f[100];
using namespace std;
int main(){
	int T;
	//freopen("A-small-attempt1.in","r",stdin);
	//freopen("A-small-attempt1.out","w",stdout);
	scanf("%d",&T);
	for (int t=1;t<=T;t++){
		memset(f,0,sizeof(f));
		int ans1,ans2,rjl=0;
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
						rjl=x;f1=1;
					}
					else if (f1&&f[x]) rjl=-1;
				}
			}
		if (rjl==0) printf("Case #%d: Volunteer cheated!\n",t);
		else if (rjl!=-1) printf("Case #%d: %d\n",t,rjl);
		else printf("Case #%d: Bad magician!\n",t);
	}
	return 0;
}
