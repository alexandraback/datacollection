#include <iostream>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int matrix[4][4];


void readM() {
  for(unsigned r = 0; r < 4; ++r) {
    for(unsigned c = 0; c < 4; ++c) {
      cin >> matrix[r][c];
    }
  }
}

void testCase(unsigned id) {
  int r;
  cin >> r; --r;
  readM();

  std::set<int> chosen;
  for(unsigned c = 0; c < 4; ++c)
    chosen.insert(matrix[r][c]);
  cin >> r; --r;
  readM();

  std::set<int> chosen2;
  for(unsigned c = 0; c < 4; ++c)
    if(chosen.find(matrix[r][c]) != chosen.end())
      chosen2.insert(matrix[r][c]);
  string ans;
  if(chosen2.empty())
    ans = "Volunteer cheated!";
  else if(chosen2.size() == 1)
    ans = to_string(*chosen2.begin());
  else
    ans = "Bad magician!";
  cout.precision(10);
  cout.setf(ios::fixed);
  cout << "Case #" << id << ": " << ans << "\n";
}


int main() {
  int T;
  cin >> T;
  for(int i = 1; i <= T; ++i)
    testCase(i);
  return 0;
}
