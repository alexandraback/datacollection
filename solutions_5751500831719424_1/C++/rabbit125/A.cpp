// Google Code Jam Template by rabbit125 @2014/02/13
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <climits>
#include <bits/stdc++.h>
using namespace std ;
/* Define Useful Vars. */
#define ULL  unsigned long long
#define LLI  long long
#define BIT         17
#define INF 1000000000
#define MOD 1000000007
#define MAX      12000
int n ;
char w[ 120 ][ 120 ] ;
struct W
{
    char c ;
    int cnt ;
};
vector <W> v[ 120 ] ;
int main( )
{
    freopen( "A-large.in" , "r" , stdin ) ;
    freopen( "A-l0.out" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        scanf( "%d" , &n ) ;
        W Now ;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf( "%s" , &w[i] ) ;
            v[i].clear( ) ;
            Now.c = w[i][0] ;
            Now.cnt = 0 ;
            for( int j = 0 ; j < strlen( w[i] ) ; j++ )
            {
                Now.c = w[i][j] ;
                Now.cnt++ ;
                if( j+1 < strlen( w[i] ) && w[i][j] != w[i][j+1] )
                {
                    v[i].push_back( Now ) ;
                    Now.cnt = 0 ;
                }
            }
            v[i].push_back( Now ) ;
            for( int j = 0 ; j < v[i].size() ; j++ )
                ;//printf( "%c %d\n" , v[i][j].c , v[i][j].cnt ) ;

        }
        bool ok = 1 ;
        for( int i = 1 ; i < n ; i++ )
        {
            if( v[0].size() == v[i].size() )
            {
                for( int j = 0 ; j < v[0].size() ; j++ )
                    if( v[0][j].c != v[i][j].c )
                        ok = 0 ;
            }
            else
                ok = 0 ;
        }
        if( ok == 0 )
            printf( "Case #%d: Fegla Won\n" , T++ ) ;
        else
        {
            int ans = 0 ;
            for( int i = 0 ; i < v[0].size() ; i++ )
            {
                vector<int> vc ;
                for( int j = 0 ; j < n ; j++ )
                    vc.push_back( v[j][i].cnt ) ;
                //sort( vc.begin() , vc.end() ) ;
                //int Mid = vc[ vc.size()/2 ] ;
                int Min = INF ;
                int pos ;
                for( int k = 0 ; k < n ; k++ )
                {
                    pos = 0 ;
                    for( int j = 0 ; j < n ; j++ )
                        pos += abs( vc[k]-v[j][i].cnt ) ;
                    Min = min( Min , pos ) ;
                }
                ans += Min ;
            }
            printf( "Case #%d: %d\n" , T++ , ans ) ;
        }
    }
    return 0 ;
}
/*
5
2
mmaw
maw
2
gcj
cj
3
aaabbb
ab
aabb
2
abc
abc
3
aabc
abbc
abcc

*/
/*
Case #1: 1
Case #2: Fegla Won
Case #3: 4
Case #4: 0
Case #5: 3
*/
