/*************************************************************************
    > File Name: googlea.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年05月03日 星期六 23时55分28秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
template <typename T> inline T Min(T a, T b) {
	return a<b?a:b;
}
template <typename T> inline T Max(T a, T b) {
	return a>b?a:b;
}
template <typename T> inline T Abs(T a) {
	return a>0?a:-a;
}
const int inf = 0x3f3f3f3f;
int Cas = 1, t, n, a[MAXN][MAXN];
string s[MAXN];
string goal;
bool check()
{	
	memset(a, 0, sizeof(a));
	goal.clear();
	for (int i = 0; i < s[1].length(); i ++) {
		if (i == 0) {
			goal += s[1][i];
			a[1][goal.length()] ++;
		} else {
			if (s[1][i] == goal[goal.length() - 1]) {
				a[1][goal.length()] ++;
				continue;
			} else {
				goal += s[1][i];
				a[1][goal.length()] ++;
			}
		}
	}
	for (int i = 2; i <= n; i ++) {
		string tmp;
		for (int j = 0; j < s[i].length(); j ++) {
			if (j == 0) {
				tmp += s[i][j];
				a[i][tmp.length()] ++;
			} else {
				if (s[i][j] == tmp[tmp.length() - 1]) {
					a[i][tmp.length()] ++;
					continue;
				} else {
					tmp += s[i][j];
					a[i][tmp.length()] ++;
				}
			}
		}
		if (goal != tmp) return false;
	}
	return true;
}
void work()
{
	printf("Case #%d: ", Cas ++);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
	}
	if (check()) {
		int ans = 0;
		for (int i = 1; i <= goal.length(); i ++) {
			int now = inf;
			for (int j = 1; j <= 100; j ++) {
				int tmp = 0;
				for (int k = 1; k <= n; k ++) {
					tmp += Abs(a[k][i] - j);
				}
				now = Min(now, tmp);
			}
			ans += now;
		}
		printf("%d\n", ans);
	} else {
		printf("Fegla Won\n");
	}
}
int main()
{
	//freopen("in", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		work();
	}
	return 0;
}
