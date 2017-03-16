#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;

const int N=50;
int p[N];
int q[N];
int n;

void read(){
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> p[i];
}

void solve(){
  if(n==2){
    for(int i=0; i<p[0]; i++)
      cout << "BA ";
    cout << '\n';
    return;
  }
  set<pair<int,int>, greater<pair<int,int> > > s;
  int sum=0;
  pair<int,int> tmp, tmp2;

  for(int i=0; i<n; i++){
    s.insert(mp(p[i], i));
    sum+=p[i];
  }
  while(sum!=2){
    tmp=*s.begin();
    cout << char('A'+tmp.second) << ' ';
    s.erase(s.begin());
    s.insert(mp(tmp.first-1, tmp.second));
    sum--;
    // cout << '\n';
    // for(auto xx: s){
    //   cout << xx.first << ' ' << xx.second;
    // }
    // cout << '\n';
  }
  tmp=*s.begin();
  s.erase(s.begin());
  tmp2=*s.begin();
  s.erase(s.begin());
  cout << char('A'+tmp.second) << char('A'+tmp2.second) << '\n';
}

int main(){
  int T;
  cin >> T;
  for(int i=1; i<=T; i++){
    read();
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}