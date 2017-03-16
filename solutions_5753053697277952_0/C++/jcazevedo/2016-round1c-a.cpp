#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N, tot = 0;
    vector<int> parties;
    cin >> N;
    parties.assign(N, 0);
    for (int i = 0; i < N; i++) {
      cin >> parties[i];
      tot += parties[i];
    }
    cout << "Case #" << t << ":";
    while (tot > 0) {
      string current = "";
      int best = 0, besti = 0;
      for (int i = 0; i < N; i++) {
        if (parties[i] > best) {
          best = parties[i];
          besti = i;
        }
      }
      current += (besti + 'A');
      parties[besti]--;
      tot--;
      best = 0; besti = 0;
      for (int i = 0; i < N; i++) {
        if (parties[i] > best) {
          best = parties[i];
          besti = i;
        }
      }
      bool valid = true;
      for (int i = 0; i < N; i++) {
        if (i == besti)
          continue;
        if (parties[i] > (tot - parties[i] - 1)) {
          valid = false;
          break;
        }
      }
      if (valid) {
        current += (besti + 'A');
        parties[besti]--;
        tot--;
      }
      cout << " " << current;
    }
    cout << endl;
  }
  return 0;
}
