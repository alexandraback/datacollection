#include <iostream>
#include <vector>

using namespace std;

int main() {
   int T; cin >> T;
   for (int i = 1; i <= T; ++i) {
      int N; cin >> N;
      vector<int> num(N);
      for (int j = 0; j < N; ++j) cin >> num[j];
      int y = 0, z = 0, max = 0, diff;
      for (int j = 1; j < N; ++j) {
         diff = num[j - 1] - num[j];
         if (diff > 0) y += diff;
         if (max < diff) max = diff;
      }
      for (int j = 0; j < (N - 1); ++j) {
         if (num[j] < max) z += num[j];
         else z += max;
      }
      cout << "Case #" << i << ": " << y << " " << z << endl;
   }
   return 0;
}

