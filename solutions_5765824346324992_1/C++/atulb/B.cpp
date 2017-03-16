#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define vi vector<int>
#define vs vector<string>
#define vl vector<LL>
#define pb push_back
#define endl "\n"


LL solve()
{
   LL B,N;
   cin >> B >> N;
   vl M;
   for (int i=1;i<=B;i++)
   {
     LL t;
     cin >> t;
     M.pb(t);
   }

   LL time = 0;
   // bin search for time
   {
      LL lo = 0;
      LL hi = 1e15;
      while (lo < hi)
      {
         LL mid = (lo + hi) / 2;
         LL cut = 0;
         LL free = 0;
         for (int i=0;i<B;++i)
         {
            cut  += mid / M[i];
            if (mid % M[i] == 0) free++;
            else cut++;
         }
         //cout  << mid << " " << cut << " " << free << endl;
         if (cut < N && (cut + free) >= N) { lo = mid; hi = mid; break; }
         else if (cut >= N) { hi = mid - 1;}
         else { lo = mid + 1; }
      }
      //if (lo > hi)
      //   cout << lo << " " << hi << endl;
      assert(lo <= hi);
      time = lo;
   }

   //cout  << time << endl;
   // return
   for (int i=0;i<B;++i)
   {
      N -= time / M[i];
      if  (time % M[i] != 0) N--;
   }
   for (int i = 0; i < B; ++i)
   {
      if (time % M[i] == 0)
      {
         if (N == 1)
            return i + 1;
         else
            N--;
      }
   }
   return -1;
}

int main()
{
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   for (int i = 1; i <= T; ++i)
   {
      LL ret = solve();
      cout  << "Case #" << i << ": " << ret << endl;
   }

   return 0;
}
