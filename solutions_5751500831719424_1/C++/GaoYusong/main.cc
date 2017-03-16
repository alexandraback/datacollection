#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

typedef vector<pair<char, int> > v_string;
const int inf = 1 << 28;

v_string decode(string s)
{
  v_string ret;
  int cnt = 1;
  for (int i = 1; i <= s.length(); i++) {
    if (i < s.length() && s[i] == s[i - 1]) {
      cnt++;
    } else {
      ret.push_back(make_pair(s[i - 1], cnt));
      cnt = 1;
    }
  }
  return ret;
}

int check(const v_string &a, const v_string &b)
{
  int ret = inf;
  if (a.size() == b.size()) {
    ret = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i].first == b[i].first) {
        ret += abs(a[i].second - b[i].second);
      } else {
        ret = inf;
        break;
      }
    }
  }
  return ret;
}

int main()
{
  int T;

  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);

  cin >> T;

  for (int cn = 1; cn <= T; cn++) {
    int n;

    cin >> n;
    vector<v_string> aa(n);
    int len = -1;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      string tmp;
      cin >> tmp;
      aa[i] = decode(tmp);
      if (len == -1) {
        len = aa[i].size();
      } else {
        if (len != aa[i].size()) {
          ok = false;
        }
      }
    }
    int ans = 0;

    if (ok) {
      for (int i = 0; i < len; i++) {
        int ret = inf;
        for (int j = 0; j < n; j++) {
          int curr = 0;
          for (int k = 0; k < n; k++) {
            if (j != k) {
              if (aa[k][i].first == aa[j][i].first) {
                curr += abs(aa[k][i].second - aa[j][i].second);
              } else {
                ok = false;
                break;
              }
            }
          }
          if (!ok) {
            break;
          }
          ret = min(curr, ret);
        }
        if (!ok) {
          break;
        }
        ans += ret;
      }
    } 

    cout << "Case #" << cn << ": ";
    if (!ok) {
      cout << "Fegla Won" << endl;
    } else {
      cout << ans << endl;
    }
    
  }
  return 0;
}
