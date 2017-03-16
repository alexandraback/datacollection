#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<set>
#include<iomanip>
#include<complex>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<bitset>
#include<memory.h>
#include<cassert>
#include<ctime>

using namespace std;

#pragma comment(linker, "/STACK:36777216")

#define For(i,l,r) for (int i = l; i < r + 1; i ++)
#define ForI(it , s , T) for (T :: iterator it = s.begin(); it != s.end() ; ++ it )
#define LL long long
#define iinf 2000000000
#define linf 4000000000000000000LL
#define MOD  1000000007
#define Pi 3.1415926535897932384
#define bit(mask,i) ((mask>>i)&1)
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define sqr(x) ((x)*(x))
#define pause cin.get();cin.get();
#define fir first
#define sec second
#define ln(x) log(x)
#define pii pair<int,int>

const int Nmax = 200100;
const int Direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

inline void printTest() {
       static int test_number = 0;
       cout << "Case #";
       test_number ++;
       cout << test_number << ": ";
}
int n;
int d[Nmax*10];

inline void upd(int idx, int x) {
       if (d[idx] == 0) d[idx] = x;
       else
           d[idx] = min(d[idx], x);
}
int main() {
    ios_base::sync_with_stdio(0);
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int test;
    cin >> test;
    while (test --> 0){ 
          /*cin >> n;
          
          for (int i = 1;i<= n ;i ++)
              d[i] = 0;
          d[1] = 1;
          for (int i = 1;i < n ;i ++) {
              if (d[i] == 0) continue;
              upd(i + 1, d[i] + 1);
              int x = 0;
              for (int j = i; j > 0 ; j /= 10)
                 x = (x * 10) + (j % 10);
              if (x <= n && x > i){
                 upd(x,d[i] + 1);
              }
          }
          
          printTest();
          cout << d[n] << endl;*/
          int r,c,n;
          cin >> r >> c >> n;
          
          int best = iinf;
          for (int mask = 0; mask < (1 << (r * c)); mask ++) {
              int cc = __builtin_popcount(mask);
              if (cc != n) continue;
              int current = 0;
              for (int i = 0 ;i < r * c ;i ++) {
                  if ((i + 1) % c != 0) {
                     current += (bit(mask,i) && bit(mask,i + 1));
                  }
                  if (i + c < r* c){ 
                     current += (bit(mask,i) && bit(mask,i + c));
                  }
              }
              best = min(best, current);
          }
          assert(best  != iinf);
          printTest();
          cout << best << endl;
          
    }
    return 0;
}
