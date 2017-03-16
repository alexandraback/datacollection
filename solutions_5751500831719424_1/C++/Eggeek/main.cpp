#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 111
struct node {
	int t;
	char c;
};node v[maxn][maxn];
int n,cnt[maxn];

void process(char* s,int id) {
	int sum=0;
	while (*s) {
		if (sum==0) sum++;
		else {
			if (*s == *(s-1)) sum++;
			else {
				v[id][cnt[id]++] = (node){sum,*(s-1)};
				sum = 1;
			}
		}
		s++;
	}
	v[id][cnt[id]++] = (node){sum,*(s-1)};
}

void work() {
	scanf("%d",&n);
	memset(v,0,sizeof(v));
	memset(cnt,0,sizeof(cnt));
	char s[maxn];
	for (int i=0; i<n; i++ ) {
		scanf("%s",s);
		process(s,i);
//		printf("%s\n",s);
//		for (int j=0; j<cnt[i]; j++ ) printf("%d %c\n",v[i][j].t,v[i][j].c);
	}

	for (int i=0; i<n; i++ ) if (cnt[i] != cnt[0]) {
		printf("Fegla Won\n");
		return;
	}
	for (int i=0; i<cnt[0]; i++ ) {
		for (int j=0; j<n; j++ ) if (v[j][i].c != v[0][i].c) {
			printf("Fegla Won\n");
			return;
		}
	}
	int ans=0;
	for (int i=0; i<cnt[0]; i++ ) {
		vector<int> x;
		x.clear();
		for (int j=0; j<n; j++) x.push_back(v[j][i].t);
		sort(x.begin(),x.end());
		int t = x[x.size()/2];
		for (int j=0; j<n; j++ ) ans += abs(v[j][i].t-t);
	}
	printf("%d\n",ans);
}

int main() {

	int cas;
	freopen("test.txt","r",stdin);
	freopen("ans.txt","w",stdout);
	scanf("%d",&cas);
	for (int t=1; t<=cas; t++ ) {
		printf("Case #%d: ",t);
		work();
	}
	return 0;
}
