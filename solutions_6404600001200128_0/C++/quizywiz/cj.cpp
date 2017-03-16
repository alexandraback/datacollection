#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;++i)
#define repi(i,a,b) for(int i=a;i<b;++i)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define vi vector<int>
#define sc(a) scanf("%d",&a)
#define lli long long int

int n,t;
int a[1001];
int main() {
	// your code goes here
	sc(t);
	repi(itt,1,t+1)
	{
		sc(n);
		repi(i,0,n)sc(a[i]);
		int minans = 0;
		repi(i,0,n-1)
		{
			if(a[i]>a[i+1])minans += a[i]-a[i+1];
		}
		cout<<"Case #"<<itt<<": ";
		cout<<minans<<" ";
		int maxdiff=0;
		repi(i,0,n-1)
		{
			if(maxdiff < a[i]-a[i+1])
			{
				maxdiff = a[i]-a[i+1];
			}
		}
		int cur = a[0];
		minans = 0;
		repi(i,1,n)
		{
			if(cur<=maxdiff){minans += cur; cur = 0;}
			else {minans += maxdiff; cur -= maxdiff; }
			cur = a[i];
		}
		cout<<minans<<endl;;
	}
	return 0;
}