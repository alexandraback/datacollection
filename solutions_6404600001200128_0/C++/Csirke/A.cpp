#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long lglg;

int main()
{
  int T;
  scanf("%d", &T);

  for(int t = 0; t < T; ++t) {
    printf("Case #%d: ", t+1);

    int n;
    scanf("%d", &n);

    vector<int> m(n, 0);

    int y = 0, z = 0;

    for(int i = 0; i < n; ++i) {
      scanf("%d", &(m[i]));
    }

    for(int i = 1; i < n; ++i) {
      if(m[i] < m[i-1]) {
        y += m[i-1] - m[i];
      }
    }

    int speed = 0;

    for(int i = 1; i < n; ++i) {
      speed = max(speed, m[i-1] - m[i]);
    }

    for(int i = 0; i < n-1; ++i) {
      z += min(speed, m[i]);
    }

    printf("%d %d\n", y, z);
  }

  return 0;
}
