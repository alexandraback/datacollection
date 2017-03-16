/*
 * Author:  Eyelids
 * Created Time:  2014/5/4 0:04:15
 * File Name: A.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
using namespace std;
const double eps(1e-8);
typedef long long lint;
#define clr(x) memset( x , 0 , sizeof(x) )
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clrs( x , y ) memset( x , y , sizeof(x) )
int T, n;
char s[110][110];
vector < pair<int, int> > p[110];

int main() {
    freopen( "A.in", "r", stdin );
    freopen( "A.out", "w", stdout );
    
    scanf( "%d", &T );
    int cas = 0;
    while ( T -- ) {
        scanf( "%d", &n );
        for ( int i = 0; i < n; i ++ ) {
            scanf( "%s", s[i] );
            int len = strlen( s[i] );
            
            p[i].clear();
            p[i].push_back( make_pair( s[i][0] - '0', 1 ) );
            for ( int j = 1; j < len; j ++ ) 
                if ( s[i][j] == s[i][j - 1] )
                    p[i][p[i].size() - 1].second ++;
                else 
                    p[i].push_back( make_pair( s[i][j] - '0', 1 ) );
        }
       
        bool flag = true; 
        int m = p[0].size();
        for ( int i = 1; i < n; i ++ ) 
            if ( m != (int)p[i].size() )
                flag = false;
        for ( int i = 0; i < m; i ++ )
            for ( int j = 1; j < n; j ++ )
                if ( p[j][i].first != p[j - 1][i].first )
                    flag = false;
            
        if ( !flag ) {
            printf( "Case #%d: Fegla Won\n", ++ cas );
            continue;
        }
       
        int ret = 0, tmp = 0; 
        for ( int i = 0; i < m; i ++ ) {
            int Min = 1000000000;
            for ( int j = 0; j < n; j ++ ) {
                tmp = 0;
                for ( int k = 0; k < n; k ++ )  
                    tmp += abs( p[j][i].second - p[k][i].second );
                Min = min( tmp, Min );
            }
            ret += Min;
        }
                  
        printf( "Case #%d: %d\n", ++ cas, ret );
    }

    return 0;
}






