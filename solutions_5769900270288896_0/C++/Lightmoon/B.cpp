#include <bits/stdc++.h>

#define For(i,a,b) for (int i = (a); i <= (b); i++)
#define Ford(i,a,b) for (int i = (a); i >= (b); i--)
#define Rep(i,a) for (int i = 0; i < (a); i++)
#define Repd(i,a) for (int i = (int)(a) - 1; i >=0; i--)
#define PI (acos(0.0) * 2)
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define PII pair<int, int>
#define PIII pair<PII, int>
#define VI vector<int>
#define sz(a) ((int)a.size())
#define oo 1000000000
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(a,u,v) {cout << #a << " = "; For(_,u,v) cout << a[_] << ' '; cout << endl;}
#define MAXN 1000111
#define LL long long
#define Two(n) (1<<(n))
#define RESET(a,c) memset(a, c, sizeof(a))
using namespace std;

int a[100][100];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int calculate(int st, int r, int c) {
	RESET(a,0);
	Rep(i,r*c) if ((st >> i) & 1) {
		int x = i/c, y=i%c;
		a[x+1][y+1] = 1;
	}
	int res = 0;
	For(i,1,r) For(j,1,c) if (a[i][j]) {
		Rep(k,4) {
			int u = i + dx[k], v = j + dy[k];
			res += a[u][v];
		}
	}
	return res/2;
}

int calc(int r, int c, int n) {
	int res = r*c*4;
	For(i,0,Two(r*c)) {
		if (__builtin_popcount(i) == n) {
			res = min(res, calculate(i, r, c));
		}
	}
	return res;
}

int main() {
	int ntest;
	cin >> ntest;
	For(test,1,ntest) {
		int r, c, n;
		cin >> r >> c >> n;
		LL result = calc(r,c,n);
		cout << "Case #" << test << ": " << result << endl;
	}
}