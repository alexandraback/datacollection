//*
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

#define EQ 1e-9

typedef long long ll;

int n;

bool eq(double x, double y)
{
	if(abs(x-y) < EQ) return true;
	return false;
}

struct LIST
{
	int x, y;
	int idx;
	double gap;
	int g;
	bool operator < (const LIST & l) const {
		if(g < l.g) return true;
		else if(g > l.g) return false;
		else
		{
			if(g == 1 || g == 3) return gap > l.gap;
			else if(g == 2) return gap > l.gap;
			else return gap < l.gap;
		}
	}
} a[5000], b[5000];

ll ccw(ll ax, ll ay, ll bx, ll by, ll cx, ll cy)
{
	return (bx-ax)*(cy-ay)-(by-ay)*(cx-ax);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, TT;
	scanf("%d", &TT);
	for(T=0;T<TT;T++)
	{
		int i, j, k;
		scanf("%d", &n);
		for(i=0;i<n;i++) scanf("%d%d", &a[i].x, &a[i].y);
		if(n == 1)
		{
			printf("Case #%d:\n%d\n", T+1, 0);
			continue;
		}
		printf("Case #%d:\n", T+1);
		for(i=0;i<n;i++)
		{
			int rmin=0x7fffffff;
			for(j=0;j<n;j++)
			{
				int plus=0, minus=0;
				if(j == i) continue;
				for(k=0;k<n;k++)
				{
					if(ccw(a[i].x, a[i].y, a[j].x, a[j].y, a[k].x, a[k].y) > 0)
					{
						plus++;
					}
					else if(ccw(a[i].x, a[i].y, a[j].x, a[j].y, a[k].x, a[k].y) < 0) minus++;
				}
				if(rmin > min(plus, minus)) rmin=min(plus, minus);
			}
			printf("%d\n", rmin);
		}

	}
	return 0;
}

//*/