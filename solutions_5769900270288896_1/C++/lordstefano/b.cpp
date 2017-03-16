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

int Vx[] = {-1, 1, 0, 0};
int Vy[] = {0, 0, -1, 1};
int n, m;
int ans;

bool out (int x, int y){
	return min(x,y) < 0 || x >= n || y >= m;
}

vector <int> v[2];

int main (){
	int t; cin >> t;
	f (kase, 1, t+1){
		int caras;
		cin >> n >> m >> caras;
		int tot = 0;
			v[0].clear(), v[1].clear();
		f (i, 0, n) f (j, 0, m){
			int cnt = 0;
			f (d, 0, 4){
				int x = i+Vx[d], y = j+Vy[d];
				if (out(x,y)) continue;
				cnt++;
				tot++;
			}
			v[(i+j)%2].pb(cnt);
		}
		tot /= 2;
		f (j, 0, 2) sort (rall(v[j]));
		int ret;
		if (caras <= (n*m+1)/2) ret = 0;
		else{
			ret = 0;
			f (i, 0, 2){
				int p = 0;
				f (j, 0, n*m-caras) p += v[i][j];
				ret = max(ret, p);
			}
			ret = tot-ret;
		}
		printf("Case #%d: %d\n", kase, ret);	
	}
	return 0;
}


