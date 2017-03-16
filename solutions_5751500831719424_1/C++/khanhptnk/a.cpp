#include <vector>
#include <list>
#include <map>
#include <set>
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
#define BIG 1000000000
#define LL long long
#define MAXN 110
using namespace std;

int ntest;
int n;
string s[MAXN], t[MAXN];
vector<int> c[MAXN];

string reduce(int i) {
	string ans = "";
	int last = 0;
	for (int j = 1; j < s[i].length(); j++)
		if (s[i][j] != s[i][j - 1]) {
			ans += s[i][j - 1];
			//cout << s[i] << ' ' << j - last << endl;
			c[i].push_back(j - last);
			last = j;
		}
	ans += s[i][s[i].length() - 1];
	c[i].push_back((int)s[i].length() - last);
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> ntest;
	for (int test = 1; test <= ntest; test++) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> s[i];
		for (int i = 0; i < n; i++) c[i].clear();
		for (int i = 0; i < n; i++) t[i] = reduce(i);
		int ans = 0;
		for (int i = 0; i < n; i++) 
			if (t[i] != t[0]) {
				printf("Case #%d: Fegla Won\n", test);
				goto next;
			}
		for (int i = 0; i < c[0].size(); i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) sum += c[j][i];
			int avg = sum / n;
			int cur1 = 0;
			for (int j = 0; j < n; j++) cur1 += abs(c[j][i] - avg);
			avg++;
			int cur2 = 0;
			for (int j = 0; j < n; j++) cur2 += abs(c[j][i] - avg);
			ans += min(cur1, cur2);
		}
		printf("Case #%d: %d\n", test, ans);

		next:;
	}
}

