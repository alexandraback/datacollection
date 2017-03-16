#include <cassert>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>

struct Vec
{
	Vec(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
	
	long long x;
	long long y;
	
	Vec operator-(const Vec & that) const
	{
		return Vec(x - that.x, y - that.y);
	}
	
	long long operator^(const Vec & that) const
	{
		return x * that.y - y * that.x;
	}
	
	double arg() const
	{
		return atan2l(y, x);
	}
	
	bool operator<(const Vec & that) const
	{
		double d = that.arg() - this->arg();
		if(fabs(d) >= 1e-5)
			return d > 0.0;
			
		long long cp = (*this) ^ that;
		return cp > 0;
	}
};



int processTree(std::vector<Vec> & p)
{
	std::sort(p.begin(), p.end());
	const int n = (int)p.size();
	
	int result = n;
	int posA = 0, posB = 0, negA = 0, negB = 0;
	for(int base = 0; base < n; base++)
	{
		posA = std::max(posA, base + 1);
		while(posA < base + n && (p[base] ^ p[posA % n]) == 0)
			posA++;
			
		posB = std::max(posB, posA);
		while(posB < base + n && (p[base] ^ p[posB % n]) > 0)
			posB++;

		negA = std::max(negA, posB);
		while(negA < base + n && (p[base] ^ p[negA % n]) == 0)
			negA++;
			
		negB = std::max(negB, negA);
		while(negB < base + n && (p[base] ^ p[negB % n]) < 0)
			negB++;

		result = std::min(result, posB - posA);
		result = std::min(result, negB - negA);
	}
	
	return result;
}


void solve(const std::vector<Vec> & p)
{
	const int n = (int)p.size();
	if(n <= 3)
	{
		for(int i = 0; i < n; i++)
			printf("0\n");
		return;
	}

	for(int i = 0; i < n; i++)
	{
		std::vector<Vec> d;
		for(int j = 0; j < n; j++)
			if(i != j)
				d.push_back(p[j] - p[i]);
				
		printf("%i\n", processTree(d));
	}

/*
	std::vector<int> res(n, n);
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			int l = 0, r = 0;
			
			for(int k = 0; k < n; k++)
			{
				long long cp = (p[j] - p[i]) ^ (p[k] - p[i]);
				if(cp > 0) l++;
				if(cp < 0) r++;
			}
			
			res[i] = std::min(res[i], std::min(l, r));
			res[j] = std::min(res[j], std::min(l, r));
		}

	for(int i = 0; i < n; i++)
		printf("%i\n", res[i]);
*/
}

int main()
{
//	printf("%lf\n", Vec(1, 0).arg());
//	printf("%lf\n", Vec(0, 1).arg());	
//	printf("%lli\n", Vec(1, 0) ^ Vec(0, 1));
//	return 0;

	freopen("input.txt", "r", stdin);
	
	int tests;
	scanf("%i\n", &tests);
	for(int test = 1; test <= tests; test++)
	{
		int n;
		scanf("%i\n", &n);

		std::vector<Vec> p;
		for(int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%i %i\n", &x, &y);
			p.push_back(Vec(x, y));
		}

		printf("Case #%i:\n", test);
		solve(p);
	}
	
	return 0;
}

