#include <bits/stdc++.h>

using namespace std;

string makeGood (string s) {
      string ans = "" + s[0];
      for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1])
                  ans += s[i];
      }
      return ans;
}

vector <int> getData (string s) {
      string temp = "" + s[0];
      vector <int> a;
      for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                  temp += s[i];
            } else {
                  a.push_back (temp.size());
                  temp = s[i];
            }
      }
      if (temp.size() != 0)
            a.push_back (temp.size());
      return a;
}

int solve (vector <int> a) {
      int mx = *max_element (a.begin(), a.end());
      int ans = (int) 1e9;
      for (int val = 0; val <= mx; val++) {
            int tot = 0;
            for (int i = 0; i < a.size(); i++) {
                  tot += abs (a[i] - val);
            }
            ans = min (ans, tot);
      }
      return ans;
}

int main() {
      freopen ("input.txt", "r", stdin);
      freopen ("output.txt", "w", stdout);

      int T, caseNo = 1;
      scanf ("%d", &T);
      while (T--) {
            int n;
            cin >> n;
            vector <string> a;
            vector <string> en;
            vector <vector <int> > data;
            for (int i = 0; i < n; i++) {
                  string s;
                  cin >> s;
                  a.push_back (s);
                  en.push_back (makeGood (s));
                  data.push_back (getData (s));
            }
            int ok = true;
            for (int i = 1; i < n; i++) {
                  if (en[i] != en[i - 1]) {
                        ok = false;
                        break;
                  }
            }
            if (ok) {
                  int ans = 0;
                  for (int i = 0; i < data[0].size(); i++) {
                        vector <int> v;
                        for (int j = 0; j < n; j++) {
                              v.push_back (data[j][i]);
                        }
                        ans += solve (v);
                  }
                  printf ("Case #%d: %d\n", caseNo ++, ans);
            } else {
                  printf ("Case #%d: Fegla Won\n", caseNo ++);
            }
      }

      return 0;
}
