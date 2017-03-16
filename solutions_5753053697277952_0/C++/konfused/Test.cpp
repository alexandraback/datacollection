#include <cstdio>
int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int TC = 1; TC <= T; ++TC)
	{
		int N;
		scanf("%d", &N);

		int P[26], sum = 0;
		for(int i = 0; i < N; ++i)
		{
			scanf("%d", &P[i]);
			sum += P[i];
		}
		
		printf("Case #%d: ", TC);

		if(sum&1)
		{
			int max = 0, maxIndex = -1;
			for(int i = 0; i < N; ++i)
				if(P[i] > max)
				{
					max = P[i];
					maxIndex = i;
				}
			printf("%c ", 'A'+maxIndex);
			--P[maxIndex];
		}

		while(true)
		{
			int max = 0, maxIndex = -1;
			for(int i = 0; i < N; ++i)
				if(P[i] > max)
				{
					max = P[i];
					maxIndex = i;
				}
			if(0 == max)
				break;
			printf("%c", 'A'+maxIndex);
			--P[maxIndex];

			max = 0, maxIndex = -1;
			for(int i = 0; i < N; ++i)
				if(P[i] > max)
				{
					max = P[i];
					maxIndex = i;
				}
			if(0 == max)
				break;
			--P[maxIndex];
			printf("%c ", 'A'+maxIndex);
		}
		printf("\n");
	}
	
	return 0;
}
