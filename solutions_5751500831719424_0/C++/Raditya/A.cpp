#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
inline void OPEN(string s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(), "w", stdout);
}
inline void CLOSE()
{
	fclose(stdin);
	fclose(stdout);
}
vector<pii> ve[105];
vector<int> urut;
char ar[105];
int main()
{
	int t;
	scanf("%d", &t);
	for(int i=1;i<=t;i++)
	{
		int n;
		scanf("%d\n", &n);
		for(int j=0;j<n;j++) ve[j].clear();
		bool bisa = 1;
		for(int j=0;j<n;j++)
		{
			gets(ar);
			int SIZ = strlen(ar);
			ve[j].pb(mp(ar[0],1));
			for(int k=1;k<SIZ;k++)
			{
				if(ar[k]!=ar[k-1]) ve[j].pb(mp(ar[k], 1));
				else ve[j].back().se++;
			}
		}
		int tot = 0;
		printf("Case #%d: ",i);
		int segmen = (int)ve[0].size();
		for(int j=0;j<n;j++) if((int)ve[j].size()!=segmen)
		{
			bisa=0;
			puts("Fegla Won");
			break;
		}
		if(!bisa) continue;
		for(int j=0;j<segmen && bisa;j++)
		{
			int huruf = ve[0][j].fi;
			for(int k=0;k<n && bisa;k++)
			{
				if(ve[k][j].fi!=huruf)
				{
					bisa=0;
					puts("Fegla Won");
					break;	
				}
				urut.pb(ve[k][j].se);
			}
			if(!bisa)
			{
				urut.clear();
				break;
			}
			sort(urut.begin(),urut.end());
			for(int k=0;k<n;k++) tot+=abs(urut[n>>1] - urut[k]);
			urut.clear();
		}
		if(!bisa) continue;
		else printf("%d\n", tot);
	}
	return 0;
}
