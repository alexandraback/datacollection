#include <bits/stdc++.h>

using namespace std;

int N, B;
vector<int64_t> M;

void Input() {
  cin >> B >> N;
  M.clear();
  M.resize(B);
  for (int i = 0; i < B; i++) {
    cin >> M[i];
  }
}

int64_t count(int64_t t) {
  int64_t total = 0;
  for (int b : M) {
    int64_t c = t / b + 1;
    total += c;
  }
  return total;
}

void Solve() {
  int64_t l = 0;
  int64_t r = 1e18 + 10;
  while (l < r) {
    int64_t t = (l + r) / 2;
    if (count(t) < N) {
      l = t + 1;
    } else {
      r = t;
    }
  }

  int64_t T = l;
  vector<int> TB;
  for (int b = 0; b < B; b++) {
    int64_t count = (T - 1) / M[b] + 1;
    if (T % M[b] == 0) {
      TB.push_back(b);
    }
    N -= count;
  }

  cout << TB[N - 1] + 1;
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  const string problem = "large"; // practice, small, large
  const bool outputToStdout = true;

  string inputFile = "";
  string outputFile = "";

  if (problem == "practice") {
    inputFile  = "./data/B/B-practice.in";
    outputFile = "./data/B/B-practice.out";
  } else if (problem == "small") {
    inputFile  = "./data/B/B-small-attempt1.in";
    outputFile = "./data/B/B-small-attempt1.out.1";
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
