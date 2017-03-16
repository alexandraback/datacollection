#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 10010;

int N;
vector<int> M;

void Input() {
  cin >> N;
  M.clear();
  M.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> M[i];
  }
}

void Solve() {
  int m1 = 0;
  vector<int> d;
  for (int i = 1; i < N; i++) {
    if (M[i] < M[i - 1]) {
      m1 += M[i - 1] - M[i];
      d.push_back(M[i - 1] - M[i]);
    }
  }
  if (d.size() == 0) {
    cout << 0 << " " << 0;
    return;
  }

  sort(d.rbegin(), d.rend());
  int D = d[0];
  int m2 = 0;
  for (int i = 1; i < N; i++) {
    if (M[i - 1] - D <= 0) {
      m2 += M[i - 1];
    } else if (M[i - 1] - D <= M[i]) {
      m2 += D;
    } else {
      assert(0);
    }
  }
  cout << m1 << " " << m2;
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  const string problem = "large"; // practice, small, large
  const bool outputToStdout = true;

  string inputFile = "";
  string outputFile = "";

  if (problem == "practice") {
    inputFile  = "./data/A/A-practice.in";
    outputFile = "./data/A/A-practice.out";
  } else if (problem == "small") {
    inputFile  = "./data/A/A-small-attempt0.in";
    outputFile = "./data/A/A-small-attempt0.out";
  } else if (problem == "large") {
    inputFile  = "./data/A/A-large.in";
    outputFile = "./data/A/A-large.out";
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
