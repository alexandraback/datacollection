#include <stdio.h>
#include <vector>
#include <deque>
#include <assert.h>
using std::vector;
using std::deque;

unsigned int gcd(unsigned int a,unsigned int b)
{
	if(a > b) return gcd(b,a);
	if(0 == a) return b;
	if(1 == a) return 1;
	return gcd(b%a,a);
}

unsigned int slove_large(const vector<unsigned int>& data,unsigned int n)
{
	static unsigned long long maxminute = 100010;
	static unsigned long long maxn = 1000000010;
	static unsigned long long maxtime = maxn*maxminute;
	static unsigned long long mintime = 0;

	unsigned long long lo = mintime,hi = maxtime;
	for(;;)
	{
		unsigned long long mid = (lo + hi)/2;
		unsigned long long count = 0,free_count = 0;
		vector<bool> free(data.size(),false);
		for(size_t i = 0,size = data.size();i < size;++i)
		{
			count += mid/data[i];
			free[i] = (0 == mid%data[i]);
			free_count += (0 == mid%data[i]);
		}

		if(count >= n)
		{
			hi = mid;continue;
		}
		else if(count + data.size() - free_count >= n)
		{
			hi = mid;continue; 
		}
		else if(count + data.size() < n) 
		{
			lo = mid;continue; 
		}
		// count + data.size() - free_count < n <= count + data.size()
		unsigned long long p = count + data.size() - free_count;
		for(size_t i = 0;i < data.size();++i)
		{
			if(!free[i]) continue;
			++ p;
			if(p == n) return i;
		}
		assert(0);
	}
	assert(0);
	return 0;
}

int main()
{
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int b = 0,n = 0;scanf("%d%d",&b,&n);
		vector<unsigned int> data(b);
		for(unsigned int i = 0;i < b;++i) scanf("%d",&data[i]);

		unsigned int ans = slove_large(data,n) + 1;
		printf("Case #%u: %u\n",iCases,ans);
	}
	return 0;
}