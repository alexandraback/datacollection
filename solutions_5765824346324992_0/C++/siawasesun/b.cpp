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

template<typename T> inline T _GCD(T a, T b) { return __gcd(a, b); }
#define GCD(a, b) _GCD<__typeof(a)>((a),(b))
template<typename T> inline T _LCM(T a, T b) { return a / _GCD<T>(a, b) * b; }
#define LCM(a, b) _LCM<__typeof(a)>((a),(b))

void Solve() {
  int64_t T = 1;
  for (int64_t t : M) {
    T = LCM(t, T);
  }

  vector<int> v;
  for (int t = 0; t < T; t++) {
    for (int b = 0; b < B; b++) {
      if (t % M[b] == 0) {
        v.push_back(b + 1);
      }
    }
  }

  int a = N % v.size();
  if (a == 0) a = v.size() - 1;
  else a--;
  cout << v[a];
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
    inputFile  = "./data/B/B-small-attempt1.in";
    outputFile = "./data/B/B-small-attempt1.out";
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
