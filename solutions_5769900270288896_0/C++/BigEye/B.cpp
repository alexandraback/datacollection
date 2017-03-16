#include <iostream>
#include <queue>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define f(i,a,b) for(int i=(a);i<(b);++i)
#define fe(i,a,b) for(int i=(a);i<=(b);++i)
#define r(i,n) f(i,0,n)
#define re(i,n) fe(i,0,n)
#define fsz(i,a,v) f(i,a,sz(v))
#define rsz(i,v) r(i,sz(v))
#define all(v) v.begin(),v.end()
#define set(x,with) memset(x,with,sizeof(x))
#define same(a,b) (fabs((a)-(b))<0.0000001)
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define MAXN (1000010)

int tn;
int p, n, m;

int main(int argc, char *argv[]) {
  cin >> tn;
  fe(ti,1,tn) {
    cin >> n >> m >> p;
    int nm = n * m;
    int minscore = 0x7ffffff;
    f(state, 0, 1 << nm) {
      int now = state;
      vector<int> states;
      int cnt = 0;
      r(i, nm) {
        states.pb(now % 2);
        if (now % 2 == 1) ++cnt;
        now /= 2;
      }
      if (cnt != p) continue;
      // r(i, nm) {
      //   if (i % m == 0) cout << endl;
      //   cout << states[i] << " ";
      // }
      // cout << endl;
      
      int score = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          int now = i*m + j;
          int nowr = i*m + j + 1;
          int nowd = (i + 1)*m + j;
          if (states[now] == 0) continue;
          if (j + 1 < m && states[nowr] == 1) ++score;
          if (i + 1 < n && states[nowd] == 1) ++score;
        }
      }
      // cout << " # : " << score << endl;
      minscore = min(minscore, score);
    }
    cout << "Case #" << ti << ": " << minscore << endl;
  }    
  
  return 0;
}
