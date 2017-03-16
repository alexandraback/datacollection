#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int MAXN = 3005;

typedef long long LL;

struct Node
{
	int x,y;double angle;
	Node(void){}
	Node(int a,int b) : x(a),y(b){}
}T[MAXN],Na[MAXN];

bool In[MAXN],P[MAXN];
int Ans[MAXN],Q[MAXN],tot,N;

bool cmp(const Node &a,const Node &b) {return a.angle < b.angle;}

bool Cmp(const Node &c,const Node &b,const Node &a)
{
	return LL(b.x - a.x) * (c.y - a.y) - LL(c.x - a.x) * (b.y - a.y) < 0;
}

bool Line(const Node &c,const Node &b,const Node &a)
{
	return LL(b.x - a.x) * (c.y - a.y) - LL(c.x - a.x) * (b.y - a.y) == 0;
}

void Poly(int need)
{
	if (!tot) return;
	int od = 1;
	for(int i = 1;i <= N;i ++) In[i] = 0;
	for(int i = 2;i <= tot;i ++)
	if (Na[i].x < Na[od].x || (Na[i].x == Na[od].x && Na[i].y < Na[od].y)) od = i;
	swap(Na[1],Na[od]);
	for(int i = 2;i <= tot;i ++) Na[i].angle = atan2(Na[i].y - Na[1].y,Na[i].x - Na[1].x);
	sort(Na + 2,Na + tot + 1,cmp);
	int en = 2;Q[1] = 1,Q[2] = 2;
	for(int i = 3;i <= tot;i ++)
	{
		while (en > 1 && Cmp(Na[i],Na[Q[en]],Na[Q[en - 1]])) en --;
		Q[++ en] = i;
	}
	for(int i = 1;i <= en;i ++)
	{
		Node a = Na[Q[i]],b = Na[Q[i % en + 1]];
		for(int j = 1;j <= N;j ++)
		if (Line(a,b,T[j])) In[j] = 1;
	}
	for(int i = 1;i <= N;i ++) if (In[i]) Ans[i] = min(Ans[i],need);
}

void Test()
{
	tot = 0;
	int cut = 0;
	for(int i = 1;i <= N;i ++)
	if (P[i]) Na[++ tot] = T[i]; else cut ++;
	Poly(cut);
}

void Dfs(int Now)
{
	if (Now > N) Test(); else
	{
		P[Now] = 1,Dfs(Now + 1);
		P[Now] = 0,Dfs(Now + 1);
	}
}

void Work(int TestCase)
{
	memset(Ans,60,sizeof Ans);
	scanf("%d", &N);
	for(int i = 1;i <= N;i ++) scanf("%d%d", &T[i].x, &T[i].y);
	Dfs(1);
	printf("Case #%d:\n", TestCase);
	for(int i = 1;i <= N;i ++) printf("%d\n", Ans[i]);
}

int main()
{
	freopen("data.in","r",stdin),freopen("data.out","w",stdout);
	int Ti;
	scanf("%d", &Ti);
	for(int i = 1;i <= Ti;i ++) Work(i);
	return 0;
}

