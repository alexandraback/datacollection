/* Opgave: A */
// 7+8+7=22 includes
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <string>

#include <iostream>
#include <sstream>
#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <algorithm>

using namespace std;

struct P {
  char c;
  int count;
};
void testcase() {
  int N;
  cin >> N;
  std::vector<std::vector<P>> strings(N);
  for(int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    char prev = 0;
    for(unsigned j = 0; j < s.size(); ++j) {
      if(s[j] == prev)
	strings[i].back().count++;
      else
	strings[i].push_back(P{s[j], 1});
      prev = s[j];
    }
  }
  for(int i = 1; i < N; ++i) {
    if(strings[i].size() != strings[0].size()) {
      cout << "Fegla Won\n";
      return;
    }
    for(unsigned j =0 ; j < strings[i].size(); ++j) 
      if(strings[i][j].c != strings[0][j].c) {
	cout << "Fegla Won\n";
	return;
      }
  }
  unsigned count = 0;
  for(unsigned j = 0; j < strings[0].size(); ++j) {
    vector<int> v(N);
    for(int i =0 ; i < N; ++i)
      v[i] = strings[i][j].count;
    std::sort(v.begin(), v.end());
    int len = v[v.size() / 2];
    for(int i =0 ; i < N; ++i)
      count += abs(len - v[i]);
  }
  cout << count << "\n";
}

int main () {
  int T;
  cin >> T;
  for(int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    testcase();
  }
	return 0;
}
/* Opgave: A */
