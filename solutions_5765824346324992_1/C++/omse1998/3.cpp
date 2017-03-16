#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <deque>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define y1 yy1

using namespace std;

int b,n,tt,t,i,a[1010],rest;
ll mx_val,x,need,cur,curtime,finish;

bool run(ll x)
{
	ll kol=0;
	for (int i=1; i<=b; i++)
	{
		kol+=(x+a[i]-1)/a[i];
		if (x%a[i]==0) kol++;
	}
	return kol>=n;
}

ll binpoisk(ll l,ll r)
{
	if (l==r) return l;
	ll m=(l+r)/2;
	if (run(m))
		return binpoisk(l,m);
	else
		return binpoisk(m+1,r);
}

int main()
{
	//ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>t;
	mx_val=(ll)1e14;
	for (tt=1; tt<=t; tt++)
	{
		cin>>b>>n;
		for (i=1; i<=b; i++)
			cin>>a[i];
		cur=n;
		/*finish=binpoisk(1,mx_val);
		cur=n-1;
		curtime=binpoisk(1,mx_val);
		while (curtime==finish && cur>0)
		{
			cur--;
			curtime=binpoisk(1,mx_val);
		}
		rest=n-cur-1;
		//need=finish-curtime;
		for (i=1; i<=b; i++)
		{
			if (curtime%a[i]==0)
			{
			    if (!rest)
			    {
			    	cout<<"Case #"<<tt<<": "<<i<<endl;
					break;
			    }
			    rest--;
			}
		}*/
		x=binpoisk(0,mx_val);
		ll kol=0;
		for (i=1; i<=b; i++)
		{
			kol+=(x+a[i]-1)/a[i];
		}	
		for (i=1; i<=b; i++)
		{
			if (x%a[i]==0)
			{
				kol++;
				if (kol==n)
				{
					cout<<"Case #"<<tt<<": "<<i<<endl;
					break;
				}
			}
		}
	}
	return 0;
}


