#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}



typedef long long T;
const T EPS = 1e-7;
struct PT { 
  T x, y; 
  PT() {} 
  PT(T x, T y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }


void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) > 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) < 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}



void solve(){
  
  int N = in();
  
  vector<PT> pts(N);
  vector<int> ans(N,N-1);
  
  
  int i,j;
  for(i=0;i<N;i++){
    int x = in();
    int y = in();
    pts[i] = PT(x,y);
  }
  
  for(i=0;i<(1<<N);i++){
    
    vector<PT> pt2;
    int cnt = 0;
    
    for(j=0;j<N;j++) if(i&(1<<j)){
      pt2.push_back(pts[j]);
    }else{
      cnt++;
    }
    
    if(pt2.size()<2) continue;
    
    ConvexHull(pt2);
    
    for(j=0;j<N;j++) if(find(pt2.begin(),pt2.end(),pts[j])!=pt2.end()) ans[j] = min(ans[j],cnt);
    
  }
  
  for(i=0;i<N;i++) cout << ans[i] << endl;
  
}


int main(){
  for(int i=0,T=in();i<T;i++){
    cout << "Case #"<<i+1<<": " << endl;
      solve();
    }
}
