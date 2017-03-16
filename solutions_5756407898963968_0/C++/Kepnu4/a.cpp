#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <numeric>

using namespace std;

#define sqr(a) ((a)*(a))
#define two(a) (1 << (a))
#define has(mask, a) ((mask) & two(a) ? 1 : 0)

void load() {
}

void solve(int test) {
	int r1, r2;
	set <int> was;

	cin >> r1;
	r1--;
	
	for (int i = 0;i < 4;i++) {
		for (int j = 0, a;j < 4;j++) {
			scanf ("%d", &a);
			if (i == r1) was.insert (a);
		}
	}

	cin >> r2;
	r2--;

	vector <int> ans;
	for (int i = 0;i < 4;i++) {
		for (int j = 0, a;j < 4;j++) {
			scanf ("%d", &a);
			if (i == r2 && was.count (a) > 0) ans.push_back (a);
		}
	}

	int t = ans.size();
	printf ("Case #%d: ", test);

	if (t == 1) {
		printf ("%d\n", ans[0]);
	} else {
		puts (t == 0 ? "Volunteer cheated!" : "Bad magician!");
	}
}

int main() {
 	freopen ("a.in", "r", stdin);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		load();
 		solve(i);
 	}

 	return 0;
}