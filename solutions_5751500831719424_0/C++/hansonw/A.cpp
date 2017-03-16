#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int T; cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    int N; cin >> N;
    vector<vector<int> > counts;
    string pattern;
    int sum = 0;

    for (int i = 0; i < N; i++) {
      string s; cin >> s;
      vector<int> cnt;
      string uniq;
      int cc = 0;
      for (int j = 0; j < s.size(); j++) {
        if (j && s[j] != s[j-1]) {
          cnt.push_back(cc);
          uniq += s[j-1];
          cc = 0;
        } else {
          cc++;
        }
      }
      cnt.push_back(cc);
      uniq += s[s.size()-1];

      if (pattern.size() && uniq != pattern) {
        printf("Case #%d: Fegla Won\n", tt);
        goto fail;
      }
      pattern = uniq;
      
      counts.push_back(cnt);
    }

    for (int i = 0; i < pattern.size(); i++) {
      vector<int> hist;
      for (int j = 0; j < counts.size(); j++) {
        hist.push_back(counts[j][i]);
      }
      sort(hist.begin(), hist.end());
      int median = hist[hist.size()/2];
      for (int j = 0; j < hist.size(); j++) {
        sum += abs(hist[j] - median);
      }
    }

    printf("Case #%d: %d\n", tt, sum);

fail:;
  }
}
