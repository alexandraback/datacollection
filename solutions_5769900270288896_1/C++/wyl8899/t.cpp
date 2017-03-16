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

int a[5];
int ans;

inline int calc(int R, int C){
	return R * (C / 2) + R / 2 + 1;
}

void push(int n){
	//printf("push : n = %d | %d %d %d %d %d\n", n, a[0], a[1], a[2], a[3], a[4]);
	int s = 0;
	rep(i, 0, 4){
		int t = min(n, a[i]);
		s += t * i;
		n -= t;
	}
	if(ans == -1 || s < ans)
		ans = s;
}

void go(int R, int C, int n){
	if(C % 2 == 1)
		swap(R, C);
	int x = R % 2, y = C % 2;
	memset(a, 0, sizeof(a));
	if(x == 0 && y == 0){
		a[0] = R * C / 2;
		a[2] = 2;
		a[4] = (R - 2) * (C - 2) / 2;
		a[3] = R * C - a[0] - a[2] - a[4];
	}
	if(x == 1 && y == 0){
		if(R == 1){
			a[0] = C / 2;
			a[1] = 1;
			a[2] = C / 2 - 1;
		}else{
			a[0] = R * C / 2;
			a[2] = 2;
			a[4] = (R - 2) * (C - 2) / 2;
			a[3] = R * C - a[0] - a[2] - a[4];
		}
	}
	if(x == 1 && y == 1){
		if(R > C)
			swap(R, C);
		if(R == 1){
			a[0] = C / 2 + 1;
			a[2] = C / 2;
			push(n);
			swap(a[0], a[2]);
		}else{
			a[0] = calc(R, C);
			a[4] = (R - 2) * (C - 2) - calc(R - 2, C - 2);
			a[3] = R * C - a[0] - a[4];
			push(n);
			a[0] = R * C - a[0];
			a[2] = 4;
			a[4] = calc(R - 2, C - 2);
			a[3] = R * C - a[0] - a[4] - a[2];
		}
	}
	push(n);
}		

bool main_solve(){
	int R, C, n;
	scanf("%d%d%d", &R, &C, &n);
	ans = -1;
	go(R, C, n);
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
