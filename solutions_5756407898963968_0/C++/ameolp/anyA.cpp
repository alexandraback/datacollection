#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);

int main()
{
  int t;
  cin >> t;
  
  for(int tcase = 1; tcase <= t; tcase++) {
    int r[17] = {0}, fq, sq, x;
    cin >> fq;
    for(int i = 1; i <= 4; i++) {
      for(int j = 1; j <= 4; j++) {
        cin >> x;
        if(i == fq) {
          r[x] = i;
        }
      }
    }
    cin >> sq;
    for(int i = 1; i <= 4; i++) {
      for(int j = 1; j <= 4; j++) {
        cin >> x;
        if(i == sq && r[x] > 0) {
          r[x] = i;
        } else {
          r[x] = 0;
        }
      }
    }

    vector<int> cd;
    for(int i = 1; i <= 16; i++) {
      if(r[i] > 0) {
        cd.push_back(i);
      }
    }

    printf("Case #%d: ", tcase);
    if(cd.empty()) {
      cout << "Volunteer cheated!" << endl;
    } else if(cd.size() > 1) {
      cout << "Bad magician!" << endl;
    } else {
      cout << cd[0] << endl;
    }
  }

  return 0;
}
// Google Code Jam