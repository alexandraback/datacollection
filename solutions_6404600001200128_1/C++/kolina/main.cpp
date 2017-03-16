#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <cstdlib>
#include <queue>
#include <set>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <sstream>
#include <cassert>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		int x = 0;
		for (int i = 0; i + 1 < n; ++i)
			x += max(0, a[i] - a[i + 1]);
		int max_d = 0;
		for (int i = 0; i + 1 < n; ++i)
			max_d = max(max_d, a[i] - a[i + 1]);
		int y = 0;
		for (int i = 0; i + 1 < n; ++i)
			y += min(a[i], max_d);
		cout << "Case #" << t + 1 << ": " << x << " " << y << "\n";
	}
    return 0;
}