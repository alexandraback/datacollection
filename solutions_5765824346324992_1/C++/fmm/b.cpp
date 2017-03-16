#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

#define rep(x,n) for(int x = 0; x < n; ++x)
#define print(x) cout << x << endl
#define dbg(x) cerr << #x << " == " << x << endl
#define _ << " , " <<
#define mp make_pair
#define x first
#define y second

using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;
typedef pair<int,int> pii;

int n;
int b, m[1111];

void read() {
	cin>>b>>n;
	rep(i,b) cin>>m[i];
}

long long f(long long t) {
	long long x=0;
	rep(i,b) {
		//x += (t/m[i])*m[i] + (t%m[i]%t!=0);
		x += (t+m[i]-1)/m[i];
	}
	return x;
}

void process(int testcase) {
	long long t=1e18;

	//dbg( f(0) );
	//dbg( f(1) );
	//dbg( f(2) );


	for(long long take=t; take;) {
		long long nt = t-take;
		if(nt>0 && f(nt)>=n) t=nt;
		else take/=2;
	}
	
	//dbg(t);
	
	long long A = f(t), B = f(t-1);
	
	//dbg(A _ B);
	//dbg(n _ b);

	for(int i=0;i<b;i++) {
		int can = (t-1)%m[i] == 0;
		//dbg(i _ can);
		if(can && ++B == n) {
			printf("Case #%d: %d\n",testcase,i+1);
			return;
		}
	}

	dbg(testcase);
	assert(0);
}

int main() {
  int T;
  cin >> T;
  for(int testcase=1;testcase<=T;testcase++) { //if(testcase==6) {
    read();
    process(testcase);
  }
  return 0;
}

