#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>
#include <set>
#include <cassert>
#include <vector>

std::string solve(
    size_t R1, std::array<size_t, 16> const & nums1,
    size_t R2, std::array<size_t, 16> const & nums2)
{
  assert(R1 >= 1 && R1 <= 4);
  assert(R2 >= 1 && R2 <= 4);

  std::set<size_t> selected1;
  std::copy_n(std::next(nums1.cbegin(), 4 * (R1 - 1)), 4,
      std::inserter(selected1, selected1.end()));

  std::set<size_t> selected2;
  std::copy_n(std::next(nums2.cbegin(), 4 * (R2 - 1)), 4,
      std::inserter(selected2, selected2.end()));

  std::vector<size_t> intersection;
  std::set_intersection(
      std::begin(selected1), std::end(selected1),
      std::begin(selected2), std::end(selected2),
      std::back_inserter(intersection));

  if (intersection.empty())
  {
    return "Volunteer cheated!";
  }
  else if (intersection.size() > 1)
  {
    return "Bad magician!";
  }
  else
  {
    return std::to_string(intersection.front());
  }
}

int main()
{
  size_t T;

  std::cin >> T;

  for (size_t idx = 0; idx != T; ++idx)
  {
    size_t R1;
    std::cin >> R1;

    std::array<size_t, 16> nums1;
    std::copy_n(std::istream_iterator<size_t>(std::cin), 16, nums1.begin());

    size_t R2;
    std::cin >> R2;

    std::array<size_t, 16> nums2;
    std::copy_n(std::istream_iterator<size_t>(std::cin), 16, nums2.begin());

    std::cout << "Case #" << (idx + 1) << ": " << solve(R1, nums1, R2, nums2) << "\n";
  }
}
