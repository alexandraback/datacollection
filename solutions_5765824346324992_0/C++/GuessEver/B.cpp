#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
using std::vector;
using std::pair;
using std::make_pair;
using std::priority_queue;

const int N = 1000 + 10;

typedef pair<long long, int> pr;
priority_queue<pr, vector<pr>, std::greater<pr> > Q;
int n, m, a[N];

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}
long long lcm(long long a, int b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d", &n, &m);
		while(!Q.empty()) Q.pop();
		long long cycle = 1, minp = -1;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if(minp == -1 || a[i] < minp) minp = a[i];
			cycle = lcm(cycle, a[i]);
		}
		long long cyclep = 0;
		for(int i = 0; i < n; i++) cyclep += cycle / a[i];
		m %= cyclep; if(!m) m = cyclep;
		for(int i = 0; i < n; i++) Q.push(make_pair(0, i));
		for(int i = 0; i < m-1; i++)
		{
			pr now = Q.top(); Q.pop();
			now.first += a[now.second];
			Q.push(now);
		}
		printf("Case #%d: %d\n", cas, Q.top().second + 1);
	}
	return 0;
}
