#include <stdio.h>
#include <vector>
#include <iterator>
#include <algorithm>

typedef std::vector< int > IntSet;

void select_row(  IntSet & s )
{
    int row;
    scanf( "%d", &row );
    -- row;
    for( int i = 0; i < 4; ++ i )
    {
        for( int j = 0; j < 4; ++ j )
        {
            int v;
            scanf( "%d", &v );
            if( i == row )
                s.push_back( v );
        }
    }
    std::sort( s.begin(), s.end() );
}

int main()
{
    int tc;
    scanf("%d", &tc );
    for( int test = 1; test <= tc; ++ test )
    {
        IntSet rs1, rs2;
        select_row( rs1 );
        select_row( rs2 );

        IntSet res;
        std::set_intersection( rs1.begin(), rs1.end(), rs2.begin(), rs2.end(), std::back_inserter(res) );

        int count = res.size();
        if( count == 0 )
            printf( "Case #%d: Volunteer cheated!\n", test );
        else if( count == 1 )
            printf( "Case #%d: %d\n", test, res.front() );
        else
            printf( "Case #%d: Bad magician!\n", test );
            
    }
    return 0;
}
