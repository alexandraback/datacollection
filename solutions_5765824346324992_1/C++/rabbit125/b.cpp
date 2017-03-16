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
#define MAX      12000
/* Time Evaluation */
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
/* EPS */
const double eps = 1e-7 ;
using namespace std ;
/* Start Code Here */
int b ;
LLI n ;
LLI B[ MAX ] ;
LLI CanBe( LLI x )
{
    LLI ret = 0 ;
    for( int i = 0 ; i < b ; i++ )
    {
        ret += x / B[i] + ( x % B[i] > 0 ) ;
    }
    return ret ;
}
int main( )
{
    //freopen( "B-small-attempt1.in" , "r" , stdin ) ;
    //freopen( "B-small-attempt1.out" , "w" , stdout ) ;
    freopen( "B-large.in" , "r" , stdin ) ;
    freopen( "B-large.out" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        scanf( "%d%lld" , &b , &n )  ;
        for( int i = 0 ; i < b ; i++ )
            scanf( "%lld" , &B[i] ) ;
        LLI Max = (LLI)INF * INF , Min = 0 , Mid ;
        LLI cnt = 0 ;
        while( Max != Min + 1 )
        {
            //printf( "%lld %lld\n" , Mid , CanBe( Mid ) ) ;
            Mid = (Max + Min) / 2 ;
            if( CanBe( Mid ) < n )
                Min = Mid ;
            else
                Max = Mid ;
            cnt++ ;
            if( cnt > 10000000 )
                break ;
        }
        int ans = -1 ;
        int Mina = CanBe( Min ) ;
        //printf( "%lld %lld\n%lld %lld\n" , Max , CanBe( Max ) , Min , CanBe( Min ) ) ;
        int aa, bb ;
        cnt = 0 ;
        for( int i = 0 ; i < b ; i++ )
        {
            aa = Min / B[i] + ( Min % B[i] > 0 ) ;
            bb = Max / B[i] + ( Max % B[i] > 0 ) ;
            if( aa != bb )
                cnt++ ;
            if( cnt + Mina == n )
            {
                ans = i+1 ;
                break ;
            }
        }
        printf( "Case #%d: %d\n" , T++ , ans ) ;
    }
    return 0 ;
}
/*
3
2 4
10 5
3 12
7 7 7
3 8
4 2 1
*/
/*
test output data
*/
