#include <bits/stdc++.h>
#include <cstdlib>
#include <cstdio>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define uint unsigned int
#define LL long long
#define ULL unsigned LL
#define VI vector<int>
#define X first
#define Y second
#define reads(_s) getline(cin,_s)
#define sz(_v) ((int)_v.size())
#define all(_v) (_v).begin(),(_v).end()
#define FOR(_i,a,b) for (int _i(a),_l(b); _i<=_l; ++_i)
#define rept(i,a) FOR(i,0,(int)(a)-1)
#define x1 X1
#define y1 Y1
#define sqr(a) ((a)*(a))
#define C(a) memset((a),0,sizeof (a))
#define MS(a,x) memset((a),(x),sizeof (a))
#define INF 1050000000
#define INFL INF*1ll*INF
#define PI 3.141592653589
#define eps 1e-10
#define MOD 1000000023
#define PRIME 312427

using namespace std;

bool cur[16][16];

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int fnd(int r, int c) {
	int total(0);
	rept(i,r) rept(j,c) {
		if (!cur[i][j]) continue;
		rept(q,4) {
			int ni(i+dx[q]),nj(j+dy[q]);
			if (ni>=0 && nj>=0 && ni<r && nj<c && cur[ni][nj]) ++total;
		}
	}
	return total/2;
}

void solve_test() {
	int r,c,n;
	scanf("%d%d%d",&r,&c,&n);
	int to(1<<(r*c));
	int mn(INF);
	rept(i,to) {
		int q(r*c);
		int mask(i);
		int tot(0);
		rept(j,q) {
			cur[j/c][j%c]=mask%2;
			tot+=mask%2;
			mask/=2;
		}
		if (tot==n) {
			mn=min(mn,fnd(r,c));
		}
	}
	printf("%d\n",mn);
}

void solve() {
	int tst;
	scanf("%d\n",&tst);
	FOR(i,1,tst) {
		printf("Case #%d: ",i);
		solve_test();
	}
}

int main() {
#ifdef yeti
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#endif

#ifdef yeti
    clock_t tm = clock();
    cerr<<setprecision(10);
#endif
    solve();
#ifdef yeti
    cerr<<setprecision(3)<<(clock()-tm+0.)/CLOCKS_PER_SEC<<endl;
#endif
    return 0;
}