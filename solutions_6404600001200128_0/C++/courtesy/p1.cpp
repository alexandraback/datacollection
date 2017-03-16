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
int n,a[1000];
int main()
{
	int t,i,j,k,cs,css;
	ll an1,an2;
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cout<<"Case #"<<cs<<": ";
		cin>>n;
		for(i=0;i<n;i++)cin>>a[i];
		an1=0;
		for(i=1;i<n;i++)
		{
			if(a[i]<a[i-1])an1+=(a[i-1]-a[i]);
		}
		k=0;
		for(i=1;i<n;i++)
		{
			if((a[i-1]-a[i])>k)k=a[i-1]-a[i];
		}
		an2=0;
		for(i=0;i<n-1;i++)
		{
			if(a[i]<k)an2+=a[i];
			else an2+=k;
		}
		cout<<an1<<" "<<an2<<endl;
	}
	return 0;
}
