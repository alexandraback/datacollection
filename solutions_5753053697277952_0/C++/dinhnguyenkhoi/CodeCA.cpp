#include <bits/stdc++.h>

using namespace std;
typedef pair <int , char> pr;

int test;
int n;
int P[50];
pr a[50];

int check(int sum, pr a[50], int n)
	{
		for (int i = 1; i <= n; i++)
			if (a[i].first > sum / 2) return 0;

		return 1;
	}

int main ()
	{
		ios :: sync_with_stdio(false);
		cin.tie(0);

		cin >> test;
		int t = test;

		while (test--)
			{
				cout << "Case #" << t - test << ": ";
				cin >> n;
				int sum = 0;
				for (int i = 1; i <= n; i++) cin >> P[i];
				for (int i = 1; i <= n; i++) sum += P[i];

				for (int i = 1; i <= n; i++)
					{
						a[i].first = P[i];
						a[i].second = i + 'A' - 1;
					}

				while (sum)
					{
						sort(a + 1, a + n + 1);
						a[n].first--; sum--;
						if (check(sum,a,n)) cout << a[n].second << ' ';
							else
						{
							a[n].first--; sum--;
							if (check(sum,a,n)) cout << a[n].second << a[n].second << ' ';
								else
							{
								a[n].first++;
								a[n-1].first--;
								cout << a[n].second << a[n-1].second << ' ';
							}
						}
					}

				cout << "\n";
			}
		return 0;
	}
