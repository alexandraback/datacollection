#include <bits/stdc++.h>
#define f(i,x,y) for (int i = x; i < y; i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define eps (1e-9)
#define oo (1<<30)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; f(i,0,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; f(i,0,m)f(j,0,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define N 1
using namespace std;
template<class T> inline void mini(T &a,T b){if(b<a) a=b;}
template<class T> inline void maxi(T &a,T b){if(b>a) a=b;}

int tc;
string s[105];
string b[105];
int v[105][105];

int caso;
int main(){
	cin >> tc;
	while(tc--) {
		int n; cin >> n;
		int m;
		f(i,0,n) cin >> s[i];
		f(i,0,n) b[i] = s[i];
		f(i,0,n) {
			m = unique(all(b[i])) - b[i].begin();
			b[i] = b[i].substr(0, m);
		}
		bool eq = 1;
		f(i,1,n) if(b[i] != b[0]) eq = 0;
		printf("Case #%d: ", ++caso);
		if (!eq) puts("Fegla Won");
		else {
			f(i,0,n) {
				int j = 0;
				for(int i1 = 0, i2 = 0; i1 < s[i].size(); i1=i2) {
					for(; i2 < s[i].size() && s[i][i1] == s[i][i2]; i2++);
					v[i][j++] = i2 - i1;
				}
			}
//			mdebug(v, n, m);
			int res = 0;
			f(j,0,m) {
				vint w;
				f(i,0,n) w.pb(v[i][j]);
				sort(all(w));
				for(int i1 = 0, i2 = n-1; i1 < i2; i1++,i2--) {
					res += w[i2] - w[i1];
				}
			}
			printf("%d\n", res);
		}
	}
}


