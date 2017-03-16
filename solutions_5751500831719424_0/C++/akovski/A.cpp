#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second

string s[100];
int n, t, cnt[100];

int f(){
	int res = 100000000;
	for (int i = 0; i < n; i ++) {
		int tmp = 0;
		for (int j = 0; j < n; j ++) tmp += abs(cnt[i] - cnt[j]);
		res = min(res, tmp);
	}
	return res;
}
int solve(){
	string r[100];
	for (int i = 0; i < n; i ++) {
		r[i] = ""; r[i] += s[i][0]; int l = s[i].length();
		for (int j = 1; j < l; j ++) 
			if (s[i][j] != r[i][(int)r[i].length() - 1]) r[i] += s[i][j];
	//	cout << r[i] << endl;
	}
	for (int i = 0; i < n - 1; i ++) if (r[i] != r[i + 1]) return -1;
	vector<int> p[100];
	string c = r[0];
	for (int i = 0; i < n; i ++) {
		int x = 0;
		for (int j = 0; j < c.length(); j ++) 
		{
			int tmp = x;
			while (x < s[i].length() && s[i][x] == c[j]) x ++;
			p[i].pb(x - tmp);
		}
	}
	int res = 0;
	for (int i = 0; i < p[0].size(); i ++) {
		for (int j = 0; j < n; j ++) cnt[j] = p[j][i];
		res += f();
	}
	return res;
}
int main() {
	#ifdef _TEST_
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	cin >> t; 
	for (int i = 0; i < t; i ++) {
		cin >> n;
		for (int j = 0; j < n; j ++) cin >> s[j];
		int res = solve();
		cout << "Case #" << i + 1 << ": ";
		if (res >= 0)
			cout << res << endl;
		else cout << "Fegla Won" << endl;
	}
	return 0;
}
