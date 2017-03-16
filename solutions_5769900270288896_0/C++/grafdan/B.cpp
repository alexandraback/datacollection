// -*- compile-command: "g++ -Wall -Wextra x.cpp -o x && ./x <test.in" -*-
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long in;
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(int i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
typedef vector<in> VI;

in popcount(in x) {
  in r = 0;
  while(x>0) {
    r += x%2;
    x/=2;
  }
  return r;
}

in R , C;
in get(in x, in r, in c) {
  return (x>>(r*C+c))%2;
}

void test() {
  in N; cin >> R >> C >> N;
  in opt = R*C*10;
  forn(x,1<<(R*C)) {
    if(popcount(x)!=N) continue;
    in cnt = 0;
    forn(r,R) {
      forn(c,C) {
        if(!get(x,r,c)) continue;
        in dx[4] = {0,1,0,-1};
        in dy[4] = {1,0,-1,0};
        forn(d,4) {
          in nr = r+dx[d];
          in nc = c+dy[d];
          if(0<=nr && nr<R && 0<=nc && nc<C) {
            cnt += get(x,nr,nc);
          }
        }
      }
    }
    cnt /=2;
    if(opt > cnt) opt = cnt;
  }
  cout << opt << endl;
}
int main(){
  std::ios::sync_with_stdio(false); // remove this if you use printf/scanf
  std::cin.tie(0);

  in T; cin >> T;
  forn(t,T) {
    cout << "Case #" << t+1 << ": ";
    test();
  }

  return 0;  
}
