#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <memory.h>
using namespace std;
 
#define max(a,b) ((a)>(b)?(a):(b))
#define FOR0(i,n) for( i = 0 ; i < n ; ++i )
#define FOR1(i,n) for( i = 1 ; i <= n ; ++i )
#define sys_p system( "pause" )
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
 
typedef long long LL ;
const LL INF = (LL)1e18 ;
const LL MOD = (LL)1e9 + 9 ;

struct thing
{
     LL l, r ;
     thing(){}
     thing(LL L,LL R){l=L,r=R;}
};

bool in( thing a, thing b )
{
      return a.l >= b.l && a.r <= b.r ;
}
 
main()
{  
      int t ;
      cin >> t ;
      while( t-- )
      {
        int n, k, p, x, y, i, j ; thing a[600],b[600] ; 
        cin >> n >> k >> p ; 
        FOR0(i,k)
          cin >> a[i].l >> a[i].r ;
        FOR0(i,p)
          cin >> b[i].l >> b[i].r ;
        FOR0(i,k)
        {
          if( a[i].l == a[i].r )
            continue ;
          FOR0(j,p)
          {
            if( a[i].l == b[j].l && a[i].r == b[j].r )
              continue ;
            if( (b[j].l < a[i].l && b[j].r >= a[i].l) || (b[j].l >= a[i].l && b[j].r <= a[i].r) || (b[j].l > a[i].l && b[j].l <= a[i].r && b[j].r > a[i].r) )
              break ;
          }
          cout << i <<  " "  << j << endl ;
          if( j < p ) 
            break ;
        }
        if( i == k )
          cout << "Yes" << endl ;
        else
          cout << "No" << endl ;
      }
}
