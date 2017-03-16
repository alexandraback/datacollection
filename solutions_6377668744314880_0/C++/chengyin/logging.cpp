#include <iostream>
#include <vector>

using namespace std;

int solve(const vector<int>& X, const vector<int>& Y) {
   // for each point, compute every line with other points
   // find out min number of points on both sides
   const int N = X.size();
   // line: y = mx + k
   double m, K;
   for (int i = 0; i < N; ++i) {
      int min = 10000;
      //cout << "Taget X = " << X[i] << ", Y = " << Y[i] << endl;
      for (int j = 0; j < N; ++j) {
         if (i == j) continue;
         //cout << "Try X = " << X[i] << ", Y = " << Y[i] << endl;
         if (X[i] == X[j]) {  // vertical line
            int small = 0, large = 0;
            for (int k = 0; k < N; ++k) {
               if (k == i || k == j) continue;
               if (X[k] < X[i]) ++small;
               if (X[k] > X[i]) ++large;
            }
            //cout << "S = " << small << ", L = " << large << endl;
            if (min > small) min = small;
            if (min > large) min = large;
         }
         else {
            m = (double)(Y[j] - Y[i]) / (double)(X[j] - X[i]);
            K = (double)Y[i] - (m * (double)X[i]);
            int small = 0, large = 0;
            for (int k = 0; k < N; ++k) {
               if (k == i || k == j) continue;
               const double v = m * (double)X[k] + K;
               if ((double)Y[k] > v) ++small;
               if ((double)Y[k] < v) ++large;
            }
            //cout << "S = " << small << ", L = " << large << endl;
            if (min > small) min = small;
            if (min > large) min = large;
         }
      }
      cout << min << endl;
   }
}

int main() {
   int T; cin >> T;
   for (int i = 1; i <= T; ++i) {
      int N; cin >> N;
      vector<int> X(N), Y(N);
      for (int j = 0; j < N; ++j) cin >> X[j] >> Y[j];
      cout << "Case #" << i << ": " << endl;
      solve(X, Y);
   }
   return 0;
}

