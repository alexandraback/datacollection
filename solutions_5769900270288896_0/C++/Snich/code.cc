#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl; 


size_t r, c;
vector<vector<char> > house;

int ans;


void calc(size_t x, size_t y, int num_tenats) {
  if (y == c) {
    ++x;
    y = 0;
  }
  if (num_tenats == 0) {
    int cur = 0;
    for (size_t i = 0; i < r; ++i) {
      for (size_t j = 0; j < c; ++j) {
        if (house[i][j]) {
          if (i + 1 < r) cur += house[i + 1][j];
          if (j + 1 < c) cur += house[i][j + 1];
        }
      }
    }
    ans = min(ans, cur);
    return;
  } 
  if (x == r) return;
  house[x][y] = 1;
  calc(x, y + 1, num_tenats - 1);
  house[x][y] = 0;
  //if (int(r * c - (x * c + y + 1)) >= num_tenats) calc(x, y + 1, num_tenats);
  calc(x, y + 1, num_tenats);
}


int main()
{
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": ";

        int num_tenats;
        cin >> r >> c >> num_tenats;
        house.assign(r, vector<char>(c, 0));
        ans = std::numeric_limits<int>::max();
        calc(0, 0, num_tenats);
        cout << ans;

        cout << endl;
    }
    return 0;
}
