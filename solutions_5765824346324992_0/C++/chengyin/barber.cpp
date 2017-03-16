#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int64_t ratio(int64_t N, const vector<int64_t>& cost) {
   int64_t r = 0;
   for (int i = 0; i < cost.size(); ++i)
      r += ((N / cost[i]) + ((N % cost[i]) ? 1 : 0));
   return r;
}

int64_t solve(int64_t N, const vector<int64_t>& cost) {
   int64_t jump = 10000000000000000;
   int64_t min = 0, value;
   if (N <= cost.size()) return N;
   while (jump) {
      for (;; min += jump) {
         value = ratio(min, cost);
         //cout << "attemp = " << min << ", v = " << value << endl;
         if (value >= N) break;
      }
      if (value == N) break;
      min -= jump;
      jump = jump >> 1;
   }
   //cout << "First match on " << min << ", v = " << ratio(min, cost) << endl;
   while (true) {
      if (ratio(min, cost) < N) break;
      --min;
   }
   // configuration
   int64_t S = ratio(min, cost);
   //cout << "Last match on " << min << ", v = " << S << endl;
   for (int i = 0; i < cost.size(); ++i) {
      if (!(min % cost[i])) ++S;
      if (S >= N) return (1 + i);
   }
   assert (0);
   return 1;
}

int main() {
   // parse T
   int T; cin >> T;
   // parse cases
   for (int i = 1; i <= T; ++i) {
      int64_t B, N; cin >> B >> N;
      vector<int64_t> cost(B);
      for (int j = 0; j < B; ++j) cin >> cost[j];
      cout << "Case #" << i << ": " << solve(N, cost) << endl;
   }
   return 0;
}

