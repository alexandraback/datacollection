#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

int b, n;
vector<int> mk;

long long search(long long t)
{
	long long people = 0;
	for (int i = 0; i < mk.size(); i++)
	{
		people += t / mk[i];
	}
	return people;
}

void testCase()
{
	scanf("%d%d", &b, &n);

	mk = vector<int>(b);
	for (int i = 0; i < b; i++)
	{
		scanf("%d", &mk[i]);
	}

	if (b >= n)
	{
		printf("%d", n);
		return;
	}
	n -= b;

	long long target = 0;

	long long left = 0, right = numeric_limits<long long>::max() / 3;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		auto result = search(mid);

		if (result < n)
		{
			target = max(target, mid);
			left = mid + 1;
		}
		if (result >= n)
		{
			right = mid - 1;
		}
	}

	priority_queue<pair<long long, int>, vector<pair<long long, int>>,
		greater<pair<long long, int>>> pq;

	for (int i = 0; i < b; i++)
	{
		long long prevCount = target / mk[i];
		n -= prevCount;
		long long next = mk[i] * (prevCount + 1);
		pq.push({next, i});
	}

	for (int i = 0; i < n; i++)
	{
		auto top = pq.top();
		if (i == n - 1)
		{
			printf("%d", top.second + 1);
			return;
		}
		pq.pop();
		pq.push({ top.first + mk[top.second], top.second });
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		testCase();
		printf("\n");
	}

	return 0;
}