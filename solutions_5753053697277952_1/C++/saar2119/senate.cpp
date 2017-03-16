/*
    Author:-Sarthak Taneja
    CSE 2nd year,MNNIT Allahabad
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair< int,int > ii;
typedef vector< ii > vii;

#define sfd(x) scanf("%d",&x)
#define sfs(x) scanf("%s",x)
#define sff(x) scanf("%lf",&x)
#define mod 1000000007
#define MAX 1000000
#define INF 1000000000
#define pb push_back
#define mp make_pair
#define fr first 
#define sc second
#define testcases scanf("%d",&t);while(t--)
#define ffor(a,b,c) for(a=b;a<c;a++)
#define rfor(a,b,c) for(a=b;a>=c;a--)

ll power(ll base, ll exp)
{
	if(exp == 0)
	return 1;
	ll r = power(base, exp/2);
	r=(r*r)%mod;
	if(exp&1)
		r=(r*base)%mod;
	return r;
}

/**********************************************/

int main()
{
	int i,j,t;
	int casecnt=1;
	int n;
	set< pair<int, char> > sett;

	testcases
	{
		printf("Case #%d: ",casecnt++);

		scanf("%d",&n);
		int x;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			sett.insert(mp(x, i+'A'));
		}

		while(sett.size() > 0)
		{
			pair <int, char> pp,qq;
			pp= *(--sett.end());
			qq= *(--(--sett.end()));

			if(pp.fr - qq.fr >1)
			{
				printf("%c%c ",pp.sc,pp.sc);
				sett.erase(pp);
				pp.fr-=2;
				if(pp.fr > 0)
					sett.insert(pp);

			}
			else if(pp.fr - qq.fr == 1)
			{
				printf("%c ",pp.sc);
				sett.erase(pp);
				pp.fr-=1;
				if(pp.fr > 0)
					sett.insert(pp);
			}	
			else
			{
				if(sett.size() == 3)
				{
					sett.erase(pp);
					pp.fr-=1;
					printf("%c ",pp.sc);
					if(pp.fr > 0)
						sett.insert(pp);
					continue;
				}
				printf("%c%c ",pp.sc, qq.sc);
				sett.erase(pp);
				sett.erase(qq);
				pp.fr--;
				qq.fr--;
				if(pp.fr > 0)
					sett.insert(pp);
				if(qq.fr > 0)
					sett.insert(qq);
			}

		}
		printf("\n");
	}
	return 0;
}