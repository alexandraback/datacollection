#include <iostream>

using namespace std;

typedef long long llong;

int B;
llong N;
int M[1004];

llong nserved(llong t) {
   if (t < 0) return 0;
   llong res = 0;
   for (int i = 0; i < B; ++i)
      res += 1 + t / M[i];
   return res;
}

bool check(llong t) {
   return nserved(t) >= N;
}

llong bin_search() {
   llong lo = 0, hi = 1000000000000000LL;
   while (lo < hi) {
      llong mid = lo + (hi-lo)/2;
      if ( check(mid) )
         hi = mid;
      else
         lo = mid+1;
   }
   return lo;
}

int solve() {
   llong t = bin_search();
   llong ns = nserved(t-1);
// cerr << "t = " << t << ' ' << "ns = " << ns << endl;
   for (int i = 0; i < B; ++i) {
      if ((t % M[i]) == 0) {
         ++ns;
         if (N <= ns) return i+1;
      }
   }
   return -1;
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      cin >> B >> N;
      for (int i = 0; i < B; ++i)
         cin >> M[i];
      int res = solve();
      cout << "Case #" << tc << ": " << res << endl;
   }

   return 0;
}
