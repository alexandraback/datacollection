#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forn1(i, n) for (int i = 1; i <= (int)(n); i++)

void solve()
{
   long r, c, n;
   cin >> r >> c >> n;

   if (((r * c) + 1) / 2 >= n) {
      cout << "0" << endl;
      return;
   }

   // Special cases
   if (r == 1 || c == 1) {
      int rooms = r * c;
      if (n <= (rooms + 1) / 2)
         cout << "0" << endl;
      else {
         if (rooms % 2 == 1)
            cout << (n - ((rooms + 1) / 2)) * 2 << endl;
         else {
            int k = n - ((rooms + 1) / 2), unh = 0;
            cout << 1 + ((k - 1) * 2) << endl;
         }
      }
      return;
   }

   // Subtraction style - if all empties are internal
   if ((r >=3 && c >= 3)) {
      int inner_r = r - 2, inner_c = c - 2, anti_n = (r * c) - n;
      if ( ((inner_r * inner_c) + 1) / 2 >= anti_n) {
         int unh_if_full = ( (r - 1) * c ) + ( (c - 1) * r );
         cout << (unh_if_full - (4 * anti_n)) << endl;
         return;
      } else {
         anti_n -= ((inner_r * inner_c) + 1) / 2;
         int num_edges_available = (((r - 2) / 2) * 2) + (((c - 2) / 2) * 2);
         if (anti_n <= num_edges_available) {
            int unh_if_full = ( (r - 1) * c ) + ( (c - 1) * r );
            unh_if_full -= 4 * (((inner_r * inner_c) + 1) / 2);
            cout << (unh_if_full - (3 * anti_n)) << endl;
            return;
         }
      }
   }

   long unhappiness = 0;

   // Assume crossrooms filled
   n -= ((r * c) + 1) / 2;


   // Odd x odd case
   if (r % 2 == 1 && c % 2 == 1) {
      // No corners

      // Fill edges
      long num_edges = (r - 1) + (c - 1);
      if (num_edges > n) {
         unhappiness += (n * 3);
         cout << unhappiness << endl;
         return;
      } else {
         unhappiness += (num_edges * 3);
         n -= num_edges;
      }

      // Center rooms
      unhappiness += (n * 4);
      cout << unhappiness << endl;
      return;
   }

   // Even x ? case
   // Two corners
   if (n <= 2) {
      cout << (n * 2) << endl;
      return;
   }
   n -= 2;
   unhappiness = 4;

   // Fill edges
   long num_edges = (r - 2) + (c - 2);
   if (num_edges > n) {
      unhappiness += (n * 3);
      cout << unhappiness << endl;
      return;
   } else {
      unhappiness += (num_edges * 3);
      n -= num_edges;
   }

   // Center rooms
   unhappiness += (n * 4);
   cout << unhappiness << endl;
   return; 
}

int main()
{
   freopen("two.in", "r", stdin);
   freopen("two.out", "w", stdout);

   long count;
   cin >> count;
   forn1(i, count) {
      cout << "Case #" << i << ": ";
      solve();
   }
   return 0;
} 
