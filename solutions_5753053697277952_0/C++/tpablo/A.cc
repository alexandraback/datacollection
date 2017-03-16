#include <bits/stdc++.h>

using namespace std;


void test() {
  static int c;
  cout << "Case #" << ++c << ": ";
  
  int n;
  cin >> n;
  
  vector<int> P(n);
  for(int i = 0; i < n; ++i) cin >> P[i];
  
  set< pair<int, int> > S;
  for(int i = 0; i < n; ++i) {
    S.insert(make_pair(-P[i], i));
  }
  
  while(not S.empty()) {
    pair<int, int> p1 = *S.begin();
    pair<int, int> p2 = *S.rbegin();
    
    if(S.size() == 2 and p1.first == p2.first) {
      for(int i = 0; i < -p1.first; ++i) {
        cout << char('A' + p1.second) << char('A' + p2.second) << ' ';
      }
      S.clear();
    } else {
      S.erase(S.begin());
      cout << char('A' + p1.second) << ' ';
      p1.first += 1; // cuz negative
      if(p1.first != 0) S.insert(p1);
    }
  }
  
  cout << '\n';
}


int main() {
  int t;
  cin >> t;
  
  while(t --> 0) test();
  
  return 0;
}
