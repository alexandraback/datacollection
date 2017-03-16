#include <iostream>

using namespace std;

typedef long long llong;

int N;
int M[1004];

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      cin >> N;
      for (int i = 0; i < N; ++i)
         cin >> M[i];

      int G = 0;
      llong res1 = 0;
      for (int i = 1; i < N; ++i) {
         int d = M[i-1] - M[i];
         if (d > 0) {
            G = max(G, d);
         //   cerr << i << ": " << M[i-1] << ' ' << M[i] << ' ' << d << endl;
            res1 += d;
         }
      }
      llong res2 = 0;
      for (int i = 0; i < N-1; ++i) {
         int eat = min(M[i], G);
         res2 += eat;
      }
   //   cerr << G << endl;
      cout << "Case #" << tc << ": " << res1 << ' ' << res2 << endl;
   }

   return 0;
}
