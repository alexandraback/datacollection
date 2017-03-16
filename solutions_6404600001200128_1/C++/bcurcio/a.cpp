#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

#define EPS 1e-10




void solve(){
  int N = in();
  int i;
  vector<int> a(N);
  long long ans1 = 0;
  
  int maxDif = -1;
  
  for(i=0;i<N;i++){
    cin>>a[i];
    if(i>0){
      ans1 += max(0,a[i-1] - a[i]);
      maxDif = max(maxDif,a[i-1]-a[i]);
    }
    
    
  }
  
  long long ans2 = 0;
  
  if(maxDif <=0 ){
    ans2 = 0;
  }else{
    ans2 = 0;
    
    for(i=0;i<N-1;i++){
        ans2 += a[i] < maxDif ? a[i] : maxDif;
    }
    
  }
  
  
  
  
  cout << ans1 << ' ' << ans2 << endl;
  
  
  
}

int main(){
  for(int i=0,T=in();i<T;i++){
    cout << "Case #"<<i+1<<": ";
      solve();
    }
}
