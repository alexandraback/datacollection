#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>

int Tcases, N;
int *input;

using namespace std;

int computeSecond()
{
	int maxRate = 0;
	int eaten = 0;

	for (int i=1; i<N; i++)
	{
		if (input[i] < input[i-1])
		{
			if (input[i-1] - input[i] > maxRate)
				maxRate = input[i-1] - input[i];
		}
	}

	for (int i=0; i<N - 1 ;i++)
	{
		if(input[i] <= maxRate)
		{
			eaten += input[i];
		}
		else
		{
			eaten += maxRate;
		}
	}

	return eaten;
}

int computeFirst()
{
	int eaten = 0;

	for (int i=1; i<N; i++)
	{
		if (input[i] < input[i - 1])
			eaten += input[i - 1] - input[i];	
	}
	return eaten;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("mushrooms.out", "w", stdout);
	
	scanf("%d", &Tcases);

	for(int i=0; i<Tcases; i++)
	{
		scanf("%d", &N);
		input = new int[N];

		for(int i=0; i<N; i++)
			scanf("%d", &input[i]);

		printf("Case #%d: %d %d\n",i+1, computeFirst(), computeSecond());
	
		delete [] input;
	}

	return 0;
}