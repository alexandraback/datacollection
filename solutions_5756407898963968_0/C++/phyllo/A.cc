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


int main(){
  int T;
  cin >> T;

  for(int t=0; t<T; t++){
    int c1, c2, v;
    vector<int> tmp1(4, 0), tmp2(4, 0);

    cin >> c1;
    for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
        if(c1 == i+1) cin >> tmp1[j];
        else cin >> v;
      }
    }
    cin >> c2;
    for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
        if(c2 == i+1) cin >> tmp2[j];
        else cin >> v;
      }
    }

    int n = 0, m = 0;
    for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
        if(tmp1[i] == tmp2[j]){
          n++;
          m = tmp1[i];
        }
      }
    }
    if(n == 1){
      cout << "Case #" << t+1 << ": " << m << endl;
    }
    else if(n == 0){
      cout << "Case #" << t+1 << ": Volunteer cheated!" << endl;
    }else{
      cout << "Case #" << t+1 << ": Bad magician!" << endl;
    }
  }
  
  return 0;
}
