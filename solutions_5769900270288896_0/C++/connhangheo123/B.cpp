#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define sr(x) (int)x.size()
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {cout << #x << " = "; For(_,a,b) cout << x[_] << ' '; cout << endl;}
#define Bit(s,i) (((s)&(1<<(i)))>0)
#define Two(x) (1<<(x))
const int MOD = 1000000007;
const int nmax = 10000;
const double E = 1e-8;
const double PI = acos(-1);
typedef long long LL;
typedef pair<int,int> pii;
int n,m,stest,k;
int res;
int Fre[20][20];
void DFS(int i,int j,int k,int s) {
	if ( k == 0 ) {
		res = min(res, s);
		return;
	}
	if ( i > n ) return;
	int u = i,v = j+1;
	if ( j == m ) {
		u++;
		v=1;
	}
	DFS(u,v,k,s);
	Fre[i][j] = 0;
	DFS(u,v,k-1, s + ( Fre[i-1][j] == 0 ) + (Fre[i][j-1] == 0) );
	Fre[i][j] = 1;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> stest;
	For(test,1,stest) {
		cin >> n >> m >> k;
		For(i,0,n) For(j,0,m) Fre[i][j] = true;
		res = MOD;
		DFS(1,1,k,0);
		cout << "Case #" << test << ": " << res << endl;
	}
	return 0;
}