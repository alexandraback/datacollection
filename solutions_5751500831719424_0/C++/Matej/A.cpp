#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, L;
string S;
vector<char> C, C0;
vector< vector<int> > counts;

int main()
{
  int T;
  cin >> T;
  for (int Ti = 1; Ti <= T; Ti++) {
    // init
    C0.clear();
    counts.clear();
      
    // input
    cin >> N;
    getline(cin, S);
    
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      getline(cin, S);
      
      // build character sequence
      C.clear();
      for (unsigned int j = 0; j < S.length(); ++j)
          if (j == 0 || S[j] != S[j - 1])
            C.push_back(S[j]);
      if (i == 0) {
        C0 = C;
        L = C0.size();
        for (int j = 0; j < L; ++j)
          counts.push_back( vector<int>() );
      }
      if (C0.size() != C.size() || (!equal(C0.begin(), C0.end(), C.begin())) ) {
        ok = false;
        break;
      }
           
      // fill counts
      int count = 1;
      int letter = 0;
      for (unsigned int j = 0; j < S.length(); ++j)
        if (j == S.length() - 1 || S[j] != S[j + 1]) {
          counts[letter].push_back(count);
          count = 1;
          letter++;
        }
        else
          count++;
    }
    
    // failed
    if (!ok) {
      cout << "Case #" << Ti << ": Fegla Won" << endl;
      continue;
    }
    
    // calculate minimum number of moves
    int mid = N / 2;
    int totalCost = 0;
    for (int i = 0; i < L; ++i) {
      /*
      cout << i << ": (" << counts[i].size() << ") ";
      for (int j = 0; j < N; ++j)
        cout << counts[i][j] << " ";
      cout << endl;
      */
      // calculate median
      sort( counts[i].begin(), counts[i].end() );
      int midValue = counts[i][mid];
      for (int j = 0; j < mid; ++j)
        totalCost += (midValue - counts[i][j]);
      for (int j = mid + 1; j < N; ++j)
        totalCost += (counts[i][j] - midValue);
    }
    cout << "Case #" << Ti << ": " << totalCost << endl;
  }
  return 0;
}
