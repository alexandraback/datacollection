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

int N;
int X[4000], Y[4000];
int best[4000];

int compare(int a, int b, int c)
{
	// Compare vectors ab and ac
	long long int e1 = X[b]-X[a];
	long long int e2 = Y[b]-Y[a];

	long long int f1 = X[c]-X[a];
	long long int f2 = Y[c]-Y[a];

	long long int res = e1*f2-e2*f1;
	if(res == 0) return 0;
	else if(res < 0) return 1;
	else return 2;
}

int main()
{
	int T;

	scanf("%d\n", &T);

	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d:\n", t);

		scanf("%d", &N);

		for(int i = 0; i < N; i++)
		{
			scanf("%d %d\n", &X[i], &Y[i]);
			best[i] = 10000;
		}

		for(int i = 0; i < N; i++)
		{
			for(int j = i+1; j < N; j++)
			{
				int compteur[3];
				compteur[0] = 0;
				compteur[1] = 0;
				compteur[2] = 0;
				for(int k = 0; k < N; k++)
				{
					compteur[compare(i, j, k)]++;
				}
				best[i] = min(best[i], min(compteur[1], compteur[2]));
				best[j] = min(best[j], min(compteur[1], compteur[2]));
			}
		}

		if(N == 1) best[0] = 0;

		for(int i = 0; i < N; i++) printf("%d\n", best[i]);

	}

	return 0;
}
