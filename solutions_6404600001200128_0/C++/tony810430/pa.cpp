#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
#include <stack>
#include <string>

using namespace std;

int T;
int N;
int M[1005];
int cas;
int res1, res2;

int main()
{
	scanf(" %d", &T);

	for (cas = 1; cas <= T; cas++) {
		scanf(" %d", &N);
		
		res1 = res2 = 0;
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			scanf(" %d", &M[i]);
			if (i > 0) {
				res1 += max(M[i-1] - M[i], 0);
				tmp = max(tmp, M[i-1] - M[i]);
			}
		}

		for (int i = 0; i < N-1; i++) {
			res2 += min(tmp, M[i]);
		}

		printf("Case #%d: %d %d\n", cas, res1, res2);
	}

	return 0;
}