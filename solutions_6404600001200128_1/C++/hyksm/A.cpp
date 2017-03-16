#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <climits>
#include <cfloat>
#include <memory>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <queue>
#include <complex>
#include <utility>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

const double EPS = 0.0000000001;
const long long int INF = 1000000000;

int N;
int m[5000];

void solve()
{
	int a = 0;
	for (int i = 0; i < N - 1; ++i) {
		a = max(a, m[i] - m[i + 1]);
	}
	
	int res1 = 0, res2 = 0;
	for (int i = 0; i < N - 1; ++i) {
		if (m[i] > m[i + 1]) {
			res1 += m[i] - m[i + 1];
		}
		res2 += min(m[i], a);
	}
	printf("%d %d\n", res1, res2);
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i = 0; i < T; ++i) {
		scanf("%d", &N);
		for (int j = 0; j < N; ++j) {
			scanf("%d", &m[j]);
		}
		printf("Case #%d: ", i+1);
		solve();
	}

	return 0;
}

