#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>

//#include <bits/stdc++.h>

using namespace std;

int R, C;
int X[20][20];

int unhappy()
{
	int ans = 0;
	
	for(int i=0; i<R; i++)
	{
		for(int j=0; j<C; j++)
		{
			if(j+1<C && X[i][j] && X[i][j+1])
				ans++;
			if(i+1<R && X[i][j] && X[i+1][j])
				ans++;
		}
	}
	
	return ans;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output2.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	for(int test = 1; test<=T; test++)
	{
		printf("Case #%d: ", test);
		
		int N;
		scanf("%d %d %d", &R, &C, &N);
		
		int ans = 10007;
		
		for(long long i=0; i<(long long)1<<(R*C); i++)
		{
			int count = 0;
			
			for(int k=0; k<R; k++)
				for(int l=0; l<C; l++)
					X[k][l] = 0;
			
			for(long long j=0; j<(R*C); j++)
			{
				if(i&(long long)1<<j)
				{
					count++;
					X[j/C][j%C] = 1;
				}
				
				if(count==N)
				{
					int x = unhappy();
					
					if(x<ans)
						ans = x;
				}
			}
		}
		
		printf("%d\n", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
