// Author : Leo Yu

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int a[1000000];

int main()
{
	//freopen("a.in",

	int T;
	cin >> T;
	for (int _ = 1; _ <= T; ++ _)
	{
		int N;
		cin >> N;
		for (int i = 1; i <= N; ++ i)
		{
			cin >> a[i];
		}
		int A = 0;
		int B = 0;
		for (int i = 1; i < N; ++ i)
			if (a[i] > a[i + 1])
			{
				A += a[i] - a[i + 1];
				B = max(B, a[i] - a[i + 1]);
			}
		LL C = 0;
		for (int i = 1; i < N; ++ i)
		{
			C += min(B, a[i]);
		}
		printf("Case #%d: %d %I64d\n", _, A, C);
	}

	return 0;
}
