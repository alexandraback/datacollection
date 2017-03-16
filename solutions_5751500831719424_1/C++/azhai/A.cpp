#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N_MAX = 200;
const int LEN_MAX = 200;
int N;
string words[N_MAX];
int counts[N_MAX][LEN_MAX];

int K; // number of blocks
char trace[LEN_MAX];

void init() {
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> words[i];

  K = 0;
  char cur = '.';
  for (int i = 0; i < words[0].length(); i++) {
    char c = words[0][i];
    if (c != cur) {
      cur = c;
      trace[K++] = c;
    }
  }
}

// returns false if Fegla Won
bool compute_counts() {
  for (int i = 0; i < N; i++) {
    string w = words[i];
    char cur = '.';
    int k = 0;
    for (int j = 0; j < w.length(); j++) {
      if (w[j] != cur) { // new letter
        if (k >= K || w[j] != trace[k])
          return false;
        counts[i][k++] = 1;
        cur = w[j];
      } else {
        counts[i][k - 1]++;
      }
    }
    if (k != K)
      return false;
  }
  return true;
}

void solve_case(int t) {
  init();
  bool success = compute_counts();
  if (!success) {
    cout << "Case #" << t << ": Fegla Won\n";
    return;
  }

  int min_cost = 0;
  for (int i = 0; i < K; i++) {
    int sorted_counts[N];
    for (int j = 0; j < N; j++)
      sorted_counts[j] = counts[j][i];
    sort(sorted_counts, sorted_counts + N);

    int median = sorted_counts[N / 2];
    for (int j = 0; j < N; j++)
      min_cost += abs(sorted_counts[j] - median);
  }
  cout << "Case #" << t << ": " << min_cost << "\n";
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
