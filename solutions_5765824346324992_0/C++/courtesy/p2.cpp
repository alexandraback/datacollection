/*  Vivek Kantariya  */
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#define PB push_back
#define pii pair<int,int>
#define MP make_pair
#define sz size()
#define fi first
#define se second
using namespace std;
typedef long long ll;
int a[5],B,n,b[5];
int gcd(int a,int b)
{
	if(a%b==0)return b;
	return gcd(b,a%b);
}
int lcm(int a,int b)
{
	return (a*b)/gcd(a,b);
}
int main()
{
	int t,i,j,k,cs,css;
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cout<<"Case #"<<cs<<": ";
		cin>>B>>n;
		k=1;
		for(i=0;i<B;i++)
		{
			cin>>a[i];
			k=lcm(k,a[i]);
		}
		j=0;
		for(i=0;i<B;i++)j+=(k/a[i]);
		n--;
		n%=j;
		for(i=0;i<B;i++)b[i]=0;
		for(i=0;i<n;i++)
		{
			for(j=1,k=0;j<B;j++)
			{
				if(b[j]<b[k])k=j;
			}
			b[k]+=a[k];
		}
		for(j=1,k=0;j<B;j++)
		{
			if(b[j]<b[k])k=j;
		}
		cout<<k+1<<endl;
	}
	return 0;
}
