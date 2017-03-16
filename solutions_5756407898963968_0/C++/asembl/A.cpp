#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std ;
int cnt[20] ;

int main()
{
    int T ;
    int test = 1 ;

    cin >> T ;
    while ( T-- )
    {
        int r ;

        cin >> r ;
        memset( cnt , 0 , sizeof cnt );

        for ( int i = 1 ; i <= 4 ; ++i )
            for ( int j = 1 ; j <= 4 ; ++j )
            {
                int x ;
                cin >> x;
                if ( i == r )
                    cnt[ x ] ++;
            }

        cin >> r ;
        for ( int i = 1 ; i <= 4 ; ++i )
            for ( int j = 1 ; j <= 4 ; ++j )
            {
                int x ;
                cin >> x;
                if ( i == r )
                    cnt[ x ] ++;
            }
        int flag = 0 ;
        int ans = 0 ;

        for ( int i = 0 ; i < 20 ; ++i )
        {
            if ( cnt[i] >= 2 )
            {
                ++flag ;
                ans = i ;
            }
        }
        cout << "Case #" << test++ << ": ";
        if (flag == 0 )
            cout << "Volunteer cheated!\n";
        else if (flag == 1 )
            cout << ans << endl ;
        else
            cout << "Bad magician!\n" ;
    }

    return 0;
}
