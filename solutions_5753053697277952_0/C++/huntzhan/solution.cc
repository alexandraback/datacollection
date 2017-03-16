// {{{ $VIMCODER$ <-----------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// }}}

const string kInputFilename = "input.txt";
const string kOutputFilename = "output.txt";

ifstream fin(kInputFilename);
ofstream fout(kOutputFilename);


char ToParty(int idx) {
  return 'A' + idx;
}


int main() {
  int T;
  fin >> T;

  for (int case_idx = 1; case_idx <= T; ++case_idx) {
    int N;
    fin >> N;

    vector<int> senators_count(N, 0);
    int total = 0;
    for (int i = 0; i < N; ++i) {
      fin >> senators_count[i];
      total += senators_count[i];
    }

    fout << "Case #" << case_idx << ":";
    while (total > 0) {
      // 1. find the top 2 parties.
      int top1_party = -1, top2_party = -1;
      for (int i = 0; i < N; ++i) {
        if (senators_count[i] == 0) {
          continue;
        }
        if (top1_party == -1
            || senators_count[top1_party] < senators_count[i]) {
          top2_party = top1_party;
          top1_party = i;
        } else if (
            top2_party == -1
            || senators_count[top2_party] < senators_count[i]) {
          top2_party = i;
        }
      }

      // two plans:
      // 1. remove 1 top1_party.
      // 2. remove 1 top1_party, 1 top2_party.
      // --3. remove 2 top1_party.
      fout << " ";
      if (senators_count[top2_party] > (total - 1) / 2) {
        // case 2.
        fout << ToParty(top1_party) << ToParty(top2_party);

        --senators_count[top1_party];
        --senators_count[top2_party];
        total -= 2;
      } else {
        // case 1.
        fout << ToParty(top1_party);

        --senators_count[top1_party];
        total -= 1;
      }
    }
    fout << endl;
  }

  fout.close();
}
