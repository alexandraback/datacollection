#include <bits/stdc++.h>
using namespace std;
#define TR(i,v) 		for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
#define DEBUG(x) 		cout << #x << " = "; cout << x << endl;
#define SIZE(p) 		(int)(p).size()
#define MP(a, b)		make_pair((a), (b))
#define ALL(p)			(p).begin(), (p).end()
#define rep(i, n)		for(int (i)=0; (i)<(int)(n); ++(i))
#define REP(i, a, n)	for(int (i)=(a); (i)<(int)(n); ++(i))
#define FOR(i, a, b)   	for(int (i)=(int)(a); (i)<=(int)(b); ++(i))
#define FORD(i, b, a)  	for(int (i)=(int)(b); (i)>=(int)(a); --(i)) 
typedef long long LL;
typedef pair<int, int> pii;
string A[105], B[105];
int C[105][105];
int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);	
    freopen("A.out", "w", stdout);
    #endif
	// ios::sync_with_stdio(false);    cin.tie(0);
	int T;		scanf("%d", &T);
	FOR(cs, 1, T) {
		printf("Case #%d: ", cs);
		int n;	cin>>n;
		rep(i, n)	cin>>A[i], B[i]=A[i];
		rep(i, n) {
			string &s=B[i];
			string r;
			for(int i=0;i<SIZE(s);)
			{
				int j=i;
				while(j+1<SIZE(s) && s[j+1]==s[i]) ++j;
				r+=s[i];
				i=j+1;
			}
			B[i]=r;
		}
		bool ff=false;
		rep(i, n) if(B[i]!=B[0]) {
			puts("Fegla Won");
			ff=true;
			break;
		}
		// DEBUG(B[0]);
		if(ff)	continue;
		memset(C, 0, sizeof(C));
		int len=SIZE(B[0]);
		string w=B[0];
		rep(k, n) {
			string &s=A[k];
			int cnt=0;
			for(int i=0; i<SIZE(s);) {
				int j=i;
				while(j+1<SIZE(s) && s[j+1]==s[i])	++j;
				C[k][cnt++]=j-i+1;
				i=j+1;
			}			
			assert(cnt==len);
		}
		// rep(i, n)
		// rep(j, len) {
		// 	printf("%d%c", C[i][j], " \n"[j+1==len]);
		// }
		int res=0;
		rep(i, len) {
			int c=0x3f3f3f3f;
			rep(j, n) {
				int cc=0;
				rep(k, n)				
					cc+=abs(C[k][i]-C[j][i]);
				c=min(c, cc);
			}			
			res+=c;
		}		
		printf("%d\n", res);
	}
	return 0;
}