#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int R,C, N;

int solve(int mask) {
  vector<string> b(R, string(C,'.'));
  int counter = 0;
  for(int i=0; i<R; i++) {
    for(int j=0; j<C; j++) {
      if( (mask>>counter) % 2) {
        b[i][j] = '#';
      }
      counter ++;
    }
  }
  int ret = 0;
  for(int i=0; i<R; i++) {
    for(int j=0; j<C ;j++) {
      if(b[i][j] == '#') {
        if(i +1 <R && b[i+1][j] == '#') ret ++;
        if(j+1 < C && b[i][j+1] == '#') ret ++; 
      }
    }
  }
  return ret;

}

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    cin >> R >> C >> N;
    int ret = 300;
    for(int x=0; x< (1 << (R*C)); x++) {
      if(__builtin_popcount(x) == N)
        ret= min (ret, solve(x));
    }
    printf("Case #%d: %d\n",tc,ret);


  }

  return 0;
}