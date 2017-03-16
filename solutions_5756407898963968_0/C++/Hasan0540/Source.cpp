#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int a[4][4],b[4][4];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,r1,r2;
	scanf("%d",&t);
	for(int k=1;k<=t;++k){
		printf("Case #%d: ",k);
		scanf("%d",&r1);
		--r1;
		bool vis[17]={0};
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j){
				scanf("%d",&a[i][j]);
				if(r1==i)
					vis[a[i][j]]=true;
			}
		scanf("%d",&r2);
		--r2;
		int res=-1;
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j){
				scanf("%d",&b[i][j]);
				if(i==r2 && vis[b[i][j]]){
					if(res==-1)
						res=b[i][j];
					else
						res=-2;
				}
			}
		if(res==-1)
			puts("Volunteer cheated!");
		else if(res==-2)
			puts("Bad magician!");
		else
			printf("%d\n",res);
	}
	return 0;
}