#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long LL;

struct barber {
   LL t;
   int idx;
   bool operator<(const barber &b) const {
      return t == b.t ? idx > b.idx : t > b.t;
   };
};

int solve() {
   int B;
   LL N; 
   cin >> B >> N;
   vector<LL> M(B);
   int idx = 0;
   LL nww = 1;
   priority_queue<barber> q;
   for(LL &m : M) {
      cin >> m;
      nww = (nww * m) / __gcd(nww, m);
      q.push({0, idx});
      ++idx;
   }
   LL block_counter = 0;
   for(LL m : M)
      block_counter += nww / m;
   N = N % block_counter;
   if(N == 0) N = block_counter;
   barber b = {0, B-1};
   for(int i = 0; i < N; ++i) {
      b = q.top();
      q.pop();
      q.push({b.t + M[b.idx], b.idx});
   }
   return b.idx + 1;
}

int main() {
   ios::sync_with_stdio(false);
   int T;
   cin >> T;
   for(int i = 1; i <= T; ++i) {
      cout << "Case #" << i << ": " << solve() << endl;
   }
   return 0;
}