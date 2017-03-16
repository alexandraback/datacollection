#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

typedef pair<int,int> pii;

void solve(){
  int n = in();
  vector<pii> p(n);
  int i;
  int total = 0;
  for(i=0;i<n;i++){
    p[i] = pii(in(),i);
    total+=p[i].first;
  }
  
  while(1){
    sort(p.begin(),p.end());
    if(p[n-1].first == 0) break;
    p[n-1].first--;
    total--;
    
    string s = "";
    s += ('A'+p[n-1].second);
    
    if(p[n-2].first*2>total){
      total--;
      p[n-2].first--;
      s += ('A'+p[n-2].second);
    }
    
    cout << s <<' ';
    
  }
  
  cout << endl;
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #"<< i+1 << ": " ;
      solve();
    }
}
