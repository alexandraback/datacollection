#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
inline int get()
{
    int f=0,v=0;char ch;
    while(!isdigit(ch=getchar()))if(ch=='-')break;
    if(ch=='-')f=1;else v=ch-48;
    while(isdigit(ch=getchar()))v=v*10+ch-48;
    if(f==1)return -v;else return v;
}
int a[6][6],f[20];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T=get();
	for(int t=1;t<=T;t++)
	{
		memset(f,0,sizeof(f));
		int r=get();
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)a[i][j]=get();
		for(int i=1;i<=4;i++)f[a[r][i]]++;
		r=get();
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)a[i][j]=get();
		for(int i=1;i<=4;i++)f[a[r][i]]++;
		int cnt=0,ans;
		for(int i=1;i<=16;i++)
			if(f[i]==2)cnt++,ans=i;
		printf("Case #%d: ",t);
		if(cnt==1)printf("%d\n",ans);
		else if(cnt==0)puts("Volunteer cheated!");
		else puts("Bad magician!");
	}
	return 0;
}
