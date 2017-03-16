#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for(int tc=1; tc <= T; tc++)
	{
		int N;
		scanf("%d", &N);

		priority_queue<pair<int, int>> pq;

		int sum = 0;
		vector<int> a(N);
		for(int i=0; i < N; i++)
		{
			scanf("%d", &a[i]);
			pq.push({a[i], -i});
			sum += a[i];
		}

		printf("Case #%d:", tc);
		while(!pq.empty())
		{
			auto pick = pq.top();
			pq.pop();
			putchar(' ');
			putchar(-pick.second + 'A');
			sum--;
			if(pick.first > 1)
				pq.push({pick.first - 1, pick.second});

			if(!pq.empty() && pq.top().first * 2 > sum)
			{
				auto pick = pq.top();
				pq.pop();

				putchar(-pick.second + 'A');
				sum--;
				if(pick.first > 1)
					pq.push({pick.first - 1, pick.second});
			}
		}
		puts("");
	}
	return 0;
}