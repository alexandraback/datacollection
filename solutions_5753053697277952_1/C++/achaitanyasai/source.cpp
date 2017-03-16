#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define all(a)  a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define fill(a, x) memset(a, x, sizeof(a));
#define mod 1000000007
#define _for(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

using namespace std;
struct cmp {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const{
      if(a.first <= b.first) return true;
      return false;
    }
};

int N;
set<pair<int, int>, cmp> a;

int main() {
   int T;
   cin >> T;
   int x;
   for(int test = 1; test <= T; ++test){
      scanf("%d", &N);
      for(int n = 0; n < N; ++n){
         scanf("%d", &x);
         a.insert(mp(x, n));
      }
      vector<string> res;
      while(a.sz > 0){
         pair<int, int> tmp = *a.rbegin();
         set<pair<int, int> >::iterator it;
         set<pair<int, int> >::iterator it1;
         it = a.end();
         --it;
         a.erase(it);
         if(tmp.ff == 1){
            if(a.sz == 0 || a.sz >= 2){
               string p = "";
               p += (char)(tmp.ss + 'A');         
               res.pb(p);
               continue;
            }
            pair<int, int> tmp1 = *a.rbegin();
            if(a.sz == 1){
               tmp.ff -= 1;
               tmp1.ff -= 1;
               it = a.end();
               --it; 
               a.erase(it);
               string p = "";
               p += (char)(tmp.ss + 'A');         
               p += (char)(tmp1.ss + 'A');
               res.pb(p);
               if(tmp.ff > 0) a.insert(tmp);
               if(tmp1.ff > 0) a.insert(tmp1);
            }
         }
         else if(tmp.ff >= 2){
            if(a.sz == 0){
               tmp.ff -= 2;
               string p = "";
               p += (char)(tmp.ss + 'A');         
               p += (char)(tmp.ss + 'A');         
               res.pb(p);
               if(tmp.ff > 0) a.insert(tmp);
            }
            else{
               pair<int, int> tmp1 = *a.rbegin();
               if(tmp.ff - tmp1.ff <= 1){
                  tmp.ff -= 1;
                  tmp1.ff -= 1;
                  it = a.end();
                  --it; 
                  a.erase(it);
                  string p = "";
                  p += (char)(tmp.ss + 'A');         
                  p += (char)(tmp1.ss + 'A');
                  res.pb(p);
                  if(tmp.ff > 0) a.insert(tmp);
                  if(tmp1.ff > 0) a.insert(tmp1);
               }
               else{
                  tmp.ff -= 2;
                  string p = "";
                  p += (char)(tmp.ss + 'A');         
                  p += (char)(tmp.ss + 'A');         
                  res.pb(p);
                  a.insert(tmp);
               }
            }
         }
      }
      printf("Case #%d: ", test);
      bool f = 0;
      _for(it, res){
         if(f){
            cout << " " << (*it);
         }
         else{
            cout << (*it);
            f = 1;
         }
      }
      cout << endl;
   }
   return 0;
}