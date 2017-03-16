#include<bits/stdc++.h>
#include <unistd.h>

#define IT(a,it) for(auto it=a.begin(); it != a.end(); it++)
#define REV_IT(a,it) for(auto it=a.rbegin(); it != a.rend(); it++)
#define LL long long
#define LD long double
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define INF (int)(1e9)
#define EPS (double)(1e-9)

#ifndef ONLINE_JUDGE
#  define LOG(x) cerr << #x << " = " << (x) << endl
#else
#  define LOG(x) 0
#endif

#define MAXX 500005

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * b / gcd(a, b); }

int r, c, n;

pi_i get(int curr){
	int ii, jj;
	ii = curr/c;
	jj = curr % c;
	return MP(ii, jj);
}

int solve(int idx, int ct, vector<int> vv){
	if(idx >= r*c){
		if(ct > 0) return INF;
		int mat[20][20];
		for(int i = 0;i<20;i++) for(int j = 0;j<20;j++) mat[i][j] = 0;
		int ans = 0;
		for(int i = 0;i<vv.size();i++){
			int curr = vv[i];
			pi_i pp = get(curr);
			mat[pp.FF][pp.SS] = 1;
		}
		for(int i = 0;i<r;i++){
			for(int j = 0;j<c;j++){
				if(mat[i][j] == 1){
					if(mat[i+1][j] == 1) ans++;
					if(mat[i][j+1] == 1) ans++;
				}
			}
		}
		return ans;
	}
	int v1 = INF, v2 = INF;
	if(ct > 0){
		v1 = solve(idx+1, ct, vv);
		vv.PB(idx);
		v2 = solve(idx+1, ct-1, vv);
		vv.pop_back();
	}
	else v1 = solve(idx+1, ct, vv);
	return min(v1, v2);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int T, casee = 1;
	cin >> T;
	for(casee=1;casee<=T;casee++){
		cin >> r >> c >> n;
		cout << "Case #" << casee << ": " ;
		vector<int> vv;
		cout << solve(0, n, vv) << endl;
		vv.clear();
	}
	fclose(stdin);
	fclose(stdout);
return 0;	
}

