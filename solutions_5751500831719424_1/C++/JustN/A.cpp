#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 105;
const int inf = 100000000;

int a[MAXN][MAXN];

int main()
{
    freopen("input.in" , "r" , stdin );
    freopen("output.out" , "w" , stdout );

    int T;
    cin >> T;

    for ( int tt = 1 ; tt <= T ; tt++ )
    {
        int N;
        string s , mask , t;
        bool wrong = false;
        cin >> N ;
        getline( cin , s );

        for ( int i = 1 ; i <= N ; i++ )
        {
            getline( cin , s );
            t = s[0];

            for ( int j = 0 ; j < MAXN ; j++ )
                a[i][j] = 0;

            a[i][1] = 1 ;

            for ( int j = 1 ; j < s.size() ; j++ )
            {
                if ( s[j] != s[j-1] ) t = t + s[j];
                a[i][ t.size() ]++;
            }

            if ( i == 1 ) mask = t;
            if ( mask != t ) wrong = true ;

        }


        if ( wrong )
        {
            cout << "Case #" << tt << ": Fegla Won" << endl;
        }
        else
        {
            int ans = 0;
            for ( int j = 1 ; j <= t.size() ; j++ )
            {
                int bestRes = inf ;
                for ( int k = 0 ; k < MAXN ; k++ )
                {
                    int res = 0;
                    for ( int i = 1 ; i <= N ; i++ )
                    {
                        res+= abs( a[i][j] - k );
                    }
                    bestRes = min( res , bestRes );
                }
                ans += bestRes;
            }
            cout << "Case #" << tt << ": " << ans << endl;
        }


    }

    return 0;
}
