#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdio>
#include<vector>
#include<cassert>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<iostream>
#include<algorithm>
#include<functional>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 105
using namespace std;
typedef long long LL;
typedef pair<char,int> P;
int t,n,len,cnt;
vector<P> in[M],pre[M];
vector<int> ord;
char tmp[M],cur;
bool check()
{
	REP(i,2,n)
	{
		if(in[i].size() != in[i-1].size())return false;
		REP(j,0,(int)in[i].size()-1)
			if(in[i][j].F != in[i-1][j].F)
				return false;
	}
	return true;
}
int main()
{
	scanf("%d",&t);
	REP(tt,1,t)
	{
		scanf("%d",&n);
		REP(i,1,n)
		{
			in[i].clear();
			scanf("%s",tmp);
			len=strlen(tmp);
			
			cur=tmp[0];cnt=1;
			REP(j,1,len-1)
			{
				if(cur != tmp[j])
				{
					in[i].PB(MP(cur, cnt));
					cnt=1;
					cur=tmp[j];
				}
				else
					cnt++;
			}
			in[i].PB(MP(cur,cnt));
		}

		printf("Case #%d: ", tt);
		if(!check())puts("Fegla Won");
		else
		{
			int ans=0, num;
			REP(i,0,(int)in[1].SZ-1)
			{
				ord.clear();
				REP(j,1,n)ord.PB(in[j][i].S);
				sort(ord.begin(), ord.end());

				num = ord[n/2];
				FOR(j,ord)ans+=abs(*j-num);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

