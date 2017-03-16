#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <functional>
#include <cmath>

using namespace std;

#define INT_INF 987654321
#define LL_INF 987654321987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef queue<int> qi;
typedef stack<int> si;


int T, ans;
vector<pair<int, char>> uone;
int N;
int main(void)
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int test = 1; test <= T; test++)
	{
		scanf("%d", &N);

		printf("Case #%d: ", test);
		uone.clear();
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			int n;
			scanf("%d", &n);
			sum += n;
			uone.push_back(pair<int,char>(n, 'A' + i));
		}
		if (sum % 2)
		{
			sort(uone.begin(), uone.end());
			auto m = uone.back();
			uone.pop_back();
			m.first--;
			printf("%c ", m.second);
			if (m.first != 0)
				uone.push_back(m);
		}
		while (uone.empty() == false)
		{
			sort(uone.begin(), uone.end());
			auto m = uone.back();
			uone.pop_back();
			m.first--;
			printf("%c", m.second);
			if (m.first != 0)
				uone.push_back(m);
			sort(uone.begin(), uone.end());
			m = uone.back();
			uone.pop_back();
			m.first--;
			printf("%c ", m.second);
			if (m.first != 0)
				uone.push_back(m);
		}
		
		putchar('\n');
	}
}