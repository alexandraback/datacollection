#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

void Solve() {
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<int> B(N, 0);
  int added = 0;
  int total = accumulate(A.begin(), A.end(), 0);

  vector<vector<int>> D;

  stringstream ss;
  while (added < total) {
    vector<pair<int, int>> C;
    for (int i = 0; i < N; i++) {
      if (A[i] - B[i] > 0) {
        C.push_back(make_pair(A[i] - B[i], i));
      }
    }
    sort(C.begin(), C.end());

    ss << " ";
    if (C.size() >= 2) {
      ss << char('A' + C[0].second);
      ss << char('A' + C[1].second);
      B[C[0].second]++;
      B[C[1].second]++;
      added += 2;
    } else {
      ss << char('A' + C[0].second);
      B[C[0].second]++;
      added += 1;
    }
  }

  string res = ss.str();
  reverse(res.begin(), res.end());

  cout << res;
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  const string problem = "small"; // practice, small, large
  const bool redirectStdoutToFile = true;
  const bool redirectStderrToFile = true;

  string inputFile = "";
  string stdoutFile = "";
  string stderrFile = "./output/A.stderr";

  if (problem == "practice") {
    inputFile  = "./input/A-practice.in";
    stdoutFile = "./output/A-practice.out";
  } else if (problem == "small") {
    inputFile  = "./input/A-small-attempt2.in";
    stdoutFile = "./output/A-small-attempt2.out";
  } else if (problem == "large") {
    inputFile  = "./input/A-large.in";
    stdoutFile = "./output/A-large.out";
  }

  fprintf(stderr, "Read from input: %s\n", inputFile.c_str());
  if (redirectStdoutToFile) fprintf(stderr, "Redirect stdout: %s\n", stdoutFile.c_str());
  if (redirectStdoutToFile) fprintf(stderr, "Redirect stderr: %s\n", stderrFile.c_str());

  assert(freopen(inputFile.c_str(), "r", stdin) != nullptr);
  if (redirectStdoutToFile) freopen(stdoutFile.c_str(), "w", stdout);
  if (redirectStderrToFile) freopen(stderrFile.c_str(), "w", stderr);

  int T = 0;
  string line;
  {
    getline(cin, line);
    istringstream is(line);
    is >> T;
  }

  fprintf(stderr, "# of cases: %d\n", T);

  for (int test_case = 1; test_case <= T; ++test_case) {
    printf("Case #%d: ", test_case);
    Solve();
    printf("\n");

    fprintf(stderr, "Finished: #%d\n", test_case);
  }

  fprintf(stderr, "Finished all test cases\n");

  return 0;
}
