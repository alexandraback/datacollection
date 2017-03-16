#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
  int T;

  cin >> T;

  for (int cas = 1; cas <= T; cas++) {
    int N;

    cin >> N;
    
    vector<string> inps;
    for (int i = 0 ; i < N; i++) {
      string s;
      cin >> s;
      inps.push_back(s);
    }

    vector<string> result;
    vector<vector<int> > count;

    for (int j = 0; j < N; j++) {
      char prev = 0;
      result.push_back("");
      count.push_back(vector<int>());
      for (int i = 0; i < inps[j].size(); i++) {
        if (inps[j][i] != prev) {
          result.back() += inps[j][i];
          count.back().push_back(0);
          prev = inps[j][i];
        } else {
          count.back().back()++;
        }
      }
    }

    bool fail = false;
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (result[i] != result[j]) {
          fail = true;
        }
      }
    }

    if (fail) {
      cout << "Case #" << cas << ": Fegla Won" << endl;
      continue;
    }

    int total = 0;
    for (int i = 0; i < count[0].size(); i++) {
      int minc = 100000;
      for (int j = 0; j < count.size(); j++) {
        int n = count[j][i];
        int t = 0;
        for (int k = 0; k < count.size(); k++) {
          t += abs(count[k][i] - n);
        }
        if (t < minc) minc = t;
      }
      total += minc;
    }

    cout << "Case #" << cas << ": " << total << endl;
  }

  return 0;
}
