#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ifstream fin("A-small-attempt0.in");
ofstream fout("out.txt");

int main() {
	int tests;
	fin >> tests;
	int n;
	int a[1000];
	for(int test = 0; test < tests; ++test) {
		fin >> n;
		int ans1 = 0, ans2 = 0;
		for(int i = 0; i < n; i++) {
			fin >> a[i];
		}
		for(int i = 1; i < n; i++) {
			if(a[i] < a[i-1]) {
				ans1 += (a[i - 1] - a[i]);
			}
		}
		for(int i = 0; i < n - 1; i++) {
			ans2 = max(ans2, a[i]);
		}
		int x = 0;
		for(int i = 0; i < n - 1; i++) {
			if(a[i] >= a[i + 1]) {
			    x = max(x, a[i] - a[i + 1]);
			}
		}
		x = min(ans2, x);
		ans2 = 0;
		for(int i = 0; i < n - 1; i++) {
			ans2 += min(a[i], x);
		}
		fout << "Case #" << test + 1 << ": " << ans1 << " " << ans2 << endl;
	}
	return 0;
}
