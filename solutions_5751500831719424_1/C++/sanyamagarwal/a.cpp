
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <iomanip>
using namespace std;


#define ll long long
#define rep(i,a,b) for(ll i = a;i<b;i++)
#define rev(i,a,b) for(ll i = (b-1); i>=a;i-- )
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld%lld",&a,&b)
#define slll(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define sllll(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define MOD 1000000007


ll cool(ll arr[], ll n)
{
	ll min = 100000;
	ll max = 0;
	rep(i,0,n)
	{if(arr[i]<min) min =  arr[i];
	if(arr[i]>max) max = arr[i];}
	ll min_val  = 100000;
	rep(i,min,max+1)
	{
		ll thisval = 0;
		rep(j,0,n)
		thisval += abs(arr[j]-i);
		if(thisval < min_val) min_val = thisval;
	}
	return min_val;
}


int main()
{
	ll test;
	sl(test);
	rep(tt,1,test+1)
	{
		printf("Case #%lld: ",tt );
		ll n;
		sl(n);
		string str;
		vector<vector<ll> >  good(n);
		vector<vector<char> > check(n);
		rep(i,0,n)
		{
			cin>>str;
			str += '$';
			char prev = '$';
			ll count = 0;
			rep(j,0,str.size())
			{
				if(prev != str[j]) {
					good[i].push_back(count);
					check[i].push_back(prev);
					count = 0;
				}
				prev = str[j];
				count ++;
			}
		}
		bool flag = true;
		rep(i,0,n-1)
		{
			if(check[i]!= check[i+1]) {
				flag = false;
				break;
			}
		}
		if(!flag)
		{
			printf("Fegla Won\n" );
			continue;
		}
		ll sz = good[0].size();
		ll arr[200][200];
		rep(i,0,sz)
		rep(j,0,n)
		arr[i][j] = good[j][i];

		ll ans = 0;
		rep(i,0,sz)
		{
			ans += cool(arr[i],n);
		}
		printf("%lld\n",ans );
	}
}











