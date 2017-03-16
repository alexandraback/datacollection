
#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <map>

using namespace std;

int N;
std::string inputs[100];

int counts[100][100];


std::string nonrepeating(const std::string& s) {

  std::string nr;

  nr += s[0];

  for (int i = 1; i < s.size(); ++i) {
    if (s[i] != s[i-1]) nr += s[i];
  }

  return nr;
}

bool valid() {
  std::string nr = nonrepeating(inputs[0]);

  for (int i = 1; i < N; ++i) {
    if (nr != nonrepeating(inputs[i])) return false;
  }

  return true;
}

int determine(int k) {
  int v = 100*100*100;
  for (int i = 0; i < N; ++i) {
    // assume i as best
    int a = 0;
    for (int j = 0; j < N; ++j) { a += abs(counts[i][k] - counts[j][k]); }

    v = min(v, a);
  }

  return v;
}

void solve(int CASE) {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> inputs[i];
  }

  //fprintf(stderr, "nonrepeating: %s\n", nonrepeating(inputs[0]).c_str());

  if (!valid()) {
    printf("Case #%d: %s\n", CASE, "Fegla Won");
    return;
  }

  memset(counts, 0, sizeof(counts));

  int maxk = 0;
  for (int i = 0; i < N; ++i) {
    int k = 0;
    counts[i][k] = 1;
    for (int j = 1; j < inputs[i].size(); ++j) {
      if (inputs[i][j-1] == inputs[i][j])
        counts[i][k]++;
      else
        counts[i][++k] = 1;
    }

    maxk = max(maxk, k);
  }

  ++maxk;

  int val = 0;
  for (int i = 0; i < maxk; ++i) {
    val += determine(i);

  }


  printf("Case #%d: %d\n", CASE, val);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    solve(i+1);

  return 0;
}

