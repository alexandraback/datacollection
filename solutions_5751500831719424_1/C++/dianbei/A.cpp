//============================================================================
// Name        : A.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

const int inf = 1 << 29;
#define mod 1000000007
#define N 100010

char str[110][110];
vector<pair<char, int> > a[110];

void solve(int k) {
	char ch = str[k][0];
	int cnt = 1;
	a[k].clear();
	for (int i = 1; str[k][i]; i++) {
		if (str[k][i] == ch) {
			cnt++;
		} else {
			a[k].push_back(make_pair(ch, cnt));
			ch = str[k][i];
			cnt = 1;
		}
	}
	a[k].push_back(make_pair(ch, cnt));
}

int check(int n) {
	int t = a[0].size();
	for (int i = 1; i < n; i++) {
		if (a[i].size() != t)
			return -1;
		for(int j=0;j<a[i].size();j++)
			if(a[i][j].first!=a[0][j].first) return -1;
	}
	int ans=0;
	for(int i=0;i<t;i++){
		int tt=1<<29;
		for(int j=0;j<n;j++){
			int s=0;
			for(int k=0;k<n;k++){
				s+=abs(a[k][i].second-a[j][i].second);
			}
			tt=min(tt,s);
		}
		ans+=tt;
	}
	return ans;
}
int main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T, n ,ri=1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", str[i]);
			solve(i);
		}
		int ans=check(n);
		printf("Case #%d: ",ri++);
		if(ans==-1) printf("Fegla Won\n");
		else printf("%d\n",ans);
	}
	return 0;
}
