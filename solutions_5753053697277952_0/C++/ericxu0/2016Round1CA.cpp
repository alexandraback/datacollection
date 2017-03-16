#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <complex>
#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int T, N;
pair<int, char> A[26];

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	ios::sync_with_stdio(0);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> A[i].first;
			A[i].second = 'A' + i;
		}

		sort(A, A + N);
		cout << "Case #" << t << ": ";
		string ans = "";
		for (int i = A[N - 1].first; i > A[N - 2].first; i--)
			ans = ans + A[N - 1].second + " ";
		for (int i = 0; i < N - 2; i++)
			for (int j = 0; j < A[i].first; j++)
				ans = ans + A[i].second + " ";
		for (int i = 0; i < A[N - 2].first; i++)
			ans = ans + A[N - 2].second + A[N - 1].second + " ";
		
		for (int i = 0; i < ans.size() - 1; i++)
			cout << ans[i];
		cout << "\n";
	}

	return 0;
}