#include<iostream>
#include<string.h>
#include<stdio.h>
#include<memory.h>
#include<string>
#include<algorithm>
using namespace std;

string str[110];
char ch[110];
int rec[110][110],a[110],p,n,n1,i1,i,j,num,num1,u;

int main()
{
		cin>>n1;
	
	for(i1=1;i1<=n1;i1++)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>str[i];
		}
		
		cout<<"Case #"<<i1<<": ";
		u=0;
		num=0;p=0;
		for(i=0;i<str[1].length();i++)
		{
			if(i==0||str[1][i]!=str[1][i-1])
			{
				num++;
				ch[num]=str[1][i];
				rec[1][num-1]=p;
				p=0;
			}
			else
				p++;
		}
		rec[1][num]=p;
		for(j=2;j<=n;j++)
		{
			num1=0;p=0;
			for(i=0;i<str[j].length();i++)
			{
				if(i==0||str[j][i]!=str[j][i-1])
				{
					num1++;
					if(ch[num1]!=str[j][i])
					{
						u=1;
						break;
					}
					rec[j][num1-1]=p;
					p=0;
				}
				else
					p++;
			}
			if(u==1)
				break;
			if(num!=num1)
			{
				u=1;
				break;
			}
			rec[j][num]=p;
		}
		if(u==1)
		{
			cout<<"Fegla Won"<<endl;
			continue;
		}
		p=0;
		for(i=1;i<=num;i++)
		{
			for(j=0;j<n;j++)
				a[j]=rec[j+1][i];
			sort(a,a+n);
			for(j=0;j<n;j++)
			{
				p+=abs(a[j]-a[n/2]);
			}
		}
		cout<<p<<endl;
	}
	
	return 0;
} 
