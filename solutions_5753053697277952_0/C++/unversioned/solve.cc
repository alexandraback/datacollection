#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iterator>

using namespace std;

int main() {
  int n;
  cin >> n;

  auto solve = [](vector<int> counts) {
    int total = 0;
    for (auto x : counts)
      total += x;

    while (total > 0) {
      auto it = max_element(counts.begin(), counts.end());
      --*it;
      char c = (it - counts.begin() + 'A');
      cout << c;
      --total;
      
      it = max_element(counts.begin(), counts.end());
      if (2 * (*it) > total) {
	--*it;
	--total;
	c = (it - counts.begin() + 'A');
	cout << c;
      }

      cout << " ";
    }
  };
  for (int i = 1; i <= n; ++i) {
    int N;
    cin >> N;
    vector<int> sens;
    copy_n(istream_iterator<int>(cin), N, back_inserter(sens));
    
    cout << "Case #" << i << ": ";
    solve(sens);
    cout << "\n";
  }
}
