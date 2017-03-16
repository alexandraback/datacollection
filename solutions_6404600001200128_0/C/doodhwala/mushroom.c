#include<stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	int n;
	int m[100000];
	int cases;
	
	for(cases = 1; cases <= t; ++cases )
	{
		scanf("%d", &n);
		int i;
		
		for(i = 0; i<n; ++i)
			scanf("%d", m+i);
		
		int ctr1 = 0;
		long ctr2 = 0;
		//long sum;
		long largestdiff = 0;
		int temp;
		
		for(i = 1; i < n; ++i)
		{
			temp = (m[i-1] - m[i]);
			if(temp > 0)
				ctr1 += temp;
			if(temp > largestdiff)
				largestdiff = temp;
			//ctr2 += m[i-1];
		}
		
		for(i = 0; i<n-1; ++i)
		{
			if(m[i] < largestdiff)
				ctr2 += m[i];
			else
				ctr2 += largestdiff;
		}
		
		//ctr2 -= m[i-1];
		
		printf("Case #%d: %d %ld\n", cases, ctr1, ctr2);
	}
	
	return 0;
}

