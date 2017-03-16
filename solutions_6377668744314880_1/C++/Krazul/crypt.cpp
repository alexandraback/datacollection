#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

bool inline slope_cmp(PII a, PII b) {
  if (a.first == 0) return false;
  if (b.first == 0) return true;

  if (a.first < 0) {
    a.first *= -1;
    a.second *= -1;
  }
  if (b.first < 0) {
    b.first *= -1;
    b.second *= -1;
  }

  return (a.second * ((LL) b.first)) < (b.second * ((LL) a.first));
}

bool equal_slope(PII a, PII b) {
  return (a.first == 0 && b.first == 0) ||
         (a.second == 0 && b.second == 0) ||
         ((a.second * ((LL)b.first)) == (b.second * ((LL)a.first)) &&
          (a.second * ((LL)b.first)) != 0);
}

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    int n; cin >> n;
    vector<PII> trees(n);
    for (int i = 0; i < n; ++i) {
      cin >> trees[i].first >> trees[i].second;
    }
    cout << "Case #" << test << ":" << endl;

    vector<PII> slopes(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) { if (j == i) continue;
        slopes[(j > i) ? j - 1 : j] =
          make_pair(trees[j].first - trees[i].first,
                    trees[j].second - trees[i].second);
      }
      sort(slopes.begin(), slopes.end(), slope_cmp);

      int fewest = n - 1;
      int left = 0;
      int right = 0;
      int entering_left = 0;
      int entering_right = 0;
      for (int j = 0; j < slopes.size(); ++j) {
        if (slopes[j].first < 0) left++;
        else if (slopes[j].first > 0) right++;
        else if (slopes[j].second > 0) entering_right++;
        else if (slopes[j].second < 0) entering_left++;
      }
      fewest = min(fewest, left); fewest = min(fewest, right);
      right += entering_right; entering_right = 0;
      left += entering_left; entering_left = 0;

      for (int j = 0; j < slopes.size(); ++j) {
        if (fewest == 0) break;
        if (slopes[j].first > 0) entering_left++;
        else if (slopes[j].first < 0) entering_right++;
        else break; // already took care of up/down at the beginning

        while (j + 1 < slopes.size() && equal_slope(slopes[j], slopes[j+1])) {
          j++;
          if (slopes[j].first > 0) entering_left++;
          else if (slopes[j].first < 0) entering_right++;
        }

        right -= entering_left;
        left -= entering_right;

        fewest = min(fewest, left); fewest = min(fewest, right);
        right += entering_right; entering_right = 0;
        left += entering_left; entering_left = 0;
      }
      
      cout << fewest << endl;
    }
  }
  return 0;
}