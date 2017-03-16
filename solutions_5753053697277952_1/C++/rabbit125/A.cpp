// Google Code Jam Template by rabbit125 @2015/04/18
/* Libs. */
#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
/* ShortCut Vars. */
#if __WIN32__
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif // __WIN32__
#define BG   begin
#define CL   clear
#define ED   end
#define FR   first
#define MP   make_pair
#define SC   second
#define SZ   size
#define PB   push_back
#define PF   push_front
#define PPB  pop_back
#define PPF  pop_front
#define lg      std::__lg
#define __count __builtin_popcount
/* Type ShortCuts */
typedef unsigned int        UI;
typedef long long          LLI;
typedef unsigned long long ULL;
typedef long double         LD;
/* Function ShortCuts */
#define MS0(x) memset(x, 0, sizeof(x))
#define MS1(x) memset(x, -1, sizeof(x))
/* C++11 */
// __cplusplus is a int: 201103
#if __cplusplus > 201103L
    #include <tuple>
    #define MT make_tuple
    typedef tuple<int, int> TII;
#endif
/* Define Value Vars. */
#define BIT         17
#define INF 2000000000
#define MOD 1000000007
#define STRMAX    1000
#define MAX    1200000
/* Time Evaluation */
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
/* EPS */
const double eps = 1e-7 ;
using namespace std ;
/* Start Code Here */
int p[26] ;
int sum, N ;
vector<string> ans ;
bool Checker( int a, int b, int afsum )
{
    int lim = afsum % 2 ? (afsum+1)/2 : afsum/2 + 1 ;
    for( int k = 0 ; k < N ; k++ )
        if( k != a && k != b )
            if( p[k] >= lim )
                return 0 ;
    return 1 ;
}
int main( )
{
    //freopen( "A-small-attempt0.in" , "r" , stdin ) ;
    //freopen( "A-small-attempt0.out" , "w" , stdout ) ;
    freopen( "A-large.in" , "r" , stdin ) ;
    freopen( "A-large.out" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        ans.clear() ;
        sum = 0 ;
        scanf( "%d", &N ) ;
        for( int i = 0 ; i < N ; i++ )
        {
            scanf( "%d" , &p[i] ) ;
            sum += p[i] ;
        }
        char ct[3] = {""};
        bool pass = 0 ;
        while( sum != 0 )
        {
            pass = 0 ;
            for( int i = 0 ; i < N ; i++ )
            {
                for( int j = 0 ; j < N ; j++ )
                {
                    if( i != j )
                        if( p[i] >= 1 && p[j] >= 1 && Checker( i, j, sum-2 ) )
                        {
                            sum -= 2 ;
                            p[i] -= 1 ;
                            p[j] -= 1 ;
                            pass = 1 ;
                            ct[0] = 'A' + i ;
                            ct[1] = 'A' + j ;
                            ct[2] = '\0' ;
                            string cct(ct);
                            ans.push_back( cct ) ;
                        }
                    else
                        if( p[i] >= 2 && Checker( i, i, sum-2 ) )
                        {
                            sum -= 2 ;
                            p[i] -= 1 ;
                            p[i] -= 1 ;
                            pass = 1 ;
                            ct[0] = 'A' + i ;
                            ct[1] = 'A' + i ;
                            ct[2] = '\0' ;
                            string cct(ct);
                            ans.push_back( cct ) ;

                        }
                    if( pass ) break ;
                }
                if( pass ) break ;
            }
            if( pass == 0 )
                for( int i = 0 ; i < N ; i++ )
                {
                    if( p[i] >= 1 && Checker( i, i, sum-1 ) )
                    {
                        sum -= 1 ;
                        p[i] -= 1 ;
                        pass = 1 ;
                        ct[0] = 'A' + i ;
                        ct[1] = '\0' ;
                        string cct(ct);
                        ans.push_back( cct ) ;
                    }
                    if( pass )
                        break ;
                }
        }
        printf( "Case #%d:" , T++  ) ;
        int vs = ans.size() ;
        for( int i = 0 ; i < vs ; i++ )
            printf( " %s", ans[i].c_str() ) ;
        printf( "\n" ) ;
    }
    return 0 ;
}
/*
4
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1
*/
/*
Case #1: AB BA
Case #2: AA BC C BA
Case #3: C C AB
Case #4: BA BB CA
*/
