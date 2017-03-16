#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long lint;
typedef unsigned long long ull;

const int INF = 1000000000;
const lint LINF = 1000000000000000000ll;
const double eps = 1e-8;

int n;
int p[105];
int pcc;

int half(int diff)
{
	return (pcc - diff) / 2;
}

bool try2()
{
	int h = half(2);

	int max1index = 0, max2index = 1;

	if (p[0] < p[1])
	{
		swap(max1index, max2index);
	}

	for (int i = 2; i < n; i++)
	{
		if (p[i] > p[max1index])
		{
			max2index = max1index;
			max1index = i;
		}
		else if (p[i] > p[max2index])
		{
			max2index = i;
		}
	}

	if (p[max1index] == 0 || p[max2index] == 0)
		return false;

	p[max1index]--;
	p[max2index]--;

	for (int i = 0; i < n; i++)
	{
		if (p[i] > h)
		{
			p[max1index]++;
			p[max2index]++;
			return false;
		}
	}
	
	pcc -= 2;

	printf("%c%c ", (char)(max1index + 'A'), (char)(max2index + 'A'));

	return true;
}

bool try1()
{
	int h = half(1);

	int max1index = 0;

	for (int i = 1; i < n; i++)
	{
		if (p[i] > p[max1index])
		{
			max1index = i;
		}
	}

	if (p[max1index] == 0)
		return false;

	p[max1index]--;

	for (int i = 0; i < n; i++)
	{
		if (p[i] > h)
		{
			p[max1index]++;
			return false;
		}
	}

	pcc -= 1;

	printf("%c ", (char)(max1index + 'A'));

	return true;
}

void solve()
{
	scanf("%d", &n);

	pcc = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		p[i] = a;
		pcc += a;
	}

	while (pcc)
	{
		if (!try2())
		{
			if (!try1())
			{
				printf("FAILED FAILED FAILED FAILED\n");
				return;
			}
		}
	}

	printf("\n");
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tn;
	scanf("%d", &tn);
	for (int i = 0; i < tn; i++)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}

	return 0;
}
