#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

priority_queue<pii, vector<pii> > heap;
int n, test;

void getnPrint()
{
	pii u = heap.top();
	heap.pop();
	if (u.first > 1)
		heap.push(pii(u.first - 1, u.second));
	printf("%c", u.second + 'A');
}

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		while (!heap.empty())
			heap.pop();
		
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0, x; i < n; ++i)
		{
			scanf("%d", &x);
			heap.push(pii(x, i));
			sum += x;
		}

		printf("Case #%d: ", tt);
		while (sum > 3)
		{
			getnPrint();
			getnPrint();
			printf(" ");
			sum -= 2;
		}

		if (sum == 2)
		{
			getnPrint();
			getnPrint();
		}
		else
		{
			getnPrint();
			printf(" ");
			getnPrint();
			getnPrint();
		}

		printf("\n");
	}
	return 0;
}