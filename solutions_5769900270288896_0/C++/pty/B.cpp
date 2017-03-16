/*.....................
Author : PTY
Time : 15/05/01
Desprition :
Analyse : 
Attention : 
.....................*/
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <map>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define drep(i,r,l) for(int i=r;i>=l;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define LL long long
#define Travel(E, u) for(int i=E.start[u],v;v=E.e[i].a,i;i=E.e[i].next)
#define sqr(x) ((x)*(x))
#define pb push_back
#define read() (strtol(ipos, &ipos, 10))
#define pb push_back
#define pi 3.1415926535897

const int oo = 1e9;
const int maxn = 100008, maxm = 500008;
struct Tedge
{
	int start[maxn], tot;
	struct node
	{
		int next, a;
		double c;
	}e[maxm];
	void clear(int n)
	{
		memset(start, 0, n+1<<2);
		tot = 1; 
	}
	void add(int x, int y, double c)
	{
		//printf("%d %d\n", x, y);
		e[++tot].a = y; e[tot].next = start[x]; start[x] = tot; e[tot].c = c;
		e[++tot].a = x; e[tot].next = start[y]; start[y] = tot; e[tot].c = 0;
	}
}E;
int S, T;
int level[maxn], h[maxn];
struct Tmaxflow
{
	double dinic(int u, double l)
	{
		if (u == T) return l;
		double t = l;
		Travel(E, u)
			if (fabs(E.e[i].c) > 1e-8 && level[v] == level[u] + 1)
			{
				double tmp = dinic(v, min(E.e[i].c, l));
				l -= tmp; E.e[i].c -= tmp; E.e[i^1].c += tmp;
				if (fabs(l) < 1e-9) break;
			}
		if (fabs(l-t) < 1e-9) level[u] = -1;
		return t - l;
	}
	bool bfs()
	{
		int l = 1, r = 1;
		memset(level, 0, T+1<<2);
		level[S] = 1; h[1] = S;
		while (l <= r)
		{
			int u = h[l++];
			Travel(E, u) if (!level[v] && fabs(E.e[i].c) > 1e-8)
			{
				level[v] = level[u] + 1;
				h[++r] = v;
				if (v == T) return 1;
			}
		}
		return 0;
	}
}Maxflow;
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
int r, c, n;
bool in[100008];
struct Tprogram
{
    void open()
    {
        freopen("", "r", stdin);
        freopen("", "w", stdout);
    }
    void close()
    {
        fclose(stdin);
        fclose(stdout);
    }
    void init()
    {
    	scanf("%d%d%d", &r, &c, &n);
    }
    inline int p(int i, int j)
    {
    	return (i-1) * c + j;
    }
    void dfs(int u)
    {
    	if (in[u]) return;
    	in[u] = 1;
    	Travel(E, u)
    		if (fabs(E.e[i].c) > 1e-8)
    			dfs(v);
    }
    int work(double NUM, double &flow)
    {
    	S = 0; T = r*c + 1;
    	E.clear(r*c+2);
    	rep(i,1,r)
    		rep(j,1,c)
    		{
    			if ((i + j) & 1)
    			{
    				//E.add(S, p(i,j), 0);
					E.add(p(i,j), T, NUM);
    				rep(t,0,3)
    				{
    					int i1 = i + dx[t], j1 = j + dy[t];
    					if (i1<=0||i1>r||j1<=0||j1>c) continue;
    					E.add(p(i1,j1),p(i,j),1);
    				}
    			}
    			else
    				E.add(S,p(i,j), NUM); //E.add(p(i,j),T, 0);
    		}
    	flow = 0;
    	while (Maxflow.bfs()) 
			flow += Maxflow.dinic(S, oo);
    	int cnt = 0;
    	memset(in ,0, T+1);
    	dfs(S);
    	Travel(E,S)
    		if (!in[v]) cnt++;
    	Travel(E,T)
    		if (in[v]) cnt++;
    	return r*c-cnt;
    }
}Program;
int main()
{
    //Program.open();
    int T;
    scanf("%d",&T);
    rep(i,1,T)
    {
		printf("Case #%d: ", i);
    	Program.init();
    	double L = 0, R = 1e8, mid;
    	double flow = 0;
    	rep(i,1,100)
    	{
    		mid = (L + R) / 2;
    		int cnt = Program.work(mid, flow);
    		if (cnt <= n) L = mid;
			else R = mid; 
			//printf("%lf\n", mid);
			//if (mid < 3.00)
			//	printf("\n");
    	}
    	int cnt = Program.work(mid, flow);
    	printf("%d\n", int(flow - (r*c-cnt)*mid));
    }
    //Program.close();
    return 0;
}
