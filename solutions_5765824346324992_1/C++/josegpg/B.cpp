#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdlib>

using namespace std;

#define ri(X) scanf("%d", &(X))
#define pi(X) printf("%d", (X))
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define lint long long
#define pii pair<int,int>
#define inf 1e9
#define linf 1e15
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define uni(X) X.erase(unique(X.begin(), X.end()), X.end());

int t, b;
lint n, a[2000];

lint getAtt(lint time) {
  lint att = 0;
  for (int i = 0; i < b; i++) att += (time/a[i]) + 1;
  //cout << "att " << att << endl;
  return att;
}

bool f(lint time) {
  lint att = getAtt(time);
  return (att >= n);
}

lint bbin() {
  lint lo = 0, hi = linf, mi;
  
  while (lo+1 < hi) {
    mi = (lo + hi) >> 1;
    //cout << lo << " " << hi << " " << mi << " ";
    bool aux = f(mi);
    if (aux) hi = mi;
    else lo = mi;
  }
  
  while (lo < hi) {
    if (f(lo)) break;
    lo++;
  }
  //cout << "Res " << lo << endl;
  return lo;
}

int main(){
  ri(t);
  for (int T = 1; T <= t; T++) {
    ri(b); cin >> n;
    for (int i = 0; i < b; i++) cin >> a[i];
    lint ti = bbin();
    int res = 0;
    lint curr = (ti-1 >= 0 ? getAtt(ti-1) : 0);
    for (int i = 0; i < b; i++) if (ti%a[i]==0) {
      curr++;
      if (curr == n) {
        res = i+1;
        break;
      }
    }
    
    printf("Case #%d: %d\n", T, res);
  }
  
  return 0;
}
