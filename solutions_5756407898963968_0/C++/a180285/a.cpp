/*****************************************
NAME    : wei.huang
PROJECT : Problem A. Magic Trick
LANG    : C++
2013    , renren-inc
*****************************************/

# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <algorithm>
# include <iostream>
# include <string>
# include <queue>
# include <stack>
# include <map>
# include <set>
# include <vector>
# include <cstring>
# include <list>
# include <ctime>
# include <sstream>

# define For(i,a)   for((i)=0;i<(a);(i)++)
# define MAX(x,y)   ((x)>(y)? (x):(y))
# define MIN(x,y)   ((x)<(y)? (x):(y))
# define sz(a)      (sizeof(a))
# define MEM(a)     (memset((a),0,sizeof(a)))
# define MEME(a)    (memset((a),-1,sizeof(a)))
# define MEMX(a)    (memset((a),0x7f,sizeof(a)))
# define pb(a)      push_back(a)

# define Foreach(it, v)     for(__typeof((v).begin()) it = (v).begin(); (v).end() != it; ++it)

using namespace std;

typedef long long           ll      ;
typedef unsigned long long  ull     ;
typedef unsigned int        uint    ;
typedef unsigned char       uchar   ;


template<class T> inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template<class T> inline void checkmax(T &a, T b) {
  if (a < b) a = b;
}

const int oo = 1 << 30          ;
const double eps = 1e-7       ;
const int N = 1               ;
const int M = 1               ;
const ll P = 10000000097ll    ;

void read() {

}

void print() {

}

vector<int> get() {
  int r;
  cin >> r;
  vector<int> ret;
  for (int i=1; i<=4; i++) {
    for (int j=0; j<4; j++) {
      int x;
      cin >> x;
      if (i == r) {
        ret.push_back(x);
      }
    }
  }
  return ret;
}

vector<int> interval(vector<int> s1, vector<int> s2) {
  vector<int> ret;
  for (auto i : s1) {
    for (auto j : s2) {
      if (i == j) {
        ret.pb(i);
      }
    }
  }
  return ret;
}

void doit() {
  vector<int> s1 = get();
  vector<int> s2 = get();
  vector<int> ans = interval(s1, s2);
  switch (ans.size()) {
  case 0:
    puts("Volunteer cheated!");
    break;
  case 1:
    cout << ans[0] << endl;
    break;
  default:
    puts("Bad magician!");
    break;
  }
}

int main(int argc, char const *argv[]) {
#ifdef Hw
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  int T;

  cin >> T;
  for (int i=1; i<=T; i++) {
    printf("Case #%d: ", i);
    read();
    doit();
    print();
  }

  return 0;
}

/**



**/


