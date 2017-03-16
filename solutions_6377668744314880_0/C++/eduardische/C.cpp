#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define MAXN 3005

using namespace std;

struct coord
{
	long long x, y;
	int times;
};

long long dotProduct (coord a, coord b)
{
	return a.x * b.x + a.y * b.y;
}

long long crossProduct (coord a, coord b)
{
	return a.x * b.y - a.y * b.x;
}

coord getVector (coord a, coord b)
{
	coord res;
	res.x = b.x - a.x;
	res.y = b.y - a.y;
	return res;
}

coord basis;

int getVectorSector (coord a)
{
	if ((a.y > 0) || ((a.y == 0) && (a.x > 0))) return 0;
	else return 1;
}

bool compareVectors (coord a, coord b)
{
	int as = getVectorSector(getVector(basis, a));
	int bs = getVectorSector(getVector(basis, b));
	if (as < bs) return true;
	else if (as > bs) return false;
	else return crossProduct(getVector(basis, a), getVector(basis, b)) > 0;
}

bool lessThan180 (coord a, coord b)
{
	int cross = crossProduct(getVector(basis, a), getVector(basis, b));
	if (cross > 0) return true;
	else if (cross < 0) return false;
	else return dotProduct(getVector(basis, a), getVector(basis, b)) >= 0;
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static coord data[MAXN];
	static coord a[MAXN];
	static coord b[MAXN];
	int ac, bc;
	for (iT = 0; iT < T; iT++)
	{
		printf("Case #%d:\n",iT+1);
		int N;
		scanf("%d",&N);
		int i, j;
		for (i = 0; i < N; i++)
		{
			scanf("%lli %lli",&(data[i].x),&(data[i].y));
		}
		if (N <= 1)
		{
			printf("0\n");
			continue;
		}
		for (i = 0; i < N; i++)
		{
			int res = N-1;
			ac = 0;
			for (j = 0; j < N; j++)
			{
				if (j != i)
				{
					a[ac] = data[j];
					ac++;
				}
			}
			basis = data[i];
			sort(a, a+ac, compareVectors);
			//for (j = 0; j < ac; j++) printf("{%lli %lli} ",a[j].x,a[j].y);
			//printf("\n");
			b[0] = a[0];
			b[0].times = 1;
			bc = 1;
			for (j = 1; j < ac; j++)
			{
				if (compareVectors(b[bc-1], a[j]))
				{
					b[bc] = a[j];
					b[bc].times = 1;
					bc++;
				}
				else
				{
					b[bc-1].times++;
				}
			}
			int pos = 0;
			int sum = b[0].times;
			int next;
			//printf("%d: %d:",i,bc);
			//for (j = 0; j < bc; j++) printf(" %d",b[j].times);
			//printf("\n");
			for (j = 0; j < bc; j++)
			{
				while (1)
				{
					next = (pos+1) % bc;
					if (next == j) break;
					if (!lessThan180(b[j], b[next])) break;
					pos = next;
					sum += b[pos].times;
				}
				int toRemoveA = sum - b[j].times;
				int toRemoveB = ac - sum;
				next = (pos+1) % bc;
				if ((next != j) && (crossProduct(getVector(basis, b[j]), getVector(basis, b[next])) == 0)) toRemoveB -= b[next].times;
				//printf("j = %d; pos = %d; sum = %d; toRemoveA = %d; toRemoveB = %d\n",j,pos,sum,toRemoveA,toRemoveB);
				res = min(res, toRemoveA);
				res = min(res, toRemoveB);
				if (pos == j)
				{
					pos = (pos+1) % bc;
					sum += b[pos].times;
				}
				sum -= b[j].times;
			}
			printf("%d\n",res);
		}
	}
	return 0;
}
