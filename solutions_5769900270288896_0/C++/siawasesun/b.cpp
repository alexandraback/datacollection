#include <bits/stdc++.h>

using namespace std;

int H, W, N;

void Input() {
  cin >> H >> W >> N;
}

const int dx[4] = { 1, 0, -1, 0, };
const int dy[4] = { 0, 1, 0, -1, };

int get(const vector<int>& A, int y, int x) {
  return A[y * W + x];
}

void Solve() {
  vector<int> A(H * W, 0);
  for (int i = 0; i < N; i++) {
    A[H * W - N + i] = 1;
  }

  int res = 1e9;
  do {
    int sum = 0;
    for (int y = 0; y < H; y++) {
      for (int x = 0; x < W; x++) {
        if (!get(A, y, x)) continue;
        for (int d = 0; d < 4; d++) {
          int ny = y + dy[d];
          int nx = x + dx[d];
          if (ny >= 0 && ny < H && nx >= 0 && nx < W) {
            if (get(A, ny, nx)) sum++;
          }
        }
      }
    }
    sum /= 2;
    res = min(sum, res);
  } while (next_permutation(A.begin(), A.end()));

  cout << res;
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  const string problem = "small"; // practice, small, large
  const bool outputToStdout = true;

  string inputFile = "";
  string outputFile = "";

  if (problem == "practice") {
    inputFile  = "./data/B/B-practice.in";
    outputFile = "./data/B/B-practice.out";
  } else if (problem == "small") {
    inputFile  = "./data/B/B-small-attempt0.in";
    outputFile = "./data/B/B-small-attempt0.out";
  } else if (problem == "large") {
    inputFile  = "./data/B/B-large.in";
    outputFile = "./data/B/B-large.out";
  }

  freopen(inputFile.c_str(), "r", stdin);
  if (outputToStdout) freopen(outputFile.c_str(), "w", stdout);

  fprintf(stderr, "Read from input: %s\n", inputFile.c_str());
  if (outputToStdout) fprintf(stderr, "Write to output: %s\n", outputFile.c_str());

  int T;
  string line;
  {
    getline(cin, line);
    istringstream is(line);
    is >> T;
  }

  for (int test_case = 1; test_case <= T; ++test_case) {
    Input();
    printf("Case #%d: ", test_case);
    Solve();
    printf("\n");
  }

  return 0;
}
