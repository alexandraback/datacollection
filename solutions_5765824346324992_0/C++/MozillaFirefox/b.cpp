#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string.h>

int Tcases, B, N;
int *barbers;
long long curLCM, bperlcm;

using namespace std;

long long gcd(long long a, long long b)
{
	while (b != 0)
	{
		long long temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

long long lcm(long long a, long long b)
{
	long long temp = b / gcd (a, b);
	return abs(temp * a);
}

long long findgcd()
{
	long long result = barbers[0];

	for (int i=1; i<B; i++)
		result = gcd(result, barbers[i]);

	return result;
}

long long findlcm()
{
	long long result = barbers[0];

	for (int i=1; i<B; i++)
		result = lcm(result, barbers[i]);

	return result;
}

long long barbersperlcm()
{
	int cur = 0;

	for (int i=1; i<=curLCM; i++)
	{
		for(int j=0; j<B; j++)
			if (i % barbers[j] == 0 && i >= barbers[j])
				cur++;
	}

	return cur;
}

int getBarber(int ind)
{
	int curbarber = 0;

	//index is normalized.
	for(int i=1; i<=curLCM; i++)
	{
		for(int j=0; j<B; j++)
		{
			if (i % barbers[j] == 0 && i >= barbers[j])
				curbarber++;

			if (ind == curbarber) return j+1;
		}
	}
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("small.out", "w", stdout);

	scanf("%d", &Tcases);

	for(int i=0; i<Tcases; i++)
	{
		scanf("%d %d", &B, &N);
		barbers = new int[B];

		for (int i=0; i<B; i++)
			scanf("%d", &barbers[i]);

		if (N <= B)
		{
			printf("Case #%d: %d\n",i + 1, N);
			delete[] barbers;
			continue;
		}

		curLCM = findlcm();
		bperlcm = barbersperlcm();

		N -= B;
		if (N > bperlcm) N = N % bperlcm;
		if (N == 0) N = bperlcm;

		printf("Case #%d: %d\n",i+1, getBarber(N));

		delete [] barbers;
	}
		
	return 0;
}