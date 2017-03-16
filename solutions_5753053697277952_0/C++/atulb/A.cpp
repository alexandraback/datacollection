#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
#define vi vector<int>
#define vs vector<string>
#define vl vector<LL>
#define pb push_back
#define endl "\n"



string solve()
{
   int N;
   cin >> N;
   using pii = pair<int,int>;

   vector<pii> v;
   int sum = 0;
   for (int i=0;i<N;i++) {
      int x;
      cin >> x;
      pii p = make_pair(x, i);
      v.pb(p);
      sum += x;
   }

   sort(v.begin(), v.end());
   int i = 0;
   string ret;
   while (i <= N-2 || v[N-1].first > 0) {
      assert(sum >= 2*v[N-1].first);
      if (v[N-1].first <= (sum - v[N-1].first - 2)) {
         // remove both from front
         if (v[i].first >= 2) {
            v[i].first -= 2; sum -= 2;
            ret.append(2, 'A' + v[i].second);
            ret.append(" ");
         } else if (v[i].first == 1) {
            ret.append(1, 'A' + v[i].second);
            v[i].first --; sum--;
            i ++;
            ret.append(1, 'A' + v[i].second);
            v[i].first --; sum--;
            ret.append(" ");
         } else {
            i++;
         }
      } else if (v[N-1].first == (sum - v[N-1].first - 1)) {
         if (v[i].first != 0) {
            ret.append(1, 'A' + v[i].second);
            v[i].first --; sum--;
            ret.append(" ");
         } else {
            i++;
         }
      } else {
         if (v[i].first != 0 && v[N-1].first != 0) {
            ret.append(1, 'A' + v[i].second);
            v[i].first --; sum--;
            ret.append(1, 'A' + v[N-1].second);
            v[N-1].first --; sum--;
            ret.append(" ");
         } else if (v[i].first != 0) {
            ret.append(1, 'A' + v[i].second);
            v[i].first --; sum--;
            ret.append(" ");
         } else {
            i++;
         }
      }
   }

   // cout << ret << endl;
   assert(sum == 0);
   for (auto it : v) {
      assert(it.first == 0);
   }

   size_t sz = ret.size();
   if (ret[sz-1] == ' ') {
      ret = ret.substr(0, sz-1);
   }
   return ret;
}

int main()
{
   ios_base::sync_with_stdio(false);
   ULL T = 0;
   cin >> T;
   for (ULL i = 1; i <= T; ++i)
   {
      cout << "Case #" << i << ": " << solve();
      cout << endl;
   }

   return 0;
}
