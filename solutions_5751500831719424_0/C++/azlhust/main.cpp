#include <map>
#include <set>
#include <queue>
#include <ctime>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define all(a) a.begin(),a.end()
#define clr(a) memset(a,0,sizeof(a))
#define fill(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VII;

const double eps = 1e-8;
const double pi = acos(-1.0);
const int N = 105;

int n;
int len[N], st[N];
char s[N][N];
vector<int> all;
int solve(){
	int i, j, p, tot=0;
	for(i=1;i<=n;++i){
		len[i] = strlen(s[i]);
		st[i] = 0;
	}
	for(i=0;i<len[1]; i=st[1]){
		int mark = s[1][i];
		all.clear();
		for(p=1;p<=n;++p){
			if(st[p]==len[p] || s[p][st[p]]!=mark) return -1;
			for(j=st[p];j<len[p]&&s[p][j]==mark;++j);
			all.pb(j-st[p]);
			st[p] = j;
		}
		sort(all.begin(), all.end());
		int mid = all[all.size()/2];
		for(p=0;p<all.size();++p)
		tot += all[p]>mid?(all[p]-mid):(mid-all[p]);
	}
	for(i=2;i<=n;++i) if(st[i]!=len[i]) return -1;

	return tot;
}

int main(){
	freopen("A.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tt, i;
	scanf("%d",&tt);
	for(int cas = 1; cas <= tt; ++cas){
		printf("Case #%d: ", cas);
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%s",s[i]);
		int ans = solve();
		if(ans==-1) puts("Fegla Won");
		else printf("%d\n", ans);
	}
    return 0;
}

