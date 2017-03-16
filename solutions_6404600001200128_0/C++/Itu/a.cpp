#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb(x) push_back(x)
#define REP(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define trace(x) cerr << #x << ": " << x << endl;
#define fst first
#define snd second
#define itm1 fst.fst
#define itm2 fst.snd
#define itm3 snd
#define mt(a,b,c) mp(mp(a,b),c)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int64;
typedef unsigned long long uint64;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ii, int> tri;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> tri64;
typedef set<int> seti;
typedef set<ii> setii;
typedef stack<int> stki;
typedef stack<ii> stkii;
typedef queue<int> qi;
typedef queue<ii> qii;
typedef map<int,int> mapii;
typedef map<string,int> mapsi;
typedef unsigned int uint;

const double PI = 3.14159265359;

int n;
int num[2000];
int ans1, ans2;
int rate;

int max(int a, int b){
	if (a > b) return a;
	return b;
}

int main(){
	int nCases;
	cin >> nCases;
	REP(casenum,0,nCases){
		cin >> n;
		REP(i,0,n) cin >> num[i];
		ans1 = 0;
		REP(i,1,n){
			ans1 += max(0, num[i-1] - num[i]);
		}
		ans2 = 0;
		rate = 0;
		REP(i,1,n){
			rate = max(rate, num[i-1] - num[i]);
		}
		REP(i,0,n-1){
			ans2 += min(rate, num[i]);
		}
		cout << "Case #" << casenum+1 << ": " << ans1 << " " << ans2 << endl;
	}  
	return 0;
}

