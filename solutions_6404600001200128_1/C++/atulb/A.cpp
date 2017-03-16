#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define vi vector<int>
#define vs vector<string>
#define vl vector<LL>
#define pb push_back
#define endl "\n"


void solve(LL& ret1, LL& ret2)
{
   LL N;
   cin >> N;
   vl v;
   for (int i = 0; i < N; ++i)
   {
      LL m;
      cin >> m;
      v.pb(m);
   }

   // ret1
   ret1  = 0;
   for (int i = 1; i < N; ++i)
   {
      LL diff = -1*(v[i] - v[i-1]);
      ret1 += max(0ll, diff);
   }

   // ret2
   LL rate  = 0;
   for (int i = 1; i < N; ++i)
   {
      LL diff = -1*(v[i] - v[i-1]);
      rate = max(rate, diff);
   }
   ret2  = 0;
   for (int i = 0; i < N - 1; ++i)
   {
      LL curr = min(v[i], rate);
      ret2 += curr;
   }
}

int main()
{
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   for (int i = 1; i <= T; ++i)
   {
      LL ret1, ret2;
      solve(ret1, ret2);
      cout  << "Case #" << i << ": " << ret1 << " " << ret2 << endl;
   }

   return 0;
}
