#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>

//#include <bits/stdc++.h>

using namespace std;

int M[30];
long long calc[30];

long long gcd(long long a, long long b)
{
	if(b==0)
		return a;
	
	return gcd(b, a%b);
}

long long lcm(long long a, long long b)
{
	return a/gcd(a,b)*b;
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
		
		int B;
		long long N;
		
		scanf("%d %lld", &B, &N);
		
		for(int i=0; i<B; i++)
			scanf("%d", &M[i]);
		
		long long periodx = 1;
		
		for(int i=0; i<B; i++)
			periodx = lcm(periodx, M[i]);
		
		long long period_count = 0;
		
		for(int i=0; i<B; i++)
			period_count+= periodx/M[i];
		
		N = N%period_count + period_count;
		
		int ans = 0;
		memset(calc, 0, sizeof(calc));
		
		for(int i=0; i<N; i++)
		{
			int indx;
			long long minn = 1000000000000000000LL;
			
			for(int j=0; j<B; j++)
			{
				if(calc[j]<minn)
				{
					minn = calc[j];
					indx = j;
				}
			}
			
			ans = indx;
			calc[ans]+= M[ans];
		}
		
		printf("%d\n", ans+1);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
