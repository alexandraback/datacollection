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

int main(int argc, char *argv[])
{
  int T, row, card;

  scanf("%d", &T);

  for(int t = 0; t < T; ++t) {
    vector<bool> possible(16, true);
    scanf("%d", &row);
    --row;

    for(int i = 0; i < 4; ++i) {
      for(int j = 0; j < 4; ++j) {
        scanf("%d", &card);
        if(row != i) possible[card-1] = false;
      }
    }

    scanf("%d", &row);
    --row;

    for(int i = 0; i < 4; ++i) {
      for(int j = 0; j < 4; ++j) {
        scanf("%d", &card);
        if(row != i) possible[card-1] = false;
      }
    }

    printf("Case #%d: ", t+1);

    int ccount = count(possible.begin(), possible.end(), true);

    if(ccount > 1) {
      printf("Bad magician!\n");
    } else if(ccount == 0) {
      printf("Volunteer cheated!\n");
    } else {
      auto it = find(possible.begin(), possible.end(), true);
      printf("%d\n", (it - possible.begin()) + 1);
    }

  }

  return 0;
}
