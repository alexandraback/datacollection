#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
#define REP(i,n) for(int _n=n, i=0;i<_n;i++)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define ALL(x)   (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define PB push_back

int r[10][10];
set<int> s;

int main() {
  int Ts;
  cin>>Ts;
  FOR(cs, 1, Ts) {
    int x, y;
    REP(i,16) s.insert(i+1);
    cin >> x;
    REP(i,4) REP(j,4) {
      cin>>y;
      if (i+1!=x) s.erase(y);
    }
    cin >> x;
    REP(i,4) REP(j,4) {
      cin>>y;
      if (i+1!=x) s.erase(y);
    }
    cout << "Case #" << cs << ": ";
    if (s.size()==1) {
      cout<<(*s.begin());
    } else if(s.size()==0) {
      cout<<"Volunteer cheated!";
    } else {
      cout<<"Bad magician!";
    }
    cout << endl;
  }
  return 0;
}
