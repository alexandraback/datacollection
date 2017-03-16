#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int a[1005];

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int tt, caso = 1;
	scanf("%d", &tt);

	while (tt--)
	{
		int n;
		scanf("%d", &n);
		For(i, 0, n)
			scanf("%d", &a[i]);

		int first = 0, second = 0;
		For(i, 1, n)
			if (a[i] < a[i-1])
				first += a[i-1] - a[i];

		double rate = 0;
		For(i, 1, n)
			if (a[i] < a[i-1])
				rate = max(rate, (a[i-1]-a[i])/10.0);

		//cout << rate << endl;
		For(i, 0, n-1)
			second += min((double)a[i], 10*rate);

		printf("Case #%d: %d %d\n", caso++, first, second);
	}

	return 0;
}