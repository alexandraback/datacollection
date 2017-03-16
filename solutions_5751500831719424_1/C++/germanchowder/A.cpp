#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  long long T;
  long long N;
  cin >> T;

  for (long long ii = 1; ii <= T; ii++) {
    cout << "Case #" << ii << ": ";
    cin >> N;
    string s[N], atype = "";
    long long ret = 0;

    for (long long jj = 0; jj < N; jj++) {
      cin >> s[jj];
    }

    int counts[100][100] {};
    char c = s[0][0];
    atype += c;
    for (long long jj = 1; jj < s[0].size(); jj++) {
      if (s[0][jj] != c) {
        c = s[0][jj];
        atype += c;
      }
    }

    int al = atype.size();
    for (long long jj = 0; jj < N; jj++) {
      int kk = 0;
      if (s[jj][0] != atype[0]) {
        cout << "Fegla Won" << endl;
        goto done;
      }

      for (auto c : s[jj]) {
        if (c == atype[kk]) {
          counts[jj][kk]++;
        }
        else if (c != atype[kk]) {
          kk++; 
          if (kk == al || c != atype[kk]) {
            cout << "Fegla Won" << endl;
            goto done;
          }
          counts[jj][kk]++;
        }
      }
      if (kk != al-1) {
        cout << "Fegla Won" << endl;
        goto done;
      }
    }

    for (long long jj = 0; jj < al; jj++) {
      int best = 10001;
      for (long long kk = 0; kk < N; kk++) {
        int n = 0;
        for (long long ll = 0; ll < N; ll++) {
          n += abs(counts[kk][jj] - counts[ll][jj]);
        }
        best = min(best, n);
      }
      ret += best;
    }
    cout << ret << endl;
    
    done: ;
  }
}
