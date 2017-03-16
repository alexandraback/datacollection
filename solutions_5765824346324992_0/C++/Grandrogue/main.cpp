#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ifstream fin("B-small-attempt1.in");
ofstream fout("out.txt");

long long a[1000];
long long n, m;

long long eval(long long time, bool flag) {
	long long ans = 0;
	for(int i = 0; i < m; ++i) {
		ans += time / a[i];
		if(flag && ((time % a[i]) != 0)) ++ans;
	} 
	return ans;
}

int main() {
	int tests;
	fin >> tests;
	for(int test = 0; test < tests; ++test) {
		fin >> m >> n;
		long long ans = 0, maxtime = 0;
		for(int i = 0; i < m; ++i) {
			fin >> a[i];
		}
		maxtime = a[0];
		for(int i = 0; i < m; ++i) {
		    maxtime = min(a[i], maxtime);
		}
		long long r = maxtime * n;
		long long l = 1;
		long long succ = -1;
		while(l < r - 1) {
			long long m = (l + r) / 2;
			long long cur = eval(m, true);
			if(cur >= n) {
				succ = m;
				r = m;
			} else {
				l = m;
			}
		}
		long long cur2 = eval(r, true);
		long long cur = eval(l, true);
		if(cur >= n) succ = l;
		--succ;
		long long ready = eval(succ, true);
		for(int i = 0; i < m; ++i) {
			if(succ % a[i] == 0) {
				++ready;
				if(ready == n) {
					ans = i + 1;
					break;
				}
			}
		}
		fout << "Case #" << test + 1 << ": " << ans << endl;
	}
	return 0;
}
