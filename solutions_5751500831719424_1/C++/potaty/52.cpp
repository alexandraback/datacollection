
#include <set>
#include <map>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <queue>
#include <vector>

using namespace std;



vector<pair<char, int> > v[105];

typedef long long ll;
const int MaxN=1000005;

int check(int n) {
	for (int i=0;i<n;++i) if (v[i].size() != v[0].size()) {
		return -1;
	}
	for (int i=1;i<n;++i)
	for (int j=0;j<v[0].size();++j) {
		if (v[0][j].first != v[i][j].first) return -1;
	}
	int dsb=0;
	for (int k=0;k<v[0].size();++k) {
		int tmd=100000;
		for (int x=1;x<=100;++x) {
			int cnt=0;
			for (int i=0;i<n;++i) cnt += abs(x - v[i][k].second);
			tmd=min(tmd, cnt);
		}
		dsb+=tmd;
	}
	return dsb;
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int cases;scanf("%d", &cases);
	int cas=0;
	while (cases--) {
		int n=0;
		scanf("%d", &n);
		for (int i=0;i<n;++i) {
			v[i].clear();
			string s;cin >> s;	
			for (int k=0;k<s.size();) {
				int j=k;
				for (;j<s.size() && s[k] == s[j];++j);
				v[i].push_back(make_pair(s[k], j - k));
				k=j;
			}
		}
		
		printf("Case #%d: ",++cas);
		int dsb=check(n);
		if (dsb == -1) {
			puts("Fegla Won");
		} else {
			printf("%d\n", dsb);
		}
	}

	
	return 0;
}