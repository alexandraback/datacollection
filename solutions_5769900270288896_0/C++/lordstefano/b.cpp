#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )
#define FORV(it,A) for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
#define FORS(it,A) for(set<int>::iterator it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define N 30

int Vx[] = {-1, 1, 0, 0};
int Vy[] = {0, 0, -1, 1};
int n, m;
int ans;
int M[N][N];

bool out (int x, int y){
	return min(x,y) < 0 || x >= n || y >= m;
}
int check(){
	int cnt=0;
	f (i, 0, n) f (j, 0, m){
		f (d, 0, 4){
			int x = i+Vx[d], y = j+Vy[d];
			if (out(x,y)) continue;
			if (M[i][j] && M[x][y]) cnt++;
		}
	}
	return cnt/2;
}

void solve (int x, int y, int falta){
	if (falta < 0) return;
	if (x == n){
		solve (0, y+1, falta); return;
	}

	if (y == m){
		if (falta == 0) ans = min(ans, check());
		return;
	}

	M[x][y] = 0;
	solve(x+1, y, falta);
	M[x][y] = 1;
	solve(x+1, y, falta-1);
	M[x][y] = 0;
	
}


int main (){
	int t; cin >> t;
	f (kase, 1, t+1){
		int caras;
		cin >> n >> m >> caras;
		ans = (1<<20);
		solve(0, 0, caras);
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}


