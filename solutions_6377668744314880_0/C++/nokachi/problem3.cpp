#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

vector<int> solve(vector<pair<int, int>> ps) {
  int N = ps.size();
  vector<int> log;
  for (int i = 0; i< N; i++) {
    int entry = N-2 > 0 ? N-2 : 0;
    for (int j = 0; j < N; j++) {
      if (j==i) continue;
      // find out how many trees to the left and to the right, choose min
      int right = 0, left = 0;
      for (int k = 0; k<N; k++) {
        if (k==i || k==j) {
          continue;
        }
        long long x1 = ps[i].first, y1 = ps[i].second;
        long long x2 = ps[j].first, y2 = ps[j].second;
        long long x3 = ps[k].first, y3 = ps[k].second;
        long long prod  = (x3-x1)*(y2-y1) - (x2-x1)*(y3-y1);
        if (prod < 0) {
          left++;
        }
        if (prod > 0) {
          right++;
        }        
      }
      int q = right < left ? right : left;
      if (q < entry) {
        entry = q;
      }
    }
    log.push_back(entry);
  }
  return log;
}

int main(int argc, char *argv[]) {
  int ntest;
  cin >> ntest;
  for (int T = 0; T < ntest; T++) {
    int N;
    cin >> N;
    vector<pair<int, int>> ps;
    for (int i=0;i<N;i++) {
      int x,y;
      cin >> x;
      cin >> y;
      ps.push_back(make_pair(x, y));
    }
    vector<int> z = solve(ps);
    cout << "Case #"<< (T+1) <<":" <<endl;
    for (int i=0;i<z.size();i++) {
      cout << z[i]<<endl;
    }
  }
  return 0;
}

