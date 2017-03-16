#include <iostream>
#include <cstring>
#include <queue>
#include <cstring>
#include <algorithm>
#define rep(i, j, k) for(int i = j; i <= k; i++)

using namespace std;

int n, t, ans[100009], cnt;

struct point
{
	int sum, num;
	bool operator < (const point &fuck) const
	{
		return (sum < fuck.sum || (sum == fuck.sum && num < fuck.num));
	}
};
priority_queue<point>q;

int main ()
{
	//freopen ("1.in", "r", stdin); freopen ("1.out", "w", stdout);
	int ti;
	cin >> ti;
	rep (ff, 1, ti)
	{
		cin >> n;
		rep (i, 1, n)
			scanf ("%d", &t), q.push ((point){t, i});
		point now = q.top ();
		q.pop ();
		now.sum--;
		ans[cnt = 1] = now.num;
		if (now.sum > 0)
			q.push (now);
		while (!q.empty ())
		{
			now = q.top ();
			q.pop ();
			ans[++cnt] = now.num;
			now.sum--;
			if (now.sum > 0)
				q.push (now);
		}
		printf ("Case #%d: ", ff);
		if (n == 2)
		{
			printf ("AB");
			rep (i, 2, t)
				printf (" AB");
			cout << endl;
			continue;
		}
		if (cnt == 2)
		{
			printf ("%c%c\n", 'A' - 1 + ans[1], 'A' - 1 + ans[2]);
			continue;
		}
		printf ("%c", 'A' - 1 + ans[1]);
		rep (i, 2, cnt - 2)
			printf (" %c", 'A' - 1 + ans[i]);
		printf (" %c%c\n", 'A' - 1 + ans[cnt - 1], 'A' - 1 + ans[cnt]);
	}
	return 0;
}
