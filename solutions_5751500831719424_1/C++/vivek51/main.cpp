#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

string uniquify(string F)
{
    string s; char prev;
    for (int i = 0; i < (int)F.size(); i++) {
      char c = F[i];
      if (i == 0) {
        s += c;
      } else if (c != prev) {
        s += c;
      }
      prev = c;
    }
  return s;
}

int D[127][127];

int main()
{
  int T;
  scanf ("%d", &T);

  for (int Ti = 1; Ti <= T; Ti++) {
    int N;
    scanf("%d", &N);
    vector<string> A;
    for (int i = 1; i <= N; i++) {
      string s;
      cin >> s;
      A.push_back(s);
    }

    string ustr = uniquify(A[0]);

    int fail = 0;
    for (int i = 1; i < N; i++) {
      string t = uniquify(A[i]);
      if (ustr != t) {
        fail = 1; break;
      }
    }
    
    if (fail) {
      printf("Case #%d: Fegla Won\n", Ti);
      continue;
    }
    memset(D, 0, sizeof(D));

    for (int i = 0; i < (int)A.size(); i++) {
      string s = A[i];

      char prev;
      int count = 0, k = 0;
      for (int j = 0; j < (int)s.size(); j++) {
        if (j == 0) {
          count++; prev = s[j];
        } else if (prev == s[j]) {
          count++;
        } else {
          D[i][k] = count;
          k++; prev = s[j];
          count = 1;;
        }
      }
      D[i][k] = count;
    }
    int ans = 0;
    int sz = ustr.size();
    for (int i = 0; i < sz; i++) {
      vector<int> B;
      for (int j = 0; j < N; j++) {
        B.push_back(D[j][i]);
      }
      sort(B.begin(), B.end());

      int cost = 0;
      int m = B[N/2];
      for (int j = 0; j < N; j++) {
        cost += abs(D[j][i] - m);
      }

      ans += cost;
    }

    printf("Case #%d: %d\n", Ti, ans);
  }

  return 0;
}
