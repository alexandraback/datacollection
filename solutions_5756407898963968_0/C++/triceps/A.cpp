#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for ( int t = 1; t <= T; t++ ) {
        int grid[4][4], r1, r2;
        vector<int> v1,v2,v;
        cin >> r1;
        for ( int i = 0; i < 4; i++ )
            for ( int j = 0; j < 4; j++ )
                cin >> grid[i][j];
        v1.assign( grid[r1-1]+0, grid[r1-1]+4 );
        cin >> r2;
        for ( int i = 0; i < 4; i++ )
            for ( int j = 0; j < 4; j++ )
                cin >> grid[i][j];
        v2.assign( grid[r2-1]+0, grid[r2-1]+4 );
        sort( v1.begin(), v1.end() );
        sort( v2.begin(), v2.end() );
        set_intersection( v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v) );
        cout << "Case #" << t << ": ";
        switch (v.size())
        {
        case 0:
            cout << "Volunteer cheated!" << endl;
            break;
        case 1:
            cout << v[0] << endl;
            break;
        default:
            cout << "Bad magician!" << endl;
            break;
        }
    }
    return 0;
}
