#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;

#pragma comment(linker,"/STACK:100000000")

int cnt[20];

void solve(int T)
{
	memset(cnt, 0, sizeof(cnt));
	for (int u = 0; u < 2; ++u)
	{
		int k;
		scanf("%d", &k);
		--k;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
			{
				int x;
				scanf("%d", &x);
				--x;
				if (i == k)
					cnt[x]++;
			}
	}
	vector <int> ans;
	for (int i = 0; i < 16; ++i)
		if (cnt[i] == 2)
			ans.push_back(i + 1);
	printf("Case #%d: ", T);
	if (ans.size() == 0)
		printf("Volunteer cheated!\n");
	else if (ans.size() > 1)
		printf("Bad magician!\n");
	else
		printf("%d\n", ans.back());
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
		solve(i + 1);
	return 0;
}