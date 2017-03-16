/*
 * CodeJam 2014. Round 1B. Problem A
 * Vladimir Rutsky
 * 03.05.2014
 */

#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>
#include <set>
#include <cassert>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

std::pair<std::vector<int>, std::string> unify_string(std::string const & s)
{
  std::string template_str;
  std::vector<int> nums;

  char last_ch = s[0];
  int last_ch_count = 1;
  for (size_t i = 1; i != s.size(); ++i)
  {
    char const ch = s[i];
    if (ch != last_ch)
    {
      template_str.push_back(last_ch);
      nums.push_back(last_ch_count);

      last_ch = ch;
      last_ch_count = 1;
    }
    else
    {
      ++last_ch_count;
    }
  }
  template_str.push_back(last_ch);
  nums.push_back(last_ch_count);

  return std::make_pair(nums, template_str);
}

size_t num_moves(std::vector<int> & counts)
{
  size_t total = counts.size();

  std::map<int, size_t> m;
  for (int pos: counts)
  {
    if (m.find(pos) == m.end())
      m[pos] = 0;

    m[pos]++;
  }

  int offset = 0;
  {
    int start_pos = m.begin()->first;
    for (auto it = std::next(m.begin()); it != m.end(); ++it)
    {
      int diff = (it->first - start_pos) * it->second;
      assert(diff > 0);
      offset += diff;
    }
  }

  int min_offset = offset;
  assert(min_offset >= 0);

  // Number of items
  int left = 0, left_sum = 0;
  int cur = m.begin()->second;
  int cur_pos = m.begin()->first;
  int right = total - cur, right_sum = offset;

  for (auto it = std::next(m.begin()); it != m.end(); ++it)
  {
    int const dist = it->first - cur_pos;
    cur_pos = it->first;

    left_sum += (left + cur) * dist;
    left += cur;
    cur = it->second;
    right -= cur;
    right_sum -= (cur + right) * dist;

    assert(left_sum > 0);
    assert(left > 0);
    assert(cur > 0);
    assert(right_sum >= 0);
    assert(right >= 0);

    if (left_sum + right_sum < min_offset)
      min_offset = left_sum + right_sum;
  }

  return min_offset;
}

std::string solve(std::vector<std::string> const & strs)
{
  size_t const N = strs.size();

  std::vector<std::vector<int>> nums;

  std::string const template_str = unify_string(strs[0]).second;

  for (std::string const & s: strs)
  {
    std::vector<int> num;
    std::string str;
    std::tie(num, str) = unify_string(s);

    if (str != template_str)
      return "Fegla Won";

    nums.push_back(num);
  }
  assert(nums.size() == N);

  size_t res = 0;
  for (size_t i = 0; i != template_str.size(); ++i)
  {
    std::vector<int> counts;
    for (std::vector<int> const & num: nums)
      counts.push_back(num[i]);
    res += num_moves(counts);
  }

  return std::to_string(res);
}

int main()
{
  size_t T;

  //FILE * res = std::freopen("small.in", "rt", stdin);
  //FILE * res = std::freopen("A-small-attempt0.in", "rt", stdin);
  //FILE * res = std::freopen("A-large.in", "rt", stdin);
  //assert(res);

  std::cin >> T;

  for (size_t idx = 0; idx != T; ++idx)
  {
    size_t N;
    std::cin >> N;
    std::string tmp;
    std::getline(std::cin, tmp);
    assert(tmp == "");

    std::vector<std::string> strs;
    std::copy_n(
          std::istream_iterator<std::string>(std::cin),
          N,
          std::back_inserter(strs));

    std::cout << "Case #" << (idx + 1) << ": " << solve(strs) << "\n";
  }
}
