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
	long long T;
	cin >> T;
	for (long long t = 0; t < T; ++t) {
		long long b, n;
		cin >> b >> n;
		vector<long long> m(b);
		for (long long i = 0; i < b; ++i)
			cin >> m[i];
		long long st = 0, f = (long long)n * m[0];
		while (f - st > 1) {
			long long mid = (f + st) / 2;
			long long have = 0;
			for (long long i = 0; i < b; ++i)
				have += mid / m[i] + 1;
			long long have_2 = 0;
			if (mid > 0) {
				for (long long i = 0; i < b; ++i)
					have_2 += (mid - 1) / m[i] + 1;
			}
			if (have > n && have_2 >= n)
				f = mid;
			else
				st = mid;
		}
		long long e = 0;
		for (long long i = 0; i < b; ++i)
			e = max(e, st / m[i] * m[i]);
		st = e;
		long long have = 0;
		for (long long i = 0; i < b; ++i)
			have += st / m[i] + 1;
		vector<long long> lasts;
		for (long long i = 0; i < b; ++i) {
			if (!(st % m[i]))
				lasts.push_back(i);
		}
		long long l = lasts.size();
		cout << "Case #" << t + 1 << ": " << lasts[l - 1 - have + n] + 1 << "\n";
	}
    return 0;
}