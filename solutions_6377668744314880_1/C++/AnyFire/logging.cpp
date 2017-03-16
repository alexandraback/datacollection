#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 6005;

typedef long double LD;
typedef pair<LD, int> SI;

struct PI
{
	LD x,y; 
	PI(){}
	PI(LD X, LD Y):x(X),y(Y){}
}p[N], g[N];

struct LI
{
	PI p,v;
	LI(){}
	LI(PI P, PI V):p(P),v(V){}
};

LD r;

PI operator+(PI a, PI b){return PI(a.x+b.x, a.y+b.y);}
PI operator-(PI a, PI b){return PI(a.x-b.x, a.y-b.y);}
PI operator*(PI a, PI b){return PI(a.x*b.x - a.y*b.y, a.x*b.y + a.y*b.x);}
PI operator*(PI a, LD b){return PI(a.x*b, a.y*b);}
LD operator^(PI a, PI b){return a.x*b.y - a.y*b.x;}
LD dot(PI a, PI b){return a.x*b.x + a.y*b.y;}

int n;
int a[N], f[N];

SI sor[N];

int centre(int x)
{
	int c(0);
	for(int i=1; i<=n; i++) if(i!=x) g[i] = p[i]-p[x], sor[++c] = SI(atan2(g[i].y, g[i].x), i);
	sort(sor+1, sor+c+1);
	
	for(int i=1; i<=c; i++) f[i] = f[c+i] = sor[i].second;
	
	int ans(c), t(2);
	for(int i=1; i<=c; i++)
	{
		for(; t!=c+i && (g[f[t]]^g[f[i]])<=0; ++t);
		ans=min(ans, c+i-t);
	}
	
	return ans;
}

void work()
{
	scanf("%d", &n);
	for(int i=1, x, y; i<=n; i++) scanf("%d%d", &x, &y), p[i] = PI(x,y);
	for(int i=1; i<=n; i++) printf("%d\n", centre(i));
}

int main()
{
	freopen("logging.in", "r", stdin);
	freopen("logging.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for(int i=1; i<=T; i++) printf("Case #%d:\n", i), work();
	
	return 0;
}
