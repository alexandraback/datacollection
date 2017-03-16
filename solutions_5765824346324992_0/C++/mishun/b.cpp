#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>

long long countStarted(const std::vector<int> & a, long long time)
{
	if(time <= 0)
		return 0;

	long long r = 0;		
	for(int i = 0; i < (int)a.size(); i++)
	{
		r += time / a[i];
		if(time % a[i] != 0)
			r++;
	}
		
	return r;
}

int solve(const std::vector<int> & a, long long n)
{
	//long long r = 0;
	//while(countStarted(a, r) < n)
	//	r++;
	//long long l = r - 1;
	
	long long l = 0LL, r = 1000000000000000000LL;
	while(r - l > 1)
	{
		long long m = (r + l) / 2;
		if(countStarted(a, m) < n)
			l = m;
		else
			r = m;
	}

	n -= countStarted(a, l);
	for(int i = 0; i < (int)a.size(); i++)
		if(l % a[i] == 0)
		{
			if(n == 1)
				return i;
			n--;
		}

	assert(false);
	return -1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	
	int tests;
	scanf("%i\n", &tests);
	for(int test = 1; test <= tests; test++)
	{
		long long n;
		int b;
		scanf("%i %lli", &b, &n);
		
		std::vector<int> t;
		for(int i = 0; i < b; i++)
		{
			int tmp;
			scanf("%i", &tmp);
			t.push_back(tmp);
		}
		
		printf("Case #%i: %i\n", test, solve(t, n) + 1);
	}
	
	return 0;
}

