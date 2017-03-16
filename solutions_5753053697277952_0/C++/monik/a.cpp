#include <algorithm>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <cstring>

#define SIZE(s) ((int)((s).size()))
#define FOREACH(it,vec) for(typeof((vec).begin())it=(vec).begin();it!=(vec).end();++it)
#define REP(i,n) for(int i=0;i<(int)(n);++i)

using namespace std;

int n, T, N;

struct cmp {
  bool operator() (const pair<int,int>& a, const pair<int,int>& b) const{
    if (a.first != b.first) return (a.first > b.first);
    return a.second < b.second;
  }
};

int main(void) {
  cin >> T;
  REP(t, T) {
    cout << "Case #" << t+1 << ": ";
    cin >> N;
    set<pair<int, int>, cmp> P;
    int sum = 0;
    REP(n, N) {
      int p;
      cin >> p;
      sum += p;
      P.insert(make_pair(p,n));
    }

    while(sum > 0) {
      if (SIZE(P) != 2 && sum > 2) {
        pair<int,int> p = *P.begin(); P.erase(P.begin());
        cout << (char)(p.second + 'A') << " ";
        --sum;
        if (p.first > 1) P.insert(make_pair(p.first-1, p.second));
      }
      else {
        pair<int, int> p1 = *P.begin(); P.erase(P.begin());
        pair<int, int> p2 = *P.begin(); P.erase(P.begin());

        cout << (char)(p1.second + 'A') << (char)(p2.second + 'A') << " ";
        sum -= 2;
        if (p1.first > 1) P.insert(make_pair(p1.first-1, p1.second) );
        if (p2.first > 1) P.insert(make_pair(p2.first-1, p2.second) );
      }
    }
    cout << endl;
  }
  return 0;
}
