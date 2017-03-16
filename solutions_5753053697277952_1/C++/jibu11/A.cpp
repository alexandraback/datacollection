#include <stdio.h>
#include <queue>

using namespace std;

priority_queue <pair <int, int> > pq;
int n, lis[30];

int main()
{
	int t, k;
	scanf("%d", &t);
	for(k = 0; k < t; k++)
	{
		scanf("%d", &n);
		int i, tot = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &lis[i]);
			pq.push(make_pair(lis[i], i));
			tot += lis[i];
		}
		i = 0;
		printf("Case #%d:", k + 1);
		while(!pq.empty())
		{
			i += 2;
			pair <int, int> t1, t2, t3;
			t1 = pq.top();
			pq.pop();
			t2 = pq.top();
			pq.pop();
			if(!pq.empty())
			{
				t3 = pq.top();
				if(t1.first == t2.first && t2.first == t3.first && t3.first == 1 && tot == 3)
				{
					tot--;
					printf(" %c", t1.second + 'A');
					pq.push(make_pair(t2.first, t2.second));
					continue;
				}
			}
			if(t2.first * 2 > tot - 2 || t1.first == 1)
			{
				tot -= 2;
				if(t2.first > 1)
					pq.push(make_pair(t2.first - 1, t2.second));
				if(t1.first > 1)
					pq.push(make_pair(t1.first - 1, t1.second));
				printf(" %c%c", t2.second + 'A', t1.second + 'A');
			}
			else
			{
				tot -= 2;
				pq.push(make_pair(t2.first, t2.second));
				if(t1.first > 2)
					pq.push(make_pair(t1.first - 2, t1.second));
				printf(" %c%c", t1.second + 'A', t1.second + 'A');
			}
		}
		printf("\n");
	}
	return 0;
}
