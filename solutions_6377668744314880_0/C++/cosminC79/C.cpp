#include <stdio.h>
#include <algorithm>
#include <cstring>
#define pdd pair <double,double>
#define x first
#define y second
#define NMAX 18
#define bit(x) (1 << (x - 1))
#define has_bit(mask, x) (mask & bit(x))
#define eps 1e-6
using namespace std;
int n, r, best[NMAX];
pdd B[NMAX];
int st[NMAX], A[NMAX];

int tests, m;
bool mark[NMAX];

bool comp(int a, int b)
{
    if (B[a].y<B[b].y)
        return 1;
    if (B[a].y>B[b].y)
        return 0;
    if (B[a].x<B[b].x)
        return 1;
    return 0;
}

inline int semn(pdd a,pdd b,pdd c)
{
    double A=a.y-b.y;
    double B=b.x-a.x;
    double C=a.x*b.y-b.x*a.y;
    return (A*c.x+B*c.y+C)<-eps;
}

inline int on_line(pdd a,pdd b,pdd c)
{
	double A=a.y-b.y;
    double B=b.x-a.x;
    double C=a.x*b.y-b.x*a.y;
    return abs(A*c.x+B*c.y+C)<eps;
}

void solve()
{
	r = 0;
	
    int i;
    st[++r]=1; st[++r]=2;
    for (i=3; i<=n; i++)
    {
        while (r>=2 && semn(B[A[st[r-1]]],B[A[st[r]]],B[A[i]])) r--;
        st[++r]=i;
    }
    for (i=n-1; i>=1; i--)
    {
       while (r>=2 && semn(B[A[st[r-1]]],B[A[st[r]]],B[A[i]])) r--;
       st[++r]=i;
    }
    //~ printf("%d\n",r);
    //~ for (i=1; i<=r; i++)
        //~ printf("%lf %lf\n",st[i].x,st[i].y);
}

inline int nbits(int x)
{
	int res = 0;
	while (x)
	{
		res++;
		x = x & (x - 1);
	}
	
	return res;
}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    
    scanf("%d", &tests);
	for (int test_no = 1; test_no <= tests; test_no++)
	{
		printf("Case #%d:\n", test_no);
		
		scanf("%d", &m);
		for (int i = 1; i <= m; i++)
			scanf("%lf%lf", &B[i].x, &B[i].y);
		
		for (int i = 1; i <= m; i++)
			best[i] = m - 1;
		for (int i = 1; i < (1 << m); i++)
			if (nbits(i) >= 2)
			{
				n = 0;
				for (int j = 1; j <= m; j++)
					if (has_bit(i, j))
						A[++n] = j;
				sort(A + 1, A + n + 1, comp);
				
				solve();
				memset(mark, false, sizeof(mark));
				for (int j = 1; j < r; j++)
				{
					mark[A[st[j]]] = true;
				}
				
				for (int j = 1; j <= n; j++)
					if (!mark[A[j]])
					{
						for (int k = 1; k < r; k++)
							if (on_line(B[A[st[k]]], B[A[st[k + 1]]], B[A[j]]))
							{
								mark[A[j]] = true;
								break ;
							}
					}
					
				for (int j = 1; j <= m; j++)
					if (mark[j])
						best[j] = min(best[j], m - nbits(i));
			}
		for (int i = 1; i <= m; i++)
			printf("%d\n", best[i]);
	}
    return 0;
}
