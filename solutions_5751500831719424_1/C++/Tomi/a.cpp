#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main() {
  int TT;
  scanf("%d", &TT);
  for (int tc = 1; tc <= TT; tc++) {
    int N;
    scanf("%d", &N);

    vector<char> letters;
    vector<vector<int> > counts(N);

    vector<string> dat(N);

    bool lettersok = true;

    for (int i = 0; i < N; i++) {
      char buf[200];
      scanf("%s", buf);
      dat.push_back(buf);

      vector<char> myletters;

      for (int j = 0; buf[j]; j++) {
        if (j == 0 || buf[j] != buf[j-1]) {
          myletters.push_back(buf[j]);
          counts[i].push_back(0);
        }
        counts[i][counts[i].size()-1]++;
      }
      if (i == 0) letters = myletters;
      if (letters != myletters) {
        lettersok = false;
        break;
      }
    }

    if (!lettersok) {
      printf("Case #%d: Fegla Won\n", tc);
      continue;
    }

    long long R = 0;
    for (int w = 0; w < letters.size(); w++) {
      int bestoff = 111111111;
      for (int c = 1; c <= 100; c++) {
        int myoff = 0;
        for (int i = 0; i < N; i++) myoff += llabs(counts[i][w] - c);
        if (myoff < bestoff) bestoff = myoff;
      }
      R += bestoff;
    }
    printf("Case #%d: %lld\n", tc, R);
  }
}
