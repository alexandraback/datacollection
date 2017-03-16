/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define vi				vector<int>
#define vl				vector<ll>
#define	pii				pair<int,int>
#define pil				pair<int, ll>
#define pll				pair<ll, ll>
#define pli 			pair<ll, int>
#define pb(v, a)		v.push_back(a)
#define mp(a, b)		make_pair(a, b)
#define MOD				1000000007
#define rep(i, a, b)	for(i=a; i<=b; ++i)
#define rrep(i, a, b)	for(i=a; i>=b; --i)
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")
ll pow_mod(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
int ar[17][17];
int main()
{
	int t, tcase;
	si(t);
	rep(tcase, 1, t)
	{
		int r, c, n;
		cin>>r>>c>>n;
		cout<<"Case #"<<tcase<<": ";
		if(n <= (r * c + 1) / 2)
			cout<<"0\n";
		else
		{
			int final_ans = INT_MAX;
			int i, j, k;
			rep(i, 1, (1 << (r * c)) - 1)
			{
				memset(ar, 0, sizeof(ar));
				int filled = 0;
				rep(j, 0, r * c - 1)
					if(i & (1 << j))
						filled++;
				if(filled == n)
				{
					rep(j, 0, r * c - 1)
					{
						if(i & (1 << j))
						{
							int idx = (j + 1) / c;
							if((j + 1) % c)
								idx++;
							int idy = (j + 1) - (idx - 1) * c;
							ar[idx][idy] = 1;
						}
					}
					int ans = 0;
					rep(j, 1, r)
					{
						rep(k, 1, c)
						{
							if(ar[j][k])
							{
								if(j > 1 && ar[j - 1][k])
									ans++;
								if(k > 1 && ar[j][k - 1])
									ans++;
							}
						}
					}
					final_ans = min(final_ans, ans);
				}
			}
			cout<<final_ans<<endl;
		}
	}
	return 0;
}