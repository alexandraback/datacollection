#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>

using namespace std;
#define PB push_back
#define MP make_pair
#define sz(v) ((v).size())
#define forn(i,n) for(int i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
typedef long long in;
typedef unsigned long long int llu;

void runtc();

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int ntc;
  cin>>ntc;
  for(int i=0;i<ntc;++i) {
    cout<<"Case #"<<(i+1)<<": ";
    runtc();
    cout<<endl;
  }
  
  return 0;
}

//=============================================================================
const in MAXAREA = 16;
in countwalls(bitset<MAXAREA> const& i, in r, in c) {
  int res = 0;
  forn(p, MAXAREA) {
    if(i.test(p)) {
      int x = p%r;
      int y = p/r;

      int xx, yy, cc;
      xx=x+1;yy=y; cc = xx+r*yy;
      if(xx>=0 && xx<r && yy>=0 && yy<c && i.test(cc)) {
        res++;
      }
      xx=x;yy=y+1; cc = xx+r*yy;
      if(xx>=0 && xx<r && yy>=0 && yy<c && i.test(cc)) {
        res++;
      }
      xx=x-1;yy=y; cc = xx+r*yy;
      if(xx>=0 && xx<r && yy>=0 && yy<c && i.test(cc)) {
        res++;
      }
      xx=x;yy=y-1; cc = xx+r*yy;
      if(xx>=0 && xx<r && yy>=0 && yy<c && i.test(cc)) {
        res++;
      }
    }
  }
  return res/2;
}

void runtc() {
  in r, c, n;
  cin>>r>>c>>n;

  in res = MAXAREA*MAXAREA;
  in poss = 1<<(r*c);
  forn(i,poss) {
    bitset<MAXAREA> bs(i);
    if((in)bs.count() == n) {
      in sol = countwalls(bs, r, c);
      res = min(res, sol);
    }
  }
  cout<<res;
}
