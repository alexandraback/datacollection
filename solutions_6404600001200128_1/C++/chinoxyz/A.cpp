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

using namespace std;

#define ri(X) scanf("%d", &(X))
#define pi(X) printf("%d", (X))
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define lint long long
#define pii pair<int,int>
#define inf 1e9
#define linf 1e18
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define uni(X) X.erase(unique(X.begin(), X.end()), X.end());

int T;
int n;
const int mn = 1009;
int x[mn];

int f1(){
  

  int p = x[0];
  int res = 0;
  for(int i = 1; i < n; i++){
    if(x[i] < p){
      res += p-x[i];
    }
    p = x[i];
  }
  return res;
}

bool f(int rate){
  int p = x[0];
  for(int i = 1; i < n; i++){
    p = max(0, p-rate);
    if(p > x[i]) return 0;
    p = x[i];
  }
  return 1;
}
int gr(){
  
  int lo = 0;
  int hi = 10009;
  int mi;
  while((hi-lo) >= 2){
    mi = (hi+lo)/2;
    
    if(f(mi)){
      hi = mi;
    }else{
      lo = mi;
    }
  }
  while(!f(lo)){
    lo++;
  }
  return lo;
}
int f2(){
  int res = 0;
  int rate = gr();
  
  int p = x[0];
  for(int i = 1; i < n; i++){
    res = res + p-max(0, p-rate);
    p = max(0, p-rate);
    p = x[i];
  }
  return res;

}

int main(){
  ri(T);
  for(int t = 0; t < T; t++){
    ri(n);
    for(int i = 0; i < n; i++){
      ri(x[i]);
    }
    
    printf("Case #%d: %d %d\n", t+1, f1(), f2());
  }
  return 0;
}

