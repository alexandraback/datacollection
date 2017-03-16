#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int i,j,n,m,t,flag,ans,x,y,k;
	string a,b;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
	flag=0;
	ans=0;
	scanf("%d",&n);
	cin >> a >>b;
	x=a.size();
	y=b.size();
	i=0;
	j=0;
	while(i<x && j<y)
	{
		if(a[i]==b[j])
		{
			i++;
			j++;
		}
		else
		{
			if(a[i]==b[j-1])
			{
				i++;
				ans++;
			}
			else if(a[i-1]==b[j])
			{
				j++;
				ans++;
			}
			else if(a[i]==a[i-1])
			{
				i++;
				ans++;
			}
			else if(b[j]==b[j-1])
			{
				j++;
				ans++;
			}
			else
			{
				flag=1;
				break;
			}
		}
	}
	while(i<x)
	{
			if(a[i]==b[j-1])
			{
				i++;
				ans++;
			}
			else if(a[i]==a[i-1])
			{
				i++;
				ans++;
			}
			else
			{
				flag=1;
				break;
			}
	}
	while(j<y)
	{
			if(a[i-1]==b[j])
			{
				j++;
				ans++;
			}
			else if(b[j]==b[j-1])
			{
				j++;
				ans++;
			}
			else
			{
				flag=1;
				break;
			}
	}
	if(!flag)	printf("Case #%d: %d\n",k,ans);
	else		printf("Case #%d: Fegla Won\n",k);
	}
	return 0;
}
