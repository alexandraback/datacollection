#include <iostream>
#include <bitset>
using namespace std;
typedef long long LL;

//*******************

//*******************

int solve() {
   unsigned R, C, N;
   cin >> R >> C >> N;
   const unsigned field = R * C;
   const unsigned MAX = 1 << field;
   unsigned x = 0;
   unsigned min_happ = 1e9;
   while(x < MAX) {
      if(__builtin_popcount(x) == N) {
         // cout << bitset<10>(x) << endl;
         unsigned k = 1;
         unsigned counter = 0;
         while(k <= field) {
            if(((x >> (k-1)) & 1) == 1) {
               if(k + C <= field && ((x >> (k + C - 1)) & 1) == 1) {
                  // cerr << "v " << k << endl;
                  ++counter;
               }
               if(k % C != 0 && ((x >> k) & 1) == 1) {
                  // cerr << "> " << k << endl;
                  ++counter;
               }
            }
            ++k;
         }
         // cerr << counter << endl;
         min_happ = min(counter, min_happ);
      }
      ++x;
   }
   return min_happ;
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