#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;


int T, n, m;
string s[108];
string deal(string s, vector<int> &v)
{
	string ret;
	ret += s[0];
	int cnt = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != s[i - 1]) {
			v.push_back(cnt);
			cnt = 1;
			ret += s[i];
		} else {
			cnt++;
		}
	}
	ret += s[s.length()];
	v.push_back(cnt);
	return ret;
}
int count(vector<int> v[], int x)
{
	vector<int> r;
	for (int i = 1; i <= n; i++) {
		r.push_back(v[i][x]);
	}
	sort(r.begin(), r.end());
	if (n & 1) {
		return r[n >> 1];
	} else {
		return (r[(n - 1)>>1] + r[n>>1])>>1;
	}
}
void work()
{
	set<string> se;
	vector<int> v[108];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	
	for (int i = 1; i <= n; i++) {
		se.insert(deal(s[i], v[i]));
	}
	if (se.size() != 1) {
		puts("Fegla Won");
		return;
	}
	int ans = 0;
	for (int i = 0; i < v[1].size(); i++) {
		int temp = count(v, i);
		for (int j = 1; j <= n; j++) {
			ans += abs(v[j][i] - temp);
		}
	}
	printf("%d\n", ans);
}
int main()
{
    	freopen("A.in", "r", stdin);
    	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		work();
	}
}
