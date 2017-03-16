#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define REP(i, n) FOR(i,0,n)
#define MP(a,b) make_pair(a,b)

// for debug start
#define VD(x) << #x << ":" << x << " "
#define PRLN cout<<endl;
#define DUMPA(a,b,e,s) {FOR(i,b,e)cout<<a[i]<<s;}
#define DUMP2(a,n,N,m,M,s) {FOR(j,m,M)cout<<j<<s;PRLN;FOR(i,n,N){cout<<i<<s;FOR(j,m,M)cout<<a[i][j]<<" ";PRLN}}
#define TSIZE(T,A...) sizeof((T[]){A})/sizeof(T)
#define DUMPT(T,A...) {T n=TSIZE(T,A);T a[]={A};cout<<#A<<"=";DUMPA(a,0,n," ")PRLN}
#define DUMPI(...) DUMPT(int,__VA_ARGS__)
// for debug end

int T;

int main (int argc, char const *argv[])
{
  cin >> T;
  for (int i = 0; i < T; i++) {
    cout << "Case #" << i+1 << ": " ;
    int N; cin >> N;
    map<int,string> pmap;
    for (int n = 0; n < N; n++) {
      int p; cin >>p;
      pmap[p] += char('A'+n);
    }
    for (int p=1000;p>0;--p) {
      while(pmap[p].size()){
        switch (pmap[p].size()) {
          case 1:
          case 2:
          cout << pmap[p] << " ";
          pmap[p-1] += pmap[p];
          pmap[p].clear();
          break;
          default:
          cout << pmap[p][0] << " ";
          pmap[p-1] += pmap[p][0];
          pmap[p].replace(0,1,"");
        }
      }
    }
    cout << endl;
  }

  return 0;
}
