#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[1024];

void solve()
{
	scanf ("%d", &n);

	int i;
	for(i =0; i <n ; i++)
	{
		scanf ("%d", &a[i]);
	}

	int res0 = 0, res1 = 0;

	int mmax = 0;
	for(i = 1; i < n; i ++)
	{
		if(a[i] < a[i-1])
		{
			res0 += a[i-1] - a[i];
			mmax = max(mmax, a[i-1] - a[i]);
		}
	}

	for(i = 0; i < n-1; i ++)
	{
		res1 += min(mmax, a[i]);
		
	}

	printf("%d %d\n", res0, res1);

}
int main ()
{
	int t;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);solve();
	}
	return 0;
}