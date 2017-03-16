#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second

void solve(){
	int p[17] = {0};
	int x[4], r;
	for (int t = 0; t < 2; t ++){
	scanf("%d", &r);
	for (int i = 0; i < 4; i ++) {
		for (int j = 0; j < 4; j ++) scanf("%d", x + j);
		if (i == r - 1) {
			for (int j = 0; j < 4; j ++) p[x[j]] ++;
		}
	}
	}
	int cnt = 0, a = 0;
	for (int i = 1; i <= 16; i ++){
		if (p[i] == 2) cnt ++, a = i;
	}
	if (cnt > 1) printf("Bad magician!\n");
	else if (cnt == 0) printf("Volunteer cheated!\n");
	else printf("%d\n", a);
}

int main() {
	#ifdef _TEST_
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i ++) printf("Case #%d: ", i + 1), solve();

	return 0;
}
