#include <iostream>
#include <cstdio>
using namespace std;

int been[20];

int main()
{
    freopen("input.in" , "r" , stdin );
    freopen("output.out" , "w" , stdout );

    int T;
    cin >> T;

    for ( int t = 1 ; t <= T ; t++ )
    {

        for ( int i = 1 ; i <= 16 ; i++ ) been[i] = 0 ;
        int twos = 0 , last = 0 ;

        for ( int k = 1 ; k <= 2 ; k++ )
        {
            int line;
            cin >> line;
            for ( int i = 1 ; i <= 4 ; i++ )
            {
                for ( int j = 1 ; j <= 4 ; j++ )
                {
                    int x;
                    cin >> x;
                    if ( i == line )
                    {
                        been[x]++;
                        if ( been[x] == 2 )
                        {
                            twos++;
                            last = x;
                        }
                    }

                }

            }
        }

        cout << "Case #" << t << ": ";

        if ( twos > 1 )
            cout << "Bad magician!" << endl;

        if ( twos == 0 )
            cout << "Volunteer cheated!" << endl;

        if ( twos == 1 )
                cout << last << endl;

    }

    return 0;
}
