#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> all_comb(int n, int k)
{
  vector<string> ret;
  if (n < k) {
    // ret.push_back(string(""));
    // return ret;
  } else if (k == 0) {
    string s("0", n);
    ret.push_back(s);
  } else {
    vector<string> ret1 = all_comb(n-1, k-1);
    for (int i = 0; i < ret1.size(); ++i) {
      string s = ret1[i] + "1";
      ret.push_back(s);
    }
    vector<string> ret2 = all_comb(n-1, k);
    for (int i = 0; i < ret2.size(); ++i) {
      string s = ret2[i] + "0";
      ret.push_back(s);
    }
    // return ret;
  }
  return ret;
}

int main()
{
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int r, c, n;
    cin >> r >> c >> n;

    vector<string> choices = all_comb(r*c, n);
    // for (int j = 0; j < choices.size(); ++j) {
    //   cout << choices[j] << endl;
    // }

    int ans = -1;
    for (int j = 0; j < choices.size(); ++j) {
      bool map[16][16];
      memset(map, 0, sizeof(map));
      // string c = choices[j];
      for (int k = 0; k < r*c; ++k) {
        if (choices[j][k] == '1') {
          int rr = k/c;
          int cc = k - rr*c;
          map[rr][cc] = true;
        }
      }
      int temp = 0;
      for (int rr = 0; rr < r; ++rr) {
        for (int cc = 0; cc < c; ++cc) {
          if (map[rr][cc]) {
            temp += (rr+1 < r && map[rr+1][cc]);
            temp += (cc+1 < c && map[rr][cc+1]);
          }
        }
      }
      if (ans == -1) {
        ans = temp;
      } else {
        ans = min(ans, temp);
      }
    }

    cout << "Case #" << i+1 << ": " << ans << endl;
    // for (int rr = 0; rr < r; ++rr) {

    // }

  }
  return 0;
}