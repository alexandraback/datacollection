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


int main()
{
	int T;
	int N;
	int m[1005];

	scanf("%d\n", &T);

	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d: ", t);

		scanf("%d", &N);

		for(int i = 0; i < N; i++)
		{
			scanf("%d", &m[i]);
		}

		int somme1 = 0;
		int somme2 = 0;
		int maxdesc = 0;
		for(int i = 1; i < N; i++)
		{
			if(m[i] < m[i-1])
			{
				somme1 += m[i-1]-m[i];
				maxdesc = max(maxdesc, m[i-1]-m[i]);
			}
		}

		for(int i = 0; i < N-1; i++)
		{
			somme2 += min(maxdesc, m[i]);
		}

		printf("%d %d\n", somme1, somme2);
	}

	return 0;
}
