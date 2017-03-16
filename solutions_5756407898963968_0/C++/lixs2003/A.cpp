#include<iostream>
#include<string.h>
#include<stdio.h>
#include<memory.h>
using namespace std;

int flag[20],n1,n,i1,i,j,res,a,b,x;

int main()
{
	cin>>n1;
	for(i1=1;i1<=n1;i1++)
	{
		memset(flag,0,sizeof(flag));
		cin>>a;
		for(i=1;i<=4;i++)
			for(j=1;j<=4;j++)
			{
				cin>>x;
				if(i==a)
				{
					flag[x]=1;
				}
			}
		cin>>b;res=0;
		for(i=1;i<=4;i++)
			for(j=1;j<=4;j++)
			{
				cin>>x;
				if(i==b)
				{
					if(flag[x]==1)
					{
						if(res!=0)
							res=-1;
						else res=x;
					}
				}
			}
		cout<<"Case #"<<i1<<": ";
		if(res==0)
			cout<<"Volunteer cheated!"<<endl;
		else if(res==-1)
			cout<<"Bad magician!"<<endl;
		else cout<<res<<endl;
	}
	return 0;
} 
