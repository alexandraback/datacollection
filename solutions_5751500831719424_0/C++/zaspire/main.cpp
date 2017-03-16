#include <gmpxx.h>
//#include <gtk/gtk.h>
//#include <cairo.h>

#include "shelly.hpp"

using namespace std;
using namespace shelly;

string RemoveDup(const string &s) {
  string res;
  char last = '\n';
  for (char c: s) {
    if (c == last)
      continue;
    res.push_back(c);
    last = c;
  }

  return res;
}

int work(const vector<string> &all) {
  vector<string> n;
  vector<int> c;
  if (all[0].empty())
    return 0;
  char C = all[0][0];
  int mn = all[0].size(), mx = 0;
  for (const string &s: all) {
    int i = 0;
    for (size_t j = 0; j < s.size(); j++) {
      if (C == s[j]) {
        i++;
        continue;
      }
      break;
    }
    c.push_back(i);
    if (i > mx)
      mx = i;
    if (i < mn)
      mn = i;
    n.push_back(s.substr(i));
  }
  int res = INT32_MAX;
  for (int i = mn; i <= mx; i++) {
    int t = 0;
    for (int j: c) {
      t += abs(j - i);
    }
    if (t < res)
      res = t;
  }
  return work(n) + res;
}

int main(int argc, char **argv) {
  freopen("input.txt", "r", stdin);
//  gtk_init(&argc, &argv);

  int T;
  cin >> T;
  for (int TT = 1; TT <= T; TT++) {
    int N;
    cin >> N;
    vector<string> all;
    while (N--) {
      string a;
      cin >> a;
      all.push_back(a);
    }
    string t = RemoveDup(all[0]);
    bool b = true;
    for (const string &s: all) {
      if (RemoveDup(s) == t)
        continue;
      b = false;
    }
    if (!b) {
      cout << Format("Case #%0: Fegla Won", TT) << endl;
      continue;
    }
    cout << Format("Case #%0: %1", TT, work(all)) << endl;
  }
  return 0;
}
