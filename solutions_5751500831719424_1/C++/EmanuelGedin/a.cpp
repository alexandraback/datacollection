#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
#define rep(i, a) for(int i = 0; i < (a); i++)
#define foru(i, s, e) for(int i = (s); i < (e); i++)
#define ford(i, s, e) for(int i = (s); i >= (e); i--)
#define cinNewLine cin.ignore(numeric_limits<streamsize>::max(), '\n');
const double EPS = 1e-9;
const int INF = 2147483647;
const LL LLINF = 9223372036854775807LL;
template <class T> T gcd(T a, T b) { if(a < b) swap(a, b); if(b == 0) return a; return gcd(b, a%b); }
template <class T> T lcm(T a, T b) { return (a*b)/gcd(a, b); }

int main() {
	int T;
	cin >> T;
	foru(t, 1, T+1) {
		int n, ans = 0;
		cin >> n;
		vector<string> s(n);
		rep(i, n) cin >> s[i];
		cout << "Case #" << t << ": ";
		bool fail = false;
		VI pt(n, 0);
		while(true) {
			// End of strings?
			bool end = false;
			rep(i, n) {
				if(pt[i] >= s[i].size()) {
					end = true;
					break;
				}
			}
			if(end) rep(i, n) {
				if(pt[i] < s[i].size()) {
					fail = true;
					break;
				}
			}
			if(fail || end) break;
			
			// What is next?
			char c = s[0][pt[0]];
			vector<int> l(n);
			rep(i, n) {
				if(s[i][pt[i]] != c) {
					fail = true;
					break;
				}
				int tmp = 1;
				while(pt[i] + tmp < s[i].size() && s[i][pt[i]+tmp] == c) {
					tmp++;
				}
				pt[i] += tmp;
				l[i] = tmp;
			}
			if(fail) break;
			
			// Calculate new answer
			sort(l.begin(), l.end());
			int med = l[n/2];
			rep(i, n) {
				ans += abs(l[i]-med);
			}
		}
		if(fail) {
			cout << "Fegla Won" << endl;
			continue;
		} else {
			cout << ans << endl;
		}
	}
	return 0;
}

