#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI;
typedef pair<int, int> PII; 

void solve(){
  int x, y; 
  set<int> f, s; 
  
  cin >> x; 
  REP(i, 4) REP(j, 4){
    int n;
    cin >> n; 
    if(i == x-1) f.insert(n); 
  }
  
  cin >> y; 
  REP(i, 4) REP(j, 4){
    int n;
    cin >> n; 
    if(i == y-1) s.insert(n); 
  }
  
  //cout << "x=" << x << " y=" << y << endl;
  
  vector<int> r(4);
  vector<int>::iterator it = set_intersection(f.begin(), f.end(), s.begin(), s.end(), r.begin());  
  r.resize(it - r.begin()); 
  
  //REP(i, r.size()) cout << " " << r[i];
  
  if(r.size() == 0) cout << "Volunteer cheated!";  
  if(r.size() == 1) cout << r[0]; 
  if(r.size() > 1) cout << "Bad magician!"; 
}

int main(){
  int T;
  cin >> T;
  REP(t, T) {
    cout << "Case #" << t+1 << ": ";
    solve(); 
    cout << endl; 
  } 
  return 0; 
}
