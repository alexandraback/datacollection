#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

long long int B;
long long int M[1005];
long long int N;

long long int howmany(long long int x) // At minute x : how many clients have been on a chair? People sit at minute + epsilon sec
{
	long long int result = 0;
	for(int i = 0; i < B; i++)
	{
		result += 1+x/M[i];
	}

	return result;
}


int main()
{
	int T;

	scanf("%d\n", &T);

	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d: ", t);

		scanf("%lld %lld\n", &B, &N);

		for(int i = 0; i < B; i++)
		{
			scanf("%lld", &M[i]);
		}

		long long int a = 0;
		long long int b = (long long int)200000 * N;

		long long int c;
		long long int test;

		while(a < b)
		{
			c = (a+b)/2;
			fprintf(stderr, "[%lld %lld] : %lld\n", a, b, c);
			test = howmany(c);
			if(test < N) a = c+1;
			else b = c;
		}

		// b is such that we are >= N and b-1 is such that we are < N.

		long long int s = howmany(b-1);
		long long int u = howmany(b);

		fprintf(stderr, "%lld : %lld, %lld = %lld\n", b-1, s, b, u);
		long long int diff = N-s;
		long long int encours = 0;
		long long int ans = -1;

		for(int i = 0; i < B; i++)
		{
			if(b % M[i] == 0)
			{
				encours++;
				if(encours == diff) ans = (i+1);
			}
		}

		printf("%lld\n", ans);

	}

	return 0;
}
