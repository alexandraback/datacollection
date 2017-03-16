#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
	//freopen("E:\\ipt.txt", "r", stdin);
#define INF 0x3f3f3f3f
#define LL long long
#define mxn 105
#define mxe 300005

char s[mxn][mxn], rec[mxn];
int cnt[mxn][mxn];

int main(){
	freopen("E:\\A-large.in", "r", stdin);
	freopen("E:\\opt.txt", "w", stdout);
	int T, TT=0;
	cin>>T;
	while(++TT<=T){
		int N;
		cin>>N;
		for(int i=0; i<N; ++i) scanf("%s", s[i]);
		int sz=0;
		for(char *p=s[0], cur=*p; ; ++p){
			if(*p!=cur) rec[sz++]=cur, cur=*p;
			if(!*p) break;
		}
		bool f;
		for(int i=0; i<N; ++i){
			f=0;
			int t=0;
			for(char *p=s[i], cur=*p, n=0; ; ++p, ++n){
				if(*p!=cur)
					if(cur!=rec[t]){f=1; break;}
					else cnt[i][t]=n, ++t, n=0, cur=*p;
				if(!*p) break;
			}
			if(t!=sz) f=1;
			if(f) break;
		}
		if(f){
			printf("Case #%d: Fegla Won\n", TT);
			continue;
		}
		int ans=0;
		for(int i=0; i<sz; ++i){
			vector<int> buf;
			for(int j=0; j<N; ++j)
				buf.push_back(cnt[j][i]);
			sort(buf.begin(), buf.end());
			int t=buf[N/2];
			for(int j=0; j<N; ++j)
				if(cnt[j][i]>=t) ans+=cnt[j][i]-t;
				else ans+=t-cnt[j][i];
		}
		printf("Case #%d: %d\n", TT, ans);
	}
	return 0;
}