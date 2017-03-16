#include<bits/stdc++.h>
using namespace std;

long long int xxx[1 << 18];
long long int j, zz, N;

long long int compute(long long int i)
{
	long long int ans = 0;
	for (long long int k = 0; k < j; k++)
	{
		for (long long int v = 0; v < zz; v++)
		{
			if (v > 0 and (i & (1 << (k * zz + v))) and (i & (1 << (k * zz + v - 1))))
				ans++;
			if (k > 0 and (i & (1 << (k * zz + v))) and (i & (1 << (k * zz + v - zz))))
				ans++;
		}
	}
	return ans;
}

int main()
{
    freopen("input.txt" , "r" , stdin) ;
    freopen("ans.txt","w",stdout);
	long long int T;
	cin >> T;
   long long int t=1;
    while(T--)
    {
		cin >> j >> zz >> N;

		long long int ssss = j * zz * N * 100;

		for (long long int i = 1; i < (1 << (j * zz)); i++)
		{
			xxx[i] = xxx[i - (i & -i)] + 1;

			if (xxx[i] == N)
            ssss = min(ssss, compute(i));
		}

		printf("Case #%lld: %lld\n", t++, ssss);
	}

	return 0;
}
