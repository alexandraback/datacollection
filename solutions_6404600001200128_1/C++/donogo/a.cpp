#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <list>

using namespace std;

vector <int> mush(vector <int> M) {
  int   N = M.size();
  int i;
  int largest_drop;
  int acc_drop;
  int acc_drop2;
  int drop_cnt;
  int drop;
  vector <int> res;

  largest_drop = 0;
  acc_drop = acc_drop2 = 0;
  drop_cnt = 0;
  
  for (i = 1; i < N; i++) {
    drop = M[i-1] - M[i];
    if (drop > 0) {
      drop_cnt++;
      acc_drop += drop;
      if (drop > largest_drop) {
	largest_drop = drop;
      }
    }
  }
  res.push_back(acc_drop);

  for (i = 1; i < N; i++) {
    acc_drop2 += min(largest_drop, M[i-1]);
  }

  res.push_back(acc_drop2);

  return res;
}



int main(void) {
  int T, t;
  int B;
  int N;
  int k;
  vector <int> res;

  cin >> T;

  for (t = 1; t <= T; t++) {
    cin >> N;
    vector <int> M;
    for (k = 0; k < N; k++) {
      int m;
      cin >> m;
      M.push_back(m);
    }

    res = mush(M);
    
    cout << "Case #" << t << ": " << res[0] << " " << res[1]  << endl;

  }
  return 0;
}
