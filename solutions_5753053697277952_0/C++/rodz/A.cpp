#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> ii;

int main()
{
	int T, tcnt = 0;
	scanf("%d", &T);
	while(T--)
	{
		int n, sum = 0;
		scanf("%d", &n);
		priority_queue<ii> q;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			sum += x;
			q.push(mp(x, i));
		}
		
		printf("Case #%d:", ++tcnt);
		while(!q.empty())
		{
			string cur;
			int a = q.top().first, p = q.top().second;
			q.pop();
			a--;
			sum--;
			cur.push_back('A' + p);
			if (a)
				q.push(mp(a, p));
			
			int a2 = q.top().first, p2 = q.top().second;
			if (2*a2 > sum)
			{
				cur.push_back('A' + p2);
				q.pop();
				a2--;
				if (a2)
					q.push(mp(a2, p2));
				sum--;
			}
			cout << " ";
			cout << cur;
		}
		cout << '\n';
	}
	return 0;
}
