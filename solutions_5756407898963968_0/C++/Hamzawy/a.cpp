/*
 * a.cpp
 *
 *  Created on: Apr 12, 2014
 *      Author: AhmedHamza
 */

#include<cstdio>
#include<vector>
#include<string.h>
using namespace std;
int cnt[16];
int tc, r, x;
void fun()
{
	scanf("%d", &r);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			scanf("%d", &x);
			if (i + 1 == r)
				cnt[x - 1]++;
		}
	}
}
int main()
{
//	freopen("a.in", "rt", stdin);
	freopen("A-small-attempt1.in", "rt", stdin);
	freopen("A-small-attempt1.txt", "wt", stdout);
	scanf("%d", &tc);
	for (int t = 1; t <= tc; ++t)
	{
		memset(cnt,0,sizeof cnt);
		fun();
		fun();
		vector<int> v;
		for (int i = 0; i < 16; ++i)
			if (cnt[i] == 2)
				v.push_back(i + 1);
		printf("Case #%d: ", t);
		if (v.empty())
			printf("Volunteer cheated!\n");
		else if (v.size() != 1)
			printf("Bad magician!\n");
		else
			printf("%d\n", v.front());
	}
	return 0;
}
