#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<utility>
#include<vector>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>

#define inf 2123123123
#define LL long long
#define MP make_pair
#define ii pair<int,int>
using namespace std;
int n,i,j,ar[5][5],a,b,t,ans,c;
bool F[20];

void OPEN(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}

int main(){
	OPEN();
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		memset(F,0,sizeof(F));
		ans=c=0;
		scanf("%d",&a);
		for(i=1;i<=4;i++)
			for(j=1;j<=4;j++)
				scanf("%d",&ar[i][j]);
		for(j=1;j<=4;j++)
			F[ar[a][j]]=1;
		scanf("%d",&b);
		for(i=1;i<=4;i++)
			for(j=1;j<=4;j++)
				scanf("%d",&ar[i][j]);
		for(j=1;j<=4;j++)
			if(F[ar[b][j]]){
				ans=ar[b][j];
				c++;
			}
		printf("Case #%d: ",z);
		if(c==0)	printf("Volunteer cheated!\n");
		else if(c==1)	printf("%d\n",ans);
		else	printf("Bad magician!\n");
	}
	return 0;
}