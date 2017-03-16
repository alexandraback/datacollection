#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

int main(int argc, char ** argv)
{
	int nt;

	scanf("%d", &nt);

	for (int t = 0; t < nt; t++) {
		int mask = (1<<16)-1;

		for (int rep = 0; rep < 2; rep++) {
			int row;
			scanf("%d", &row), row--;
			for (int y = 0; y < 4; y++) {
				int rowmask = 0;
				for (int x = 0; x < 4; x++) {
					int v;
					scanf("%d", &v), v--;
					rowmask |= 1<<v;
				}
				if (y == row) mask &= rowmask;
			}
		}

		printf("Case #%d: ", t+1);
		if (mask == 0) printf("Volunteer cheated!\n");
		else if (mask != (mask&-mask)) printf("Bad magician!\n");
		else printf("%d\n", __builtin_ctz(mask)+1);
	}

	return 0;
}
