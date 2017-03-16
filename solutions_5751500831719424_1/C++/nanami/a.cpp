#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = ~0u >> 1,maxn = 105;
int n,len[maxn],a[maxn],b[maxn];
char s[maxn][maxn];
void init()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i){
		scanf("%s",s[i]);
		len[i] = strlen(s[i]);
	}
}
int abs(int x)
{
	return x >= 0 ? x : -x;
}
void solve()
{
	memset(a,0,sizeof(a));
	int ans = 0;
	while(a[0] != len[0]){
		char ch = s[0][a[0]];
		int tmp = 0;
		for(int i = 0; i < n; ++i){
			if(ch != s[i][a[i]]){
				puts("Fegla Won");
				return;
			}
			int cnt = 1;
			for(int j = a[i] + 1; j < len[i]; ++j){
				if(s[i][j] != ch) break;
				++cnt;
			}
			a[i] += cnt;
			b[i] = cnt;
			tmp = max(tmp,cnt);
		}
		int t = INF;
		for(int i = 1; i <= tmp; ++i){
			int ret = 0;
			for(int j = 0; j < n; ++j)
				ret += abs(b[j] - i);
			t = min(ret,t);
		}
		ans += t;
	}
	for(int i = 1; i < n; ++i)
		if(a[i] != len[i]){
			puts("Fegla Won");
			return;
		}
	printf("%d\n",ans);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int ca = 1; ca <= T; ++ca){
		init();
		printf("Case #%d: ",ca);
		solve();
	}
	return 0;
}

