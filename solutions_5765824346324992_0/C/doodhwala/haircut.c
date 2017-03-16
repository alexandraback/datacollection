#include<stdio.h>

long lcmOfAll(int *, int);
long lcm(long, long);
long hcf(long, long);

int main()
{
	int t;
	scanf("%d", &t);
	
	int b;
	long n;
	int m[100000];
	int booked[100000];
	int cases;
	
	for(cases = 1; cases <= t; ++cases )
	{
		scanf("%d %ld", &b, &n);
		
		int i;
		
		for(i = 0; i<b; ++i)
		{
			scanf("%d", m + i);
			booked[i] = 0;
		}
		
		long ctr = 0;
		int fb, mi;
		
		long lcm = lcmOfAll(m, b);
		if(lcm < n)
		{
			long sum = 0;
			
			for(i = 0; i<b; ++i)
				sum += lcm/m[i];
			while(n > sum)
			{
				n -= sum;
			}
			//printf("n=%ld sum=%ld\n", n, sum); 
		}
		//printf("n=%ld lcm=%ld\n", n, lcm);
		//n %= lcm;
		
		while(ctr < n)
		{
			fb = findBarber(booked, b);
			if(fb != -1)
			{
				booked[fb] = m[fb];
				++ctr;
			}
			else
			{
				mi = minInt(booked, b);
				nSec(booked, b, mi);
			}
		}
		
		printf("Case #%d: %d\n", cases, fb+1);
	}
	return 0;
}

long lcmOfAll(int * m, int n)
{
	long ans = 1;
	int i;
	for(i = 0; i<n; ++i)
	{
		ans = lcm(ans, m[i]);
	}
	return ans;
}

long lcm(long a, long b)
{
	return a*b/hcf(a,b);
}

long hcf(long a, long b)
{
	int temp;
	while(a % b != 0)
	{
		temp = a%b;
		a = b;
		b = temp;
	}
	return b;
}

int findBarber(int * booked, int n)
{
	int i;
	for(i = 0; i<n; ++i)
		if(booked[i] == 0)
			return i;
	return -1;
}

int nSec(int * booked, int n, int mi)
{
	int i;
	for(i = 0; i<n; ++i)
		if(booked[i] > 0)
			booked[i] -= mi;
}

int minInt(int * booked, int n, int mi)
{
	int i;
	int min = 100000;
	for(i = 0; i<n; ++i)
		if(booked[i] < min)
			min = booked[i];
	return min;
}
