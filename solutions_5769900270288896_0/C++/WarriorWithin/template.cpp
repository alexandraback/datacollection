#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>

#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define vpii vector <pair<int, int> >
#define vpll vector <pair<ll, ll> >
#define pll pair<ll, ll>

#define f first
#define s second

#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)

#define pb push_back
#define pob pop_back

#define max_size 100005
#define max_capacity INT_MAX

using namespace std;

ll ans = -1;

ll board[20][20];

ll check(ll n, ll r, ll c)
{	
	ll total = 0;
	ll ret = 0;

	for(ll i=1; i<=r; i++)
	{
		for(ll j=1; j<=c; j++)
		{
			if(board[i][j]==1)
			{
				total++;
				if(j+1<=c && board[i][j+1]==1)
					ret++;

				if(i+1<=r && board[i+1][j]==1)
					ret++;
			}
		}
	}

	if(total==n)
		return ret;

	return -1;
}

void recurse(ll i, ll j, ll r, ll c, ll n)
{
	if(i==r && j==c)
	{
		board[i][j] = 0;

		ll unhappiness = check(n, r, c);
		if(unhappiness!=-1 && (ans==-1 || ans>unhappiness))
			ans = unhappiness;

		board[i][j] = 1;
		unhappiness = check(n, r, c);
		if(unhappiness!=-1 && (ans==-1 || ans>unhappiness))
			ans = unhappiness;

		return;
	}

	board[i][j] = 0;
	if(j<c)
		recurse(i, j+1, r, c, n);
	else
		recurse(i+1, 1, r, c, n);

	board[i][j] = 1;
	if(j<c)
		recurse(i, j+1, r, c, n);
	else
		recurse(i+1, 1, r, c, n);
}

int main()
{
	ll t;
	cin>>t;
	for(ll m=1; m<=t; m++)
	{
		ll r, c, n;
		cin>>r>>c>>n;

		ans = -1;
		recurse(1, 1, r, c, n);
		cout<<"Case #"<<m<<": "<<ans<<endl;
	}

	return 0;
}