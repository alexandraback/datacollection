#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

const string fileName = "small";
ifstream fin (fileName + ".in");
ofstream fout(fileName + ".out");

struct TestCase {
  size_t id;

  vector<int> arr;

  string output(std::pair<long long, long long> result) {
    std::stringstream buf;
    buf << "Case #" << id << ": " << result.first << " " << result.second;
    return buf.str();
  }
};

vector<TestCase> read() {
  vector<TestCase> vec;

  // reads input
  int numTestCases;
  fin >> numTestCases;
  for (int i = 0; i < numTestCases; ++i) {
    TestCase tc;
    tc.id = i+1;

    int n;
    fin >> n;
    for (int i = 0; i < n; ++i) {
      int tmp;
      fin >> tmp;
      tc.arr.push_back(tmp);
    }

    vec.push_back(tc);
  }

  return vec;
}

int solve1(TestCase& tc) {
  int sol1 = 0;
  for (int i = 1; i < tc.arr.size(); ++i) {
    sol1 += std::max(0, tc.arr[i-1] - tc.arr[i]);
  }
  return sol1;
}

long long solve2(TestCase& tc) {
  long long sol2 = 0;

  int rate = 0;
  for (int i = 1; i < tc.arr.size(); ++i) {
    rate = std::max(rate, tc.arr[i-1] - tc.arr[i]);
  }

  for (int i = 0; i < tc.arr.size() - 1; ++i) {
    long long now = std::max(0, tc.arr[i]);
    if (now < rate) {
      sol2 += now;
    } else {
      sol2 += rate;
    }
  }
  return sol2;
}

std::pair<long long, long long> solve(TestCase& tc) {
  int sol1 = solve1(tc);
  int sol2 = solve2(tc);

  return std::make_pair(sol1, sol2);
}

int main() {
  // reads input
  auto vec = read();

  // solves and writes solution.
  for (auto& tc : vec) {
    auto sol = solve(tc);
    fout << tc.output(sol) << endl;
  }

  return 0;
}
