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
int caso;

int main(){
	cin >> tc;
	int a[4][4], b[4][4];
	int r1,r2;
	while(tc--) {
		vint vis(17,0);
		cin >> r1;
		f(i,0,4) f(j,0,4) cin >> a[i][j];
		cin >> r2;
		f(i,0,4) f(j,0,4) cin >> b[i][j];
		f(j,0,4) vis[a[r1-1][j]]++;
		f(j,0,4) vis[b[r2-1][j]]++;

		int ct = 0;
		int res;
		f(i,0,17) if (vis[i] == 2) ct++, res = i;
		printf("Case #%d: ", ++caso);
		if (ct == 1) printf("%d\n", res);
		else if(ct > 1) puts("Bad magician!");
		else puts("Volunteer cheated!");
	}
}


