#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define mp make_pair
#define X first
#define Y second

#define pb push_back
#define forI_(i,V,_) for(__typeof(V.end())i=_;i!=V.end();++i)
#define forI(i,V) forI_(i,V,V.begin())

#define rep(i,l,r) for(int i = l; i <= r; ++i)
#define per(i,r,l) for(int i = r; i >= l; --i)
#define rep_(i,l,r) for(int i = l; i < r; ++i)
#define per_(i,r,l) for(int i = r; i > l; --i)

// =====================================================
// Settings

string prob = "t";

const int OUTPUT_TO_FILE = 1;
const int MULTI_TESTCASE = 1;
const int TESTCASE_NUM_GIVEN = 1;
const int OUTPUT_CASE_NUM = 1;

const int MAXN = 100;
const int MAXM = 0;
const int P = 1000000007;

// =====================================================
// Code goes here.
// main_solve() should return if it has seen EOF if (MULTI_TESTCASE && ! TESTCASE_NUM_GIVEN).
// The return value doesn't matter otherwise.

int M, R, C;
int ans;

int a[MAXN * MAXN];
int b[MAXN][MAXN];

void check(){
	rep(i, 0, R - 1)
		rep(j, 0, C - 1)
			b[i][j] = a[i * C + j];
	int s = 0;
	rep(i, 0, R - 1)
		rep(j, 0, C - 1){
			s += b[i][j] && b[i - 1][j];
			s += b[i][j] && b[i][j - 1];
		}
	ans = min(ans, s);
}	

void dfs(int k, int rest){
	if(k == M){
		if(rest == 0)
			check();
		return;
	}
	if(rest){
		a[k] = 1;
		dfs(k + 1, rest - 1);
		a[k] = 0;
	}
	dfs(k + 1, rest);
}

bool main_solve(){
	int n;
	scanf("%d%d%d", &R, &C, &n);
	M = R * C;
	ans = n * n;
	dfs(0, n);
	printf("%d\n", ans);
}

// =====================================================

int main(){
#ifdef ONLINE_JUDGE
	if(prob == "t")
		prob = "";
#endif
	if(prob != ""){
		freopen((prob+".in").c_str(), "r", stdin);
		if(OUTPUT_TO_FILE)
			freopen((prob+".out").c_str(), "w", stdout);
	}
	if(MULTI_TESTCASE){
		if(TESTCASE_NUM_GIVEN){
			int TC;
			scanf("%d\n", &TC);
			rep(T, 1, TC){
				if(OUTPUT_CASE_NUM)
					printf("Case #%d: ", T);
				main_solve();
			}
		}else{
			while(main_solve());
		}
	}else{
		main_solve();
	}
	return 0;
}
