#include <cstdio>
#include <cstring>
char ch[109][109];
int freq[109][109];

int main()
{
	int T;
	
	freopen("date.in", "r", stdin);
	freopen("date.out", "w", stdout);
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt)
	{
		memset(freq, 0, sizeof(freq));
		int N, sol = 0;
		scanf("%d\n", &N);	
		for (int i = 1; i <= N; ++i)
		{
			char cuv[109];
			scanf("%s\n", cuv);
			for (int j = strlen(cuv) - 1; j >=0; --j)
				if (cuv[j] != cuv[j + 1])
					ch[i][++freq[i][0]] = cuv[j], freq[i][freq[i][0]] = 1;
				else
					++freq[i][freq[i][0]];
		}
		
		for (int i = 2; i <= N; ++i)
			if (freq[i][0] != freq[i-1][0])
				goto LOOSE;
			else
				for (int j = 1; j <= freq[i][0]; ++j)
					if (ch[i][j] != ch[i-1][j])
						goto LOOSE;
		//			else
		//				sol += (freq[i][j] - freq[i-1][j] > 0) ? freq[i][j] - freq[i-1][j] : freq[i-1][j] - freq[i][j];
		for (int j = 1; j <= freq[1][0]; ++j)
		{
			//sort :))
			for (int ii = 1; ii < N; ++ii)
				for (int jj = ii + 1; jj <= N; ++jj)
					if (freq[ii][j] > freq[jj][j])
					{
						int aux = freq[ii][j];
						freq[ii][j] = freq[jj][j];
						freq[jj][j] = aux;
					}
					
			int sumLeft = 0, sumRight = 0, min = 109 * 109 * 109;
			for (int i = 1; i <= N; ++i)
				sumRight += freq[i][j];
					
			for (int i = 1; i <= N; ++i)
			{
				sumRight -= freq[i][j];
				if (sumRight - (N - i) * freq[i][j] + (i-1) * freq[i][j] - sumLeft < min)
					min = sumRight - (N - i) * freq[i][j] + (i-1) * freq[i][j] - sumLeft;
				sumLeft += freq[i][j];
			}
			sol += min;
		}			
			
		printf("Case #%d: %d\n", tt, sol);		
		continue;
		
		LOOSE:
			printf("Case #%d: Fegla Won\n", tt);		
	}
return 0;
}