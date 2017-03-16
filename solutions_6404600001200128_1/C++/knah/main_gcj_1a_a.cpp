//compiler: MSVC 2010 (C++ obviously)
//one template to rule them all

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>

typedef unsigned long long ull;
typedef long long ll;

#define FN "gcj_a"

using namespace std;

int ms[1000];
int main() {
	//freopen("in.in", "r", stdin);
    //freopen("in.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream in(FN ".in");
	ofstream out(FN ".out");

	int t;
	in >> t;
	for(int tt = 0; tt < t; tt++) {
		int n;
		in >> n;
		int maxdiff = 0;
		int sum = 0;
		int longsum = 0;
		for(int i = 0; i < n; i++) {
			in >> ms[i];
			if(i > 0) {
				if(ms[i - 1] > ms[i]) {
					sum += ms[i - 1] - ms[i];
					maxdiff = max(ms[i - 1] - ms[i], maxdiff);
				}
			}
		}
		for(int i = 0; i < n - 1; i++) {
			if(ms[i] > maxdiff) {
				longsum += maxdiff;
			} else {
				longsum += ms[i];
			}
		}
		out << "Case #" << tt + 1 << ": " << sum << " " << longsum << "\n";
	}


	return 0;
}