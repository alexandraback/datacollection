#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define MAXN 200

char a[MAXN][MAXN];
char c[MAXN];
int x[MAXN];
vector<int> ve[MAXN];

bool gao(char *s) {
	int len = strlen(s);
	int tot = 0, last = 0, i = 0;
	char tmp[MAXN];
	tmp[tot++] = s[0];
	while(i < len) {
		while(s[i] == s[last] && i < len) i ++;
		if(i < len) {
			tmp[tot++] = s[i];
			last = i++;
		}
	}
	tmp[tot] = '\0';
	return strcmp(tmp, c) == 0;
}
int main() {
	int T, n;
	scanf("%d", &T);
	for(int it = 1;it <= T; ++it) {
		scanf("%d", &n);
		printf("Case #%d: ", it);
		for(int i = 0;i < n; ++i) scanf("%s", a[i]);
		int len = strlen(a[0]);
		int tot = 0, last = 0, i = 0;
		c[tot++] = a[0][0];
		while(i < len) {
			while(a[0][i] == a[0][last] && i < len) i ++;
			if(i < len) {
				c[tot++] = a[0][i];
				last = i++;
			}
		}
		c[tot] = '\0';	
		bool ok = 1;
		for(int i = 1;i < n; ++i) {
			if(!gao(a[i])) {
				ok = 0;
				break;
			}
		}
		if(!ok) {
			printf("Fegla Won\n");
		} else {
			for(int i = 0;i < MAXN; ++i)
				ve[i].clear();
			for(int i = 0;i < n; ++i) {
				int len = strlen(a[i]);
				int last = 0;
				for(int j = 1;j < len; ++j) {
					while(a[i][j] == a[i][last] && j < len) j ++;
					ve[i].push_back(j - last);
					last = j;
				}
				if(last < len)ve[i].push_back(len - last);
			}
			int m = (int)ve[0].size();
			int ans = 0;
			for(int i = 0;i < m; ++i) {
				vector<int> tmp;
				for(int j = 0;j < n; ++j) {
					tmp.push_back(ve[j][i]);
				}
				//printf(" m = %d\n", m);
				//for(int j = 0;j < n; ++j) printf("%d ", tmp[j]); puts("");
				sort(tmp.begin(), tmp.end());
				for(int j = 0;j < n; ++j) {
					if(ve[j][i] > tmp[n/2]) 
						ans += ve[j][i] - tmp[n/2];
					else 
						ans += tmp[n/2] - ve[j][i];
				}
			}
			printf("%d\n", ans);
		}
	}
}
