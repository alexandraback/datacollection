#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <strings.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <climits>
#include <assert.h>

using namespace std;

#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

int main() {
  int T;
  scanf("%d", &T);
  FOR(test,1,T+1) {
    vector<int> occ(16,0);
    int a, p;
    scanf("%d", &a);
    FOR(i,1,5) FOR(j,1,5) {
      scanf("%d", &p);
      if (i == a) occ[p-1] ++;
    }
    scanf("%d", &a);
    FOR(i,1,5) FOR(j,1,5) {
      scanf("%d", &p);
      if (i == a) occ[p-1] ++;
    }
    int cpt = 0, sol = -1;
    FOR(i,0,16) if (occ[i] == 2) {
      cpt++;
      sol = i + 1;
    }
    printf ("Case #%d: ", test);
    if (cpt == 0)
      printf ("Volunteer cheated!\n");
    else if (cpt != 1) 
      printf ("Bad magician!\n");
    else
      printf("%d\n", sol);
  }
  return 0;
}
