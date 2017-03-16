#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define fi first
#define se second
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef pair<int,int> PP;
typedef long long LL;

const int N = 20;
map<PP,int> Ans;
int X[N] , Y[N] , ans[N];
int s1 , s2 , tc , T;
bool chosen[N] , v[N];
PP poi[N];
int n;
PP que[N];

void Init()
{
	Ans.clear();
	scanf("%d",&n);
	fo(i,1,n) scanf("%d%d",&X[i],&Y[i]);
	fo(i,1,n) Ans[PP(X[i],Y[i])] = max(0,n-3);
}

bool cmp1(PP a,PP b)
{
	if (a.se != b.se) return a.se < b.se;
	return a.fi > b.fi;
}

LL cross(LL x1,LL y1,LL x2,LL y2)
{
	return x1*y2 - x2*y1;
}

LL jl(LL x,LL y)
{
	return (x-s1)*(x-s1) + (y-s2)*(y-s2);
}

bool cmp2(PP a,PP b)
{
	if (cross(a.fi-s1,a.se-s2,b.fi-s1,b.se-s2) == 0)
		return jl(a.fi , a.se) > jl(b.fi , b.se);
	return cross(a.fi-s1,a.se-s2,b.fi-s1,b.se-s2) > 0;
}

void dfs(int x,int y)
{
	if (x > n)
	{
		if (y == n || y == n-1 || y == n-2) return;
		int tot = 0;
		fo(i,1,n)
		if (chosen[i])
			poi[++tot] = PP(X[i] , Y[i]);
		sort(poi+1,poi+1+tot,cmp1);
		
		int s1 = poi[1].fi , s2 = poi[1].se;
		sort(poi+2,poi+2+tot,cmp2);
		
		fo(i,1,n) v[i] = 0;
		que[1] = poi[1];
		que[2] = poi[2];
		int k = 2;
		fo(i,2,tot)
		if (i == tot || cross(poi[i].fi-s1,poi[i].se-s2,poi[i+1].fi-s1,poi[i+1].se-s2))
		{
			k = i;
			break;
		}
		fo(i,1,k) v[i] = 1;
		int temp = k;
		k = tot;
		fd(i,tot,1)
		if (i ==1 || cross(poi[i].fi-s1,poi[i].se-s2,poi[i-1].fi-s1,poi[i-1].se-s2))
		{
			k = i;
			break;
		}
		fo(i,k,tot) v[i] = 1;
		
		int st(1) , en(2);
		fo(i,temp+1,tot)
		{
			while (st < en && cross(que[en].fi-que[en-1].fi,que[en].se-que[en-1].se,poi[i].fi-que[en-1].fi,poi[i].se-que[en-1].se) < 0) en--;
			que[++en] = poi[i];
		}
		
		fo(i,1,tot)
		if (v[i])
			Ans[poi[i]] = min(Ans[poi[i]] , y);
		fo(i,st,en)
			Ans[que[i]] = min(Ans[que[i]] , y);
		return;
	}
	
	dfs(x+1,y+1);
	
	chosen[x] = 1;
	dfs(x+1,y);
	chosen[x] = 0;
}

void Work()
{
	dfs(1 , 0);
	fo(i,1,n) printf("%d\n",Ans[PP(X[i],Y[i])]);
}

int main()
{
	freopen("c.in","r",stdin); freopen("ans.out","w",stdout);
	
	scanf("%d",&T);
	for(tc=1;tc<=T;tc++)
	{
		printf("Case #%d:\n",tc);
		Init();
		Work();
	}
	
	return 0;
}