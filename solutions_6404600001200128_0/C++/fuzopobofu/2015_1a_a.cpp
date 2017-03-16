#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iomanip>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <string.h>

using namespace std;

void solve() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    std::vector<int> vv(N);    for (int i = 0; i < N; i++) { cin >> vv[i]; }
    
    int result1 = 0;
    int prev = vv[0];
    for (int i = 1; i < N; i++) {
      result1 += max(0, prev - vv[i]);
      prev = vv[i];
      // cerr << " " << result1 << endl;
    }

    int m = 0;
    prev = vv[0];
    for (int i = 1; i < N; i++) {
      int temp = prev - vv[i];
      prev = vv[i];
      m = max(m, temp);
    }
//     cerr << " m=" << m << endl;
    int result2 = 0;
    for (int i = 0; i < N-1; i++) {
      result2 += min(m, vv[i]);
//       cerr << " " << result2 << endl;
    }

    std::cout << "Case #" << (t+1) << ": " << result1 << " " << result2 << std::endl;
  }
}

int main(int argc, char *argv[])
{
  solve();
  return 0;
}

