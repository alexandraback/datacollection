#include <cstdio>
#include <algorithm>
#include <vector>

int solve1(const std::vector<int> m)
{
	int r = 0;
	for(int i = 1; i < (int)m.size(); i++)
		r += std::max(m[i - 1] - m[i], 0);
	return r;
}

int solve2(const std::vector<int> m)
{
	if(m.size() < 2)
		return 0;
	
	int rate = 0;
	for(int i = 1; i < (int)m.size(); i++)
		rate = std::max(m[i - 1] - m[i], rate);
		
	int r = 0;
	for(int i = 0; i < (int)m.size() - 1; i++)
		r += std::min(rate, m[i]);
	return r;
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
		
		std::vector<int> m;
		for(int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%i", &tmp);
			m.push_back(tmp);
		}
		
		printf("Case #%i: %i %i\n", test, solve1(m), solve2(m));
	}
	
	return 0;
}

