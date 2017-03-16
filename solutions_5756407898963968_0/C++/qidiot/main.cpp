#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int ck[20];
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t , n , a;
    scanf( "%d" , &t );
    for( int cas=1 ; cas<=t ; cas++ )
    {
        memset( ck , 0 , sizeof( ck ) );
        scanf( "%d" , &n );
        for( int i=1 ; i<5 ; i++ )
        {
            for( int j=1 ; j<5 ; j++ )
            {
                scanf( "%d" , &a );
                if( i == n ) ck[a]++;
            }
        }
        scanf( "%d" , &n );
        for( int i=1 ; i<5 ; i++ )
        {
            for( int j=1 ; j<5 ; j++ )
            {
                scanf( "%d" , &a );
                if( i == n ) ck[a]++;
            }
        }
        int p = 0 , ans = -1;
        for( int i=1 ; i<=16 ; i++ )
            if( ck[i] == 2 )
            {
                p++; ans = i;
            }
        if( p >= 2 ) printf( "Case #%d: Bad magician!\n" , cas );
        else if( p == 1 ) printf( "Case #%d: %d\n" , cas , ans );
        else printf( "Case #%d: Volunteer cheated!\n" , cas );
    }
    return 0;
}
