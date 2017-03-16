#include <cstdio>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cases = 0;
	scanf("%d",&cases);
	for(int casenum = 1; casenum <= cases; casenum++) {
		int n,t;
		scanf("%d",&n);
		vector<pair<int, char> > v;
		for(int i=0;i<n;i++) {
			scanf("%d",&t);
			v.push_back(make_pair(t,'A'+i));
		}
		sort(v.rbegin(), v.rend());
		printf("Case #%d: ", casenum);
		while(v[0].first>v[1].first) {
			printf("%c ", v[0].second);
			v[0].first--;
		}
		for(int i=2;i<n;i++) {
			while(v[i].first) {
				printf("%c ", v[i].second);
				v[i].first--;
			}
		}
		for(int i=0;i<v[0].first;i++)printf("%c%c ", v[0].second, v[1].second);
		puts("");
	}
	return 0;
}