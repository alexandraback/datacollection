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
int m[1111];

void read() {
	cin>>n;
	rep(i,n) cin>>m[i];
}

void process(int testcase) {
	int a=0,b=0;
	double r=0;
	for(int i=1;i<n;i++) {
		if(m[i-1]>m[i]) {
			a += m[i-1]-m[i];
			r=max(r,(m[i-1]-m[i])/10.);
		}
	}
	//dbg(r);
	for(int i=1;i<n;i++) {
		int can=r*10;
		b += min(can,m[i-1]);
	}
	printf("Case #%d: %d %d\n",testcase, a, b);
}

int main() {
  int T;
  cin >> T;
  for(int testcase=1;testcase<=T;testcase++) {
    read();
    process(testcase);
  }
  return 0;
}

