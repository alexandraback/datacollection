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

int solve() {
	int r, c; 
	cin >> r >> c; 
	int k; 
	cin >> k; 

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

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    // ios::sync_with_stdio(false);

    
	int t; 
	cin >> t;  

	for (int tc = 0; tc < t; tc++) {
		cout << "Case #" << tc + 1 << ": " << solve() << "\n"; 
	}

    return 0;
}