#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>

//#include <bits/stdc++.h>

using namespace std;

int A[1003];

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output11.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	for(int test = 1; test<=T; test++)
	{
		printf("Case #%d: ", test);
		
		int N;
		scanf("%d", &N);
		
		for(int i=0; i<N; i++)
			scanf("%d", &A[i]);
		
		int ans1 = 0, max_diff = 0;
		
		for(int i=1; i<N; i++)
		{
			if(A[i]<A[i-1])
			{
				ans1+= A[i-1] - A[i];
				
				if(A[i-1]-A[i]>max_diff)
					max_diff = A[i-1]-A[i];
			}
		}
		
		int ans2 = 0;
		
		for(int i=0; i<N-1; i++)
		{
			if(A[i]<max_diff)
				ans2+= A[i];
			else
				ans2+= max_diff;
		}
		
		printf("%d %d\n", ans1, ans2);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
