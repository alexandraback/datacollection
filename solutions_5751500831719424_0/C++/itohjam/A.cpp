#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#include <complex>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <cassert>
using namespace std;

typedef long long ll;
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
bool ISINT(double x){return fabs(x-(int)round(x))<EPS;}
bool ISEQ(double x,double y){return fabs(x-y)<EPS;}
string itos(ll x){stringstream ss;ss<<x;return ss.str();}
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin();itr!=c.end();itr++)

int n;
string t[102];

string makeP(){
  string res = "";

  for(int i = 0; i < t[0].size(); i++){
    int j = i;
    res += t[0][i];

    while(j < t[0].size()){
      if(t[0][j] != t[0][i]) break;
      j++;
    }

    i = j - 1;
  }

  return res;
}

vector<int> cnt[102];

vector<int> getCnt(string s, string p){
  vector<int> res;
  int pi = 0;

  for(int i = 0; i < s.size(); i++){
    if(p.size() <= pi || p[pi] != s[i]){
      return vector<int>();
    }
    pi++;

    int j = i;

    while(j < s.size()){
      if(s[i] != s[j]) break;
      j++;
    }

    res.push_back(j - i);
    i = j - 1;
  }

  if(pi != p.size()){
    return vector<int>();
  }

  return res;
}

void solve(){
  string p;
  p = makeP();

  for(int i = 0; i < n; i++){
    cnt[i] = getCnt(t[i], p);

    if(cnt[i].size() == 0){
      cout << "Fegla Won" << endl;
      return;
    }
  }

  int res = 0;

  for(int i = 0; i < p.size(); i++){
    int minCost = INT_MAX;

    for(int j = 1; j <= 100; j++){
      int cost = 0;

      for(int k = 0; k < n; k++){
        cost += abs(cnt[k][i] - j);
      }
      minCost = min(minCost, cost);
    }
    res += minCost;
  }

  cout << res << endl;
}

int main(void){
  int T;
  cin >> T;

  for(int CASE = 1; CASE <= T; CASE++){
    cout << "Case #" << CASE << ": ";

    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> t[i];
    }
    solve();
  }
}
