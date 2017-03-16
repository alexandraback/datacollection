#include <cstdio>

#define MAXN 1005

#define max(a,b)	((a)>(b)?(a):(b))

int main()
{
	int T, ind = 0;	scanf("%d", &T);
	while(T--)
	{
		int N;	scanf("%d", &N);

		int method1 = 0, method2 = 0;
		int m[MAXN];
		float maior  = -1.0;
		scanf("%d", &m[0]);
		for(int i = 1; i < N; i++)
		{
			scanf("%d", &m[i]);
			if(m[i] <= m[i - 1])
				method1 += m[i - 1] - m[i], maior = max(maior, m[i - 1] - m[i]);
		}

		for(int i = 0; i < N - 1; i++)
		{
			if(m[i] - maior < 0)
				method2 += m[i];
			else
				method2 += maior;
		}
		
		printf("Case #%d: %d %d\n", ++ind, method1, method2);
	}

	return 0;
}
