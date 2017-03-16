#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;

struct Repeat
{
	Repeat()
		: c(0), count(0)
	{

	}

	Repeat(char c, int count)
		: c(c), count(count)
	{

	}
	
	char c;
	int count;
};

vector<Repeat> makeRepeats(const std::string& str)
{
	vector<Repeat> vec;
	vec.push_back(Repeat(str[0], 1));
	for (int i=1; i<str.size(); ++i)
	{
		if (str[i] == vec.back().c)
		{
			vec.back().count++;
		}
		else
		{
			vec.push_back(Repeat(str[i], 1));
		}
	}
	
	return vec;
}

int run()
{
	int n;
	scanf("%d", &n);

	char strs[100][101];
	for (int i=0; i<n; ++i)
	{
		scanf("%s", strs[i]);
	}

	vector<vector<Repeat>> repeaters;
	for (int i=0; i<n; ++i)
	{
		repeaters.push_back(makeRepeats(strs[i]));
	}

	int size = repeaters.front().size();
	for (auto v : repeaters)
	{
		if (v.size() != size)
		{
			return -1;
		}

		for (int i=0; i<v.size(); ++i)
		{
			if (v[i].c != repeaters.front()[i].c)
			{
				return -1;
			}
		}
	}

	int ans = 0;

	for (int i=0; i<size; ++i)
	{
		int sum = 0;
		for (auto r : repeaters)
		{
			sum += r[i].count;
		}

		int min = 10000;
		for (int j=1; j<=100; ++j)
		{
			int tsum = 0;
			for (auto r : repeaters)
			{
				tsum += std::abs(r[i].count - j);
			}

			if (tsum < min)
			{
				min = tsum;
			}
		}

		ans += min;
	}

	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i=1; i<=t; ++i)
	{
		int ans = run();
		printf("Case #%d: ", i);
		if (ans < 0)
		{
			printf("Fegla Won\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	
	return 0;
}