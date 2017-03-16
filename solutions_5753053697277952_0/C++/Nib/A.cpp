#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int tt = 1;tt <= t;tt++) {
	printf("Case #%d: ", tt);
	int n, A;
	scanf("%d", &n);
	priority_queue<pair<int, int>> pq;
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &A);
		pq.push({A, i});
	}

	while(int(pq.size()) > 2)
	{
		pair<int, int> t1 = pq.top();
		pq.pop();
		printf("%c ", t1.second+'A');
		if(t1.first > 1) pq.push({t1.first-1, t1.second});
	}

	while(!pq.empty())
	{
		pair<int, int> t1 = pq.top();
		pq.pop();
		pair<int, int> t2 = pq.top();
		pq.pop();
		if(t1.first > t2.first)
		{
			printf("%c ", t1.second+'A');
			if(t1.first > 1) pq.push({t1.first-1, t1.second});
			pq.push(t2);
		}
		else
		{
			printf("%c%c ", t1.second+'A', t2.second+'A');
			if(t1.first > 1)
			{
				pq.push({t1.first-1, t1.second});
				pq.push({t2.first-1, t2.second});
			}
		}
	}
	printf("\n"); }
}