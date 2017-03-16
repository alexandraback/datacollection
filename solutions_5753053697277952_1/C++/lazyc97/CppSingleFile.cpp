#include "bits/stdc++.h"
using namespace std;
#define llong long long
#define long llong

int A[26];
int n, n_test;

void enter()
{
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> A[i];
}

void solve()
{
	int remain = accumulate(A, A + n, 0);
	while (remain > 0)
	{
		cout << " ";

		for (int j = 0; j < 2; ++j)
		{
			int i = max_element(A, A + n) - A;
			--A[i];
			--remain;

			int k = n;
			if (j == 1)
				for (k = 0; k < n; ++k)
					if (A[k] * 2 > remain) { ++A[i]; ++remain; break; }

			if (k == n) cout << char(i + 'A');
		}
	}
}

int main()
{
	cin.rdbuf((new ifstream("test.inp"))->rdbuf());
	cout.rdbuf((new ofstream("test.out"))->rdbuf());

	cin >> n_test;
	for (int i = 1; i <= n_test; ++i)
	{
		cout << "Case #" << i << ":";
		enter();
		solve();
		cout << "\n";
	}
}