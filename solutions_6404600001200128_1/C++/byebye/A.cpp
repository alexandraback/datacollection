#include <iostream>
#include <vector>
#include <algorithm>
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long LL;

void solve(int c) {
   int N;
   cin >> N;
   vector<int> num(N);
   for(int &n : num)
      cin >> n;
   int res1 = 0, res2 = 0;
   int maks = 0;
   for(int i = 1; i < N; ++i) {
      maks = max(maks, num[i-1] - num[i]);
      res1 += max(0, num[i-1] - num[i]);
   }
   for(int i = 0; i < N-1; ++i) {
      res2 += min(num[i], maks);
   }
   
   cout << "Case #" << c << ": " << res1 << " " << res2 << endl;
}

int main() {
   ios::sync_with_stdio(false);
   int T;
   cin >> T;
   for(int i = 1; i <= T; ++i) {
      solve(i);
   }
   return 0;
}