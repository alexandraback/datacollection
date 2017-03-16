// Google Code Jam Template by rabbit125 @2014/10/01
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
int n ;
int N[ MAX ] ;
int main( )
{
    freopen( "A-small-attempt0.in" , "r" , stdin ) ;
    freopen( "A-small-attempt0.out" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        scanf( "%d" , &n ) ;
        for( int i = 0 ; i < n ; i++ )
            scanf( "%d" , &N[i] ) ;
        int a1 = 0 , a2 = 0 ;
        int r2 = 0 ;
        for( int i = 1 ; i < n ; i++ )
        {
            if( N[i] < N[i-1] )
                r2 = max( r2 , N[i-1] - N[i] ) ;
            if( N[i] < N[i-1] )
                a1 += N[i-1] - N[i] ;
        }
        for( int i = 0 ; i < n-1 ; i++ )
            if( N[i] <= r2 )
                a2 += N[i] ;
            else
            {
                a2 += r2 ;
            }
        printf( "Case #%d: %d %d\n" , T++ , a1 , a2 ) ;
    }
    return 0 ;
}
/*
4
4
10 5 15 5
2
100 100
8
81 81 81 81 81 81 81 0
6
23 90 40 0 100 9
*/
