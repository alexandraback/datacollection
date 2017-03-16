#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

int solve(const vector<int>& v){
  int ret = 0;
  REP(i,1,v.size()){
    if(v[i-1]-v[i] > 0) ret += v[i-1] - v[i];
  }
  return ret;
}
int solve2(const vector<int>& v){
  int ret = 100000000;

  rep(r,10001){
    int sum = 0;
    bool flg = true;
    REP(i,1,v.size()){
      if(v[i-1]-v[i] > 0){
        if(v[i-1]-v[i] > r){
          flg = false;
          continue;
        }
      }
      sum += min(r, v[i-1]);
    }
    if(flg && ret > sum){
      ret = sum;
    }
  }
  return ret;
}

int main(){
  int T;

  cin >> T;
  rep(t,T){
    int N, tmp;
    vector<int> v;

    cin >> N;
    rep(i,N){
      cin >> tmp;
      v.push_back(tmp);
    }
    cout << "Case #" << t+1 << ": " << solve(v) << " " << solve2(v) << endl;
  }
  
  return 0;
}
