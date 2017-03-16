#include <iostream>
#include <sys/stat.h>

using namespace std;

int64_t solveEval(int64_t R, int64_t C, int64_t N) {
   int64_t max0 = (R * C) / 2;
   int64_t max1 = (C == 1) ? 1 : 0;
   int64_t max2 = (C == 1) ? ((R - 1) / 2) : 2;
   int64_t max3 = (C == 1) ? 0 : ((2 * ((R / 2) - 1)) + (C - 2));
   int64_t max4 = (R * C) - max0 - max2 - max3;
   if (N <= max0) return 0; N -= max0;
   if (N <= max1) return N; int64_t count = max1; N -= max1;
   if (N <= max2) return count + (2 * N); count += (2 * max2); N -= max2;
   if (N <= max3) return count + (3 * N); count += (3 * max3); N -= max3;
   return count + (4 * N);
}

int64_t solve1(int64_t R, int64_t C, int64_t N) {
   int64_t max0 = (1 + (R * C)) / 2;
   int64_t max2 = (R == 1) ? ((C - 1) / 2) : 0;
   int64_t max3 = (R == 1) ? 0 : (2 * (((C - 1) / 2) + ((R - 1) / 2)));
   int64_t max4 = (R * C) - max0 - max2 - max3;
   //cout << "1 ==> " << max0 << " " << max2 << " " << max3 << " " << max4 << endl;
   if (N <= max0) return 0; N -= max0;
   if (N <= max2) return 2 * N; int64_t count = (2 * max2); N -= max2;
   if (N <= max3) return count + (3 * N); count += (3 * max3); N -= max3;
   return count + (4 * N);
}

int64_t solve2(int64_t R, int64_t C, int64_t N) {
   int64_t max0 = ((R * C) - 1) / 2;
   int64_t max1 = (R == 1) ? 2 : 0;
   int64_t max2 = (R == 1) ? ((C - 2) / 2) : 4;
   int64_t max3 = (R == 1) ? 0 : (2 * (((C - 3) / 2) + ((R - 3) / 2))); if (max3 < 0) max3 = 0;
   int64_t max4 = (R * C) - max0 - max2 - max3;
   //cout << "2 ==> " << max0 << " " << max1 << " " << max2 << " " << max3 << " " << max4 << endl;
   if (N <= max0) return 0; N -= max0;
   if (N <= max1) return N; int64_t count = max1; N -= max1;
   if (N <= max2) return count + (2 * N); count += (2 * max2); N -= max2;
   if (N <= max3) return count + (3 * N); count += (3 * max3); N -= max3;
   return count + (4 * N);
}

int64_t solve(int64_t R, int64_t C, int64_t N) {
   if ((R % 2) == 0) return solveEval(R, C, N);
   else {
      int64_t c1, c2;
      if (R > C) {
         c1 = solve1(C, R, N);
         c2 = solve2(C, R, N);
      }
      else {
         c1 = solve1(R, C, N);
         c2 = solve2(R, C, N);
      }
      //cout << "1: " << c1 << ", 2: " << c2 << endl;
      return (c1 < c2) ? c1 : c2;
   }
}

int main() {
   int64_t T; cin >> T;
   for (int64_t i = 1; i <= T; ++i) {
      int64_t R, C, N; cin >> R >> C >> N;
      cout << "Case #" << i << ": " << (((C % 2) == 0) ? solve(C, R, N) : solve(R, C, N)) << endl;
   }
   return 0;
}

