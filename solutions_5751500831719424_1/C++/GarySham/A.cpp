#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define CLR(i) memset(i,0,sizeof(i))
#define ll long long

int T,N;
char s[105],tmp[105];

char a[105][105];
int b[105][105],m[105];

int main(){
	scanf("%d",&T);
	FOE(t,1,T){
		scanf("%d",&N); gets(tmp);

		FOR(i,0,N){
			gets(s);

			int len = strlen(s);

			m[i] = 1;
			a[i][0] = s[0]; b[i][0] = 1;
			FOR(j,1,len){
				if (s[j] == s[j-1]) ++b[i][m[i]-1];
				else{
					a[i][m[i]] = s[j]; b[i][m[i]] = 1;
					++m[i];
				}
			}

			//FOR(j,0,m[i]) printf("%c %d!\n",a[i][j],b[i][j]);
		}

		bool ok=1;
		FOR(i,1,N) if (m[i] != m[i-1]) ok=0;

		int ans=0;
		FOR(i,0,m[0]){
			if (!ok) break;

			int st=INF,ed=-INF;

			char c=a[0][i];
			FOR(j,0,N){
				if (a[j][i] != c) ok=0;
				st = min(st,b[j][i]); ed = max(ed,b[j][i]);
			}

			/*
			if (ok){
				printf("%c: %d %d\n",c,st,ed);
			}
			*/

			int num=INF;
			FOE(l,st,ed){
				int count=0;
				FOR(j,0,N) count += abs(b[j][i] - l);

				num = min(count,num);
			}

			ans+=num;
		}

		if (ok) printf("Case #%d: %d\n",t,ans);
		else printf("Case #%d: Fegla Won\n",t);
	}
	return 0;
}
