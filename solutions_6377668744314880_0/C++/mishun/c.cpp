#include <cassert>
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
};


void solve(const std::vector<Vec> & p)
{
	const int n = (int)p.size();
	std::vector<int> res(n, n);
	
	if(n <= 3)
		for(int i = 0; i < n; i++)
			res[i] = 0;

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
}

int main()
{
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

