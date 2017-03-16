#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
#include <iterator>
#include <cassert>

bool solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<std::pair<char,int> > > v;

  for (std::string s; n--;) {
    std::cin >> s; s.push_back('.');
    char last='\0'; int cnt=0;
      v.emplace_back();
    for (size_t i=0; i<s.size(); ++i) {
      if (s[i] != last) {
	if (last) v.back().emplace_back(last, cnt);
	last=s[i]; cnt=1;
      } else {
	cnt++;
      }
    }
  }
  assert(!v.empty());

  std::vector<std::pair<char,std::vector<int> > > vertical;
  for (auto& p : v.front())
    vertical.emplace_back(std::make_pair(p.first, std::vector<int>()));

  for (auto& s : v) {
    if (s.size() != v.front().size())
      return false;
    for (size_t i=0; i<s.size(); ++i) {
      if (s[i].first != v.front()[i].first)
	return false;
      assert(vertical[i].first == s[i].first);
      vertical[i].second.push_back(s[i].second);
    }
  }

  int penalty = 0;
  for (auto h : vertical) {
    auto mid = h.second.begin() + h.second.size()/2;
    std::nth_element(h.second.begin(), mid, h.second.end());
    for (int i : h.second)
      penalty += std::abs(*mid - i);
  }
  std::cout << penalty;
  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int num_of_testcases; std::cin >> num_of_testcases;
  for (int testcase=1; testcase<=num_of_testcases; ++testcase) {
    std::cout << "Case #" << testcase << ": ";
    if (!solve()) std::cout << "Fegla Won";
    std::cout << '\n';
  }
}

/*
 * Local variables:
 * mode:c++
 * compile-command:"g++ -D_GLIBCXX_DEBUG -g -ggdb3 -O0 -Wall -Wextra -std=c++1y repeater.cc -o repeater && for f in *.in; do echo \"--- $f -------------\"; ./repeater <$f; done"
 * end:
 */
