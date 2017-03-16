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

const int mb = 1009;
lint n;
int nn, nb;
int x[mb];

lint getsum(lint t){
  lint sum = 0;
  for(int i = 0; i < nb; i++){
    sum += (t/x[i])+(t%x[i] == 0?0:1);
  }
  return sum;
}

bool f(lint t){
  lint sum = getsum(t);
  
  if(sum < n){
    return 1;
  }else{
    return 0;
  }
}

lint gt(){
  lint lo, hi, mi;
  lo = 0;
  hi = 1e12;
  
  while(hi-lo > 2){
    mi = (hi+lo)/2;
    if(f(mi)){
      lo = mi;
    }else{
      hi = mi;
    }
  }
  while(!f(hi)){
    hi--;
  }
  return hi;
}
int solve(){
  
  if(n <= nb){
    return n-1;
  }
  
  lint ti = gt();
  
  lint sum = getsum(ti);
  
  
  n -=sum;
  //printf("%lld %lld %lld \n",sum,  n , ti);
  assert(1 <= n && n <= nb);
  
  for(int i = 0; i < nb; i++){
    //printf("%d - %d\n",i, x[i]);
    if((ti)%x[i] != 0){
      continue;
    }
    if( n == 1) return i;
    n--;
  }
  assert(false);
}

int main(){
  int T;
  ri(T);
  for(int t = 0; t < T; t++){
    ri(nb); ri(nn);
    n = nn;
    
    for(int i = 0; i < nb; i++){
      ri(x[i]);
      
    }
    
    
    printf("Case #%d: %d\n", t+1, solve()+1);
    
    
  }
  return 0;
}

