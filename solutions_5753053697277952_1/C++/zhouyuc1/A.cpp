#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct Party
{
	int id;
	int cnt;
};

Party data[30];

bool cmp(Party A, Party B)
{
	return A.cnt > B.cnt;
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for (int tcase = 1; tcase <= T; ++tcase)
	{
		printf("Case #%d:", tcase);
		int N;
		scanf("%d", &N);
		int i;
		int tot = 0;
		for (i = 0; i < N; ++i)
		{
			int num;
			scanf("%d", &num);
			data[i].id = i;
			data[i].cnt = num;
			tot += num;
		}
		sort(data, data+N, cmp);
		// first = second
		while (data[0].cnt > data[1].cnt)
		{
			if (data[0].cnt - data[1].cnt > 1)
			{
				printf(" %c%c", data[0].id+'A', data[0].id+'A');
				data[0].cnt -= 2;
			}
			else
			{
				printf(" %c", data[0].id+'A');
				data[0].cnt -= 1;
			}
		}
		// evacuate all except 1 and 2
		for (i = 2; i < N; ++i)
		{
			while (data[i].cnt >= 2)
			{
				printf(" %c%c", data[i].id+'A', data[i].id+'A');
				data[i].cnt -= 2;
			}
			if (data[i].cnt > 0)
			{
				printf(" %c", data[i].id+'A');
				data[i].cnt -= 1;
			}
		}
		// now for 1 and 2
		while (data[0].cnt > 0)
		{
			printf(" %c%c", data[0].id+'A', data[1].id+'A');
			data[0].cnt -= 1;
			data[1].cnt -= 1;
		}
		printf("\n");
	}

	return 0;
}
