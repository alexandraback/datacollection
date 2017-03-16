#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 1010;

int gcd(int a,int b) {
   return b ? gcd(b, a % b) : a;
}

int lcm(int a,int b) {
   return a * (b / gcd(a,b));
}

int b[MAXN];
int des[MAXN];

int main(){
#ifndef ONLINE_JUDGE
   // freopen("in","r",stdin);
   freopen("B-small.in","r",stdin);
   freopen("B-small.out","w",stdout);
#endif
   int casos;
   cin >> casos;
   for(int caso = 1 ; caso <= casos ; caso++){
      int n, m;
      cin >> n >> m;
      for(int i = 0 ; i < n ; i++){
         cin >> b[i];
      }
      int L = b[0];
      for(int i = 1 ; i < n ; i++ ){
         L = lcm(L, b[i]);
      }
      int c = 0;
      for(int i = 0 ; i < n ; i++ ){
         c += L / b[i];
      }
      m %= c;
      if(m == 0) {
         m = c;
      }
      memset(des, 0, sizeof des);
      int p = -1;
      for(int i = 0 ; i < m ; i++) {//for all customers
         int mini = -1;
         p = -1;
         for(int j = 0 ; j < n ; j++){
            if(mini == -1 || des[j] < mini) {
               mini = des[j];
               p = j;
            }
         }
         des[p] += b[p];
      }
      cout << "Case #" << caso << ": " << (p+1) << endl;
   }
   return 0;
}