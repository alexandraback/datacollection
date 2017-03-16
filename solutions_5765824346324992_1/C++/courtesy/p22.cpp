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
int n,B,a[1000];
ll b[1000],jobs,mn;
void fill(ll tm)
{
	ll i,j,k;
	mn=0;jobs=0;
	for(i=0;i<B;i++)
	{
		k=tm/a[i];
		jobs+=k;
		b[i]=tm%a[i];
		if(b[mn]<b[i])mn=i;
	}
	mn++;
}
int fn(ll tm)
{
	//cout<<tm<<endl;
	ll i,j,k,an;
	jobs=0;
	for(i=0;i<B;i++)
	{
		k=tm/a[i];
		jobs+=k;
		b[i]=tm%a[i];
		b[i]=-b[i];
	}
	for(i=jobs+1;i<=n;i++)
	{
		for(j=1,k=0;j<B;j++)
		{
			if(b[j]<b[k])k=j;
		}
		b[k]+=a[k];
		an=k+1;
	}
	return an;
}
int fun(ll l,ll r)
{
	//cout<<l<<" "<<r<<endl;
	if(l==r)
	{
		fill(l);
		if(jobs<n-1)return fn(l);
		return mn;
	}
	ll i,j,k;
	k=(l+r)/2;
	fill(k);
	if(jobs==n-1)return mn;
	if(jobs>n-1)
	{
		if(jobs-n+1<2000)return fn(l);
		return fun(l,k-1);
	}
	if(n-1-jobs<2000)return fn(k);
	return fun(k+1,r);
}
int main()
{
	int t,i,j,k,cs,css;
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cout<<"Case #"<<cs<<": ";
		cin>>B>>n;
		for(i=0;i<B;i++)cin>>a[i];
		cout<<fun(0,2000000000000000)<<endl;
//		cout<<jobs<<" "<<mn<<endl;
	}
	return 0;
}
