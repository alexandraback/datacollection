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

unsigned int slove_small(const vector<unsigned int>& data,unsigned int n)
{
	n = n - 1;
	size_t size = data.size();
	if(n < size) return n;
	unsigned int lcm = 1;
	for(size_t i = 0;i < size;++i)
	{
		unsigned int g = gcd(lcm,data[i]);
		lcm = lcm*data[i]/g;
	}
	assert(lcm <= 2971600);
	unsigned int cycle_count = 0;
	for(size_t i = 0;i < size;++i)
	{
		cycle_count += lcm/data[i];
	}
	assert(0 != cycle_count);
	unsigned int r = n%cycle_count;
	if(r < size)
	{
		return r;
	}

	typedef std::pair<unsigned int,unsigned int> pair_t;
	deque<pair_t> que;
	for(size_t i = 0;i < size;++i)
	{
		pair_t p(data[i],i);
		que.push_back(p);
	}

	for(unsigned int count = size;;++count)
	{
		pair_t p = que.front();
		if(count == r) return p.second;
		que.pop_front();
		que.push_back(pair_t(p.first+data[p.second],p.second));
	}
	assert(0);
	return (unsigned int)(-1);
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
	//freopen("E:\\R1A_B_\\B-small-attempt0.in","r",stdin);
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