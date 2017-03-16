#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

bool field[1005][1005];
int N, R, C;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

bool inside(int x, int y){
	if(x < 0 || y < 0 || x >= R || y >= C)
		return 0;
	return 1;
}

int countSq(int x, int y){
	int ret=0;
	rep(k,0,4){
		int i=x+dx[k];
		int j=y+dy[k];
		if(!inside(i, j))
			continue;
		ret += field[i][j];
	}
	return ret;
}

int count(){
	int ret=0;
	for(int i=0; i < R; ++i)
		for(int j=0; j < C; ++j){
			if(!field[i][j])
				continue;
			ret += countSq(i, j);
		}
	return ret;
}

void solve(){
	scanf("%d%d%d", &R, &C, &N);
	int ntmp=N;
	rep(i,0,R)
		rep(j,0,C)
			field[i][j]=0;
	for(int num=0; num <= 4; ++num){
		rep(i,0,R)
			rep(j,0,C){
				if(!N)
					break;
				if(!field[i][j] && countSq(i,j) == num){
					field[i][j]=1;
					--N;
				}
			}
	}
	int ans1=count()/2;
	rep(i,0,R)
		rep(j,0,C)
			field[i][j]=1;
	N=R*C-ntmp;
	for(int num=4; num >= 0; --num){
		rep(i,0,R)
			rep(j,0,C){
				if(!N)
					break;
				if(field[i][j] && countSq(i,j) == num){
					field[i][j]=0;
					--N;
				}
			}
	}
	printf("%d\n", min(ans1, count()/2));
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t <= T; ++t){
		printf("Case #%d: ", t);
		solve();
	}
}
