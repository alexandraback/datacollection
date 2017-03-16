#include <vector>
#include <cstdio>

using namespace std;

#define FOR(v,lim) for(int v = 0; v < lim ; ++ v )

int vx[3010];
int vy[3010];

int main()
{
    int t;
    scanf("%d", &t);
    FOR(ti, t)
    {
	int n;
	scanf("%d", &n);
	FOR(j, n)
	{
	    int valx, valy;
	    scanf("%d%d", &valx, &valy);
	    vx[j] = valx;
	    vy[j] = valy;
	}

	printf("Case #%d:\n", ti + 1);
	FOR(i, n)
	{
	    int res = n - 1;
	    FOR(j, n)
	    {
		if(j != i)
		{
		    long long int dx = vx[j] - vx[i];
		    long long int dy = vy[j] - vy[i];
		    int a = 0;
		    int b = 0;
		    FOR(k, n)
		    {
			long long int valu = dx * (vy[k] - vy[i]) - dy * (vx[k] - vx[i]);
			if(valu > 0)
			{
			    ++a;
			}
			else if(valu < 0)
			{
			    ++b;
			}
			if(a >= res && b >= res)
			{
			    break;
			}
		    }
		    if(a < res) res = a;
		    if(b < res) res = b;
		}
	    }
	    printf("%d\n", res);

	}


    }
}
