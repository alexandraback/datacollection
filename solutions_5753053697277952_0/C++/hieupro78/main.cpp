#include <bits/stdc++.h>
using namespace std;


int main() {
   //freopen("input.txt", "r", stdin);
   int tc;
   cin >> tc;
   for (int cs = 1; cs <= tc; cs ++) {
      cout << "Case #" << cs << ":";
      int n;
      cin >> n;
      priority_queue <pair <int, int> > pq;
      int sum = 0;
      for (int i = 0; i < n; i ++) {
         int p;
         cin >> p;
         sum += p;
         pq.push({p, i});
      }

      if (sum % 2 == 1) {
         auto a = pq.top(); pq.pop();
         cout << " " << char('A' + a.second);
         a.first --;
         if (a.first > 0) pq.push(a);
      }
      while (!pq.empty()) {
         assert(pq.size() >= 2);
         cout << " ";
         for (int i = 0; i < 2; i ++) {
            auto a = pq.top(); pq.pop();
            cout << char('A' + a.second);
            a.first --;
            if (a.first > 0) pq.push(a);
         }
      }
      cout << endl;
   }
}
