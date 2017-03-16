//azariamuh

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

int inf = 1000000;
typedef long long LL;

#define forn(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define reset(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()

int T,r,c,n;
int dp[17][17][1<<17][2][17];

int on(int bit,int ix)
{
	return ((bit & (1 << ix)) > 0 ? 1 : 0);
}

int rekur(int x,int y,int bit,int now,int rem)
{
	if (rem == 0)
	{
		int ret = 0;
		if (y > 0) ret += now * on(bit,0);
		if (x > 0) ret += now * on(bit,c - 1);
		return ret;
	}
	if (x == r) return inf;
	int &ret = dp[x][y][bit][now][rem];
	if (ret >= 0) return ret;
	ret = inf;
	int xx = x;
	int yy = y + 1;
	if (yy == c) xx++, yy = 0; 
	ret = min(ret,rekur(xx,yy,(bit * 2 + now) & ((1 << c) - 1),0,rem));
	if (rem > 0 && xx < r)
		ret = min(ret,rekur(xx,yy,(bit * 2 + now) & ((1 << c) - 1),1,rem - 1));
	//printf("%d %d %d %d %d %d\n",x,y,bit,now,rem,ret);
	if (y > 0) ret += now * on(bit,0);
	if (x > 0) ret += now * on(bit,c - 1);
	//printf("%d %d %d %d %d %d\n",x,y,bit,now,rem,ret);
	return ret;
}

int main()
{
	scanf("%d",&T);
	forn(cases,1,T)
	{
		printf("Case #%d: ",cases);
		scanf("%d %d %d",&r,&c,&n);
		forn(i,0,r-1) forn(j,0,c-1) reset(dp[i][j],-1);
		int res = rekur(0,0,0,0,n);
		if (n > 0) res = min(res,rekur(0,0,0,1,n-1));
		printf("%d\n",res);
	}
	return 0;
}













