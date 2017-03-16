#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int T, N;

int main(){ 
  cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> N;
    vector <string> S(N);
    for (int i=0; i<N; i++)
      cin >> S[i];

    string s;
    for (int i=0; i<S[0].length(); i++)
      if (i == 0 || S[0][i-1] != S[0][i])
        s += S[0][i];

    bool Fegla = false;
    int moves = 0;
    vector <int> ind(N, 0);
    for (int c=0; c<s.length() && !Fegla; c++) {
      vector <int> cnt(N, 0);
      int mc = 0;
      for (int i=0; i<N; i++)
        if (ind[i] >= S[i].length() || S[i][ind[i]] != s[c]) {
          Fegla = true;
          break;
        } else {
          while (ind[i] < S[i].length() && S[i][ind[i]] == s[c])
            ind[i]++, cnt[i]++;
          if (cnt[i] > mc) mc = cnt[i];
        }

      if (!Fegla) {
        int mm = 100000;
        for (int m=1; m <= mc; m++) {
          int cm = 0;
          for (int i=0; i<N; i++)
            cm += abs(m-cnt[i]);
          if (cm < mm) mm = cm;
        }
        moves += mm;
      }
    }

    for (int i=0; i<N; i++)
      if (ind[i] != S[i].length())
        Fegla = true;

    cout << "Case #" << t << ": ";
    if (Fegla) 
      cout << "Fegla Won" << endl;
    else 
      cout << moves << endl;
  }
}

