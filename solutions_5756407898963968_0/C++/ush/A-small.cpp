
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define ALLOF(s) ((s).begin()), ((s).end())

typedef long long ll;



int main(void) {
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
    set<int> ss;
    REP(i, 16)
      ss.insert(i+1);
    
    REP(t, 2){
      int r;
      cin >> r;
      r--;
      REP(i, 4){
	REP(j, 4){
	  int v;
	  cin >> v;
	  if(i != r){
	    ss.erase(v);
	  }
	}
      }
    }
    
    cout << "Case #" << (iCase+1) << ": ";
    if(ss.size() == 0){
      cout << "Volunteer cheated!" << endl;
    }else if(ss.size() > 1u){
      cout << "Bad magician!" << endl;
    }else{
      cout << *ss.begin() << endl;
    }
  }
  
  return 0;
}
