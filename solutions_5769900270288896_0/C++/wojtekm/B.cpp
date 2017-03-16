#include <iostream>
#include <cmath>

using namespace std;

bool isOccupied[16][16];

int calculateUnhappiness(int r, int c)
{
    int res = 0;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            /*if(isOccupied[i][j]) cout << "1";
            else cout << "0";*/

            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};

            for(int k=0; k<4; k++)
            {
                int x2 = i+dx[k], y2 = j+dy[k];
                if(isOccupied[i][j] && x2 < r && x2 >= 0 && y2 < c && y2 >= 0 && isOccupied[x2][y2])
                    res++;
            }
        }
        //cout << "\n";
    }
    //cout << res << "\n";
    return res/2;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;

    for(int t=1; t<=T; t++)
    {
        int n, r, c;
        cin >> r >> c >> n;

        int res = 2000000;
        int tmp = 0;

        for(int i=0; i<pow(2, r*c); i++)
        {
            for(int i=0; i<16; i++)
                for(int j=0; j<16; j++)
                    isOccupied[i][j] = false;

            int numOfHouses = 0;
            for(int j=0; j<r*c; j++)
            {
                if(((i & ( 1 << j )) >> j) == 1)
                    numOfHouses++;
            }

            if(numOfHouses == n)
            {
                for(int j=0; j<r*c; j++)
                    if(((i & ( 1 << j )) >> j) == 1)
                        isOccupied[j/c][j%c] = true;

                res = min(res, calculateUnhappiness(r, c));
            }
        }

        cout << "Case #" << t << ": " << res << "\n";
    }

    return 0;
}
