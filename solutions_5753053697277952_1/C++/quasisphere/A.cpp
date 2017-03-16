#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<utility>
#include<iomanip>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);

  int64_t T;
  cin >> T;

  for(int64_t t=1;t<=T;t++) {
    int64_t N;
    cin >> N;
    vector<pair<int64_t,char>> P(N);
    for(int64_t i=0;i<N;i++) {
      cin >> P[i].first;
      P[i].second=i+'A';
    }
    sort(P.begin(), P.end());

    cout << "Case #" << t << ": ";
    while(P[P.size()-1].first > P[P.size()-2].first) {
      if(P[P.size()-1].first > P[P.size()-2].first+1) {
        P[P.size()-1].first-=2;
        cout << P[P.size()-1].second << P[P.size()-1].second << " ";
      } else {
        P[P.size()-1].first--;
        cout << P[P.size()-1].second << " ";
      }
    }
    for(int64_t i=0;i<P.size()-2;i++) {
      while(P[i].first > 0) {
        P[i].first--;
        cout << P[i].second << " ";
      }
    }
    while(P[P.size()-1].first > 0) {
      cout << P[P.size()-1].second << P[P.size()-2].second << " ";
      P[P.size()-1].first--;
      P[P.size()-2].first--;
    }
    cout << "\n";
  }

  return 0;
}

