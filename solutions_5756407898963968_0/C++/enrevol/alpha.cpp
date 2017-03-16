#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int a[5][5];
int b[5][5];

int main() {
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
  //std::ios::sync_with_stdio(0);
  //std::cin.tie(0);
  int tt, nc = 0;
  scanf("%d", &tt);
  while (tt--) {
    printf("Case #%d: ", ++nc);
    int ax;
    scanf("%d", &ax);
    for (int i = 1; i <= 4; ++i)
      for (int j = 1; j <= 4; ++j)
        scanf("%d", a[i] + j);
    int bx;
    scanf("%d", &bx);
    for (int i = 1; i <= 4; ++i)
      for (int j = 1; j <= 4; ++j)
        scanf("%d", b[i] + j);    
    std::set<int> st;
    for (int i = 1; i <= 4; ++i)
      st.insert(a[ax][i]);
    int cnt = 0;
    int k = -1;
    for (int i = 1; i <= 4; ++i) {
      if (st.count(b[bx][i])) {
        ++cnt;
        k = b[bx][i];
      }      
    }
    if (cnt == 1) {
      printf("%d\n", k);
    } else if (cnt == 0) {
      puts("Volunteer cheated!");
    } else {
      puts("Bad magician!");      
    }
  }
}
