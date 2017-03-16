// Tapan Sahni
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <iomanip>
#include <map>
#include <complex>
#include <set>

using namespace std;
typedef long long LL;
typedef pair <int, int> PII;

const int N = 2e5 + 10;
const LL mod = 1000000007;

int p[33];
pair <int, int >c[33];
void solve() {
	int t, tNUm = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> p[i];
		int maxx = 0, idx;
		cout << "Case #" << tNUm << ": ";
		while(true) {
			int f = 0;
			for(int i = 0; i < n; i++) 
				c[i] = PII(p[i], i);
			sort(c, c + n);
			if(c[n - 1].first == 0)
				break;
			if(n == 2) {
				char ch = c[n - 1].second + 'A', dh = c[n - 2].second + 'A';
				if(c[n - 1].first == c[n - 2].first) {
					p[c[n - 1].second]--;
					p[c[n - 2].second]--;
					cout << ch << dh <<" ";
					continue;
				}
				else {
					p[c[n - 1].second]--;
					cout << ch << " ";
				}
				continue;	
			}
			if(c[n - 3].first == 0) {
				char ch = c[n - 1].second + 'A', dh = c[n - 2].second + 'A';
				if(c[n - 1].first == c[n - 2].first) {
					p[c[n - 1].second]--;
					p[c[n - 2].second]--;
					cout << ch << dh <<" ";
					continue;
				}
				else {
					p[c[n - 1].second]--;
					cout << ch << " ";
				}
				continue;	
			}
			char ch = c[n - 1].second + 'A';
			p[c[n - 1].second]--;
			cout << ch << " ";
		}
		cout << "\n";
		tNUm++;
	}
	return; 
}
int main() {
    ios::sync_with_stdio(false) ; cin.tie(nullptr);
    solve();
    return  0;
}
// Never Quit