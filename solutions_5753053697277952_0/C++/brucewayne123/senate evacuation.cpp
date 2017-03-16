/*input
4
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1
*/
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define pii pair<long long,long long>
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
#define PI 3.14159265
#define ll long long
#define ff first
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define debug(x) cout << #x << " = " << x << endl
#define INF 1000000009
#define mod 1000000007
pii arr[50];
int main() 
{
	std::ios::sync_with_stdio(false);
	freopen("is1.txt","r",stdin);
	freopen("os1.txt","w",stdout);
	ll t;
	cin>>t;
	F(T,1,t)
	{
		cout<<"Case #"<<T<<": ";
		ll n;
		cin>>n;
		F(i,0,n-1)
		{
			ll x;
			cin>>x;
			arr[i] = mp(x,i);
		}
		sort(arr,arr+n);
		if(arr[n-1].ff!=arr[n-2].ff)
		{
			ll rem = arr[n-1].ff-arr[n-2].ff;
			F(i,1,rem)
				cout<<(char)(arr[n-1].ss+65);
			cout<<" ";
		}
		F(i,0,n-3)
		{
			ll num = arr[i].ff;
			char c = (char)(arr[i].ss+65);
			if(num%2==1)
			{
				while(num!=1)
				{
					cout<<c<<c<<" ";
					num -= 2;
				}
				cout<<c<<" ";
			}
			else
			{
				while(num!=0)
				{
					cout<<c<<c<<" ";
					num -= 2;
				}
			}
		}
		char c,d;
		c = (char)(arr[n-2].ss+65);
		d = (char)(arr[n-1].ss+65);
		ll num = arr[n-2].ff;
		F(i,1,num)
		{
			cout<<c<<d<<" ";
		}
		cout<<endl;
	}
	return 0;
}