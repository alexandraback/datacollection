#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int occ[50];
int n;

void solve()
{
	priority_queue<pair<int, int> > pq;
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", occ+i);
		pq.emplace(occ[i], i);
	}
	while (!pq.empty())
	{
		auto u(pq.top()); pq.pop();
		if (u.first == 1)
		{
			pq.push(u);
			break;
		}
		if (pq.empty() || pq.top().first != u.first)
		{
			printf(" %c", u.second+'A');
			u.first--;
			pq.push(u);
		} else
		{
			auto v(pq.top()); pq.pop();
			printf(" %c%c", u.second+'A', v.second+'A');
			u.first--;
			pq.push(u);
			v.first--;
			pq.push(v);
		}
	}
	if (pq.size()%2 == 1)
	{
		printf(" %c", pq.top().second+'A');
		pq.pop();
	}
	while (!pq.empty())
	{
		auto u(pq.top()); pq.pop();
		auto v(pq.top()); pq.pop();
		printf(" %c%c", u.second+'A', v.second+'A');
	}
}

int main()
{
	int t; scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		fprintf(stderr, "\tCase #% 3d...", _); fflush(stdout);
		milliseconds start_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

		printf("Case #%d:", _);
		solve();
		printf("\n");

		milliseconds end_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		long long time_used = end_ti.count() - start_ti.count();
		fprintf(stderr, " done\t% 6lldms\n", time_used); fflush(stdout);
	}
	fprintf(stderr, "\n\n\n");
	return 0;
}
