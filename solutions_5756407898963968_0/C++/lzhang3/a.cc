#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int r1, r2;
	scanf("%d", &r1); --r1;
	vector<int> conf1[4];
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			int x; scanf("%d", &x);
			conf1[i].push_back(x);
		}
	scanf("%d", &r2); --r2;
	vector<int> conf2[4];
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			int x; scanf("%d", &x);
			conf2[i].push_back(x);
		}
	auto pos = end(conf1[r1]);
	for (int i = 0; i < 4; ++i)
	{
		auto t = find(begin(conf1[r1]), end(conf1[r1]), conf2[r2][i]);
		if (t != end(conf1[r1]))
		{
			if (pos != end(conf1[r1]))
			{
				printf("Bad magician!\n");
				return;
			}
			else
			{
				pos = t;
			}
		}
	}
	if (pos != end(conf1[r1]))
	{
		printf("%d\n", *pos);
		return;
	}
	printf("Volunteer cheated!\n");
}

int main(void)
{
	int t;  scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		printf("Case #%d: ", i);
		solve();
	}
}