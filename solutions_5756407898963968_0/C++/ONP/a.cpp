#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi = acos(-1.);
const double eps = 1e-6;

int T, r1, a[10][10], b[10][10], r2;
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int ca = 0;
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &r1);
		r1--;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				scanf("%d", &a[i][j]);
		scanf("%d", &r2);
		r2--;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				scanf("%d", &b[i][j]);
		int ans = 0, now = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (a[r1][i] == b[r2][j])
					ans++, now = b[r2][j];
		printf("Case #%d: ", ++ca);
		if (ans == 0) {
			puts("Volunteer cheated!");
		} else if (ans > 1) puts("Bad magician!");
		else printf("%d\n", now);
	}
}
