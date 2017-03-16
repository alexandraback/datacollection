#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
const double EPS = 1e-10;
const double PI  = acos(-1.0);

int bc(int x){
  int res = 0;
  while(x>0){
	res += x & 1;
	x >>= 1;
  }
  return res;
}

int R, C, N;
int solve(int pat){
  int res = 0;
  for(int y=0;y<R;++y){
	for(int x=0;x+1<C;++x){
	  int idx = y * C + x;
	  int bit = (1<<idx) | (1<<(idx+1));
	  if((pat&bit) == bit)
		++res;
	}
  }

  for(int x=0;x<C;++x){
	for(int y=0;y+1<R;++y){
	  int idx = y * C + x;
	  int bit = (1<<idx) | (1<<(idx+C));
	  if((pat&bit) == bit)
		++res;
	}
  }

  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(t,1,T+1){
	cin >> R >> C >> N;
	int ans = 1000;
	for(int i=0;i<1<<(R*C);++i)
	  if(bc(i) == N) ans = min(ans, solve(i));
	
	cout << "Case #" << t << ": " << ans << endl;
  }
  
  return 0;
}
