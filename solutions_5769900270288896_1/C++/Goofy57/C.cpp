#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector <int> vi;

#define pb push_back
#define mp make_pair

template <class T> inline T sqr(const T& x) { return x * x; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }

const int maxn = 111; 
int a[100][100]; 
int r, c, k; 

const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}; 

int solve() {
	int n = r * c; 
	int ans = 1000; 

	for (int m = 0; m < (1 << n); m++) {
		int cnt = 0; 
		for (int i = 0; i < n; i++) {
			cnt += (m >> i) & 1; 
		}
		if (cnt != k) continue;
		int cur = 0; 
		for (int i = 0; i < n; i++) {
			int rr = i / c; 
			int cc = i % c; 
			a[rr][cc] = (m >> i) & 1; 
			if (!a[rr][cc]) continue; 
			if (rr && a[rr - 1][cc]) cur++; 
			if (cc && a[rr][cc - 1]) cur++; 
		}
		if (cur < ans) ans = cur; 
	}
	return ans; 
}

int solve3() {
	//if (!(r > 1 && c > 1 && r % 2 && c % 2)) return 1000000000;
	int ans[5] = {0}; 
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if ((i + j) % 2) {
				ans[0]++; 
				continue; 
			}
			int cur = 0; 
			for (int t = 0; t < 4; t++) {
				int nx = i + dx[t]; 
				int ny = j + dy[t]; 
				if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
					cur++; 
				}
			}
			ans[cur]++; 
		}
	}

	int all = 2 * (r - 1) * (c - 1) + r - 1 + c - 1; 
	for (int i = 0; i < r * c - k; i++) {
		for (int t = 4; t >= 0; t--) {
			if (ans[t]) {
				ans[t]--; 
				all -= t; 
				break; 
			}
		}
	}

	return all; 
}

int solve2() {

	int ans[5] = {0}; 
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if ((i + j) % 2 == 0) {
				ans[0]++; 
				continue; 
			}
			int cur = 0; 
			for (int t = 0; t < 4; t++) {
				int nx = i + dx[t]; 
				int ny = j + dy[t]; 
				if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
					cur++; 
				}
			}
			ans[cur]++; 
		}
	}

	int all = 0; 
	for (int i = 0; i < k; i++) {
		for (int t = 0; t < 5; t++) {
			if (ans[t]) {
				ans[t]--; 
				all += t; 
				break; 
			}
		}
	}

	return min(all, solve3()); 
}

void print(int ans) {
	for (int m = 0; m < (1 << (r * c)); m++) {
		int cnt = 0; 
		for (int i = 0; i < r * c; i++) {
			cnt += (m >> i) & 1; 
		}
		if (cnt != k) continue;
		int cur = 0; 
		for (int i = 0; i < r * c; i++) {
			int rr = i / c; 
			int cc = i % c; 
			a[rr][cc] = (m >> i) & 1; 
			if (!a[rr][cc]) continue; 
			if (rr && a[rr - 1][cc]) cur++; 
			if (cc && a[rr][cc - 1]) cur++; 
		}
		if (cur == ans) { 
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					cout << a[i][j]; 
				}
				cout << "\n" ;
			}
			return; 

		}
	}
}

void gen() {
	freopen("input.txt", "w", stdout);
	vi r, c, k; 
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i * j > 25) continue; 
			for (int t = 0; t < i * j; t++) {
				r.pb(i); 
				c.pb(j); 
				k.pb(t); 
			}
		}
	}

	cout << r.size() << "\n"; 
	for (int i = 0; i < r.size(); i++) {
		cout << r[i] << " " << c[i] << " " << k[i] << "\n"; 
	}
}

int main()
{

	//gen();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    // ios::sync_with_stdio(false);

    
	int t; 
	cin >> t;  

	for (int tc = 0; tc < t; tc++) {
		if (tc % 10 == 0)
			cerr << tc << " / " << t << "\n"; 
		cin >> r >> c; 
		cin >> k; 
		cout << "Case #" << tc + 1 << ": " << solve2() << "\n";

		/*if (solve() != solve2()) {
			cerr << "WA\n";
			cout << r << " " << c << " " << k << "\n"; 
			cout << "Case #" << tc + 1 << ": " << solve() << " " << solve2() << "\n";
			print(solve()); 
		}
*/
		//cout << "Case #" << tc + 1 << ": " << solve() << " " << solve2() << "\n"; 
	}

	//cout << clock() * 1.0 / CLOCKS_PER_SEC << "\n"; 

    return 0;
}