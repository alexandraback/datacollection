#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
int T,ti;
cin>>T;
for(ti=0;ti<T;ti++)
{
	
int l[4], oline1[4], oline2[4];
int i,j,cmd;
int cnt=0,ans=-1;
	scanf("%d",&cmd);
	for(i=1;i<=4;i++)
	{
		scanf("%d %d %d %d\n",&l[0],&l[1],&l[2],&l[3]);
		if(cmd==i)
			for(j=0;j<4;j++)oline1[j]=l[j];
	}

	scanf("%d",&cmd);
	for(i=1;i<=4;i++)
	{
		scanf("%d %d %d %d\n",&l[0],&l[1],&l[2],&l[3]);
		if(cmd==i)
			for(j=0;j<4;j++)oline2[j]=l[j];
	}


	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		if(oline1[i]==oline2[j])
		{
			ans=oline1[i];cnt++;
		}
	}
	
	
	cout<<"Case #"<<(ti+1)<<": ";
	if(cnt==0)cout<<"Volunteer cheated!";
	if(cnt>1)cout<<"Bad Magician!";
	if(cnt==1)cout<<ans;
	cout<<endl;
}
return 0;
}