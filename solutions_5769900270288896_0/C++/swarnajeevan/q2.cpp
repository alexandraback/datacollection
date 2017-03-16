#include<stdio.h>
#include <iostream>
using namespace std;

int cnt[1 << 19];
int nr, nc, nn;

int cmp(int i)
{
	int res = 0;
	for (int r = 0; r < nr; r++)
	{
		for (int c = 0; c < nc; c++)
		{
			if (c > 0 && (i & (1 << (r * nc + c))) && (i & (1 << (r * nc + c - 1))))
				res++;
			if (r > 0 && (i & (1 << (r * nc + c))) && (i & (1 << (r * nc + c - nc))))
				res++;
		}
	}
	return res;
}

int main() 
{
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++)
	{
		scanf("%d %d %d",&nr,&nc,&nn);
		printf("Case #%d: ",t);
		int best = nr * nc * nn * 100;
		for (int i = 1; i < (1 << (nr * nc)); i++)
		{
			cnt[i] = cnt[i - (i & -i)] + 1;
			if (cnt[i] == nn) best = min(best, cmp(i));
		}
		printf("%d\n",best);
	}
	return 0;
}
