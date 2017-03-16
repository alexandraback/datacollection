#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int tt=1; tt<=t; tt++)
    {
        int a[128] = {};
        int k;

        for (int z=0; z<2; z++)
        {
            cin >> k;

            for (int i=1; i<=4; i++)
                for (int j=0; j<4; j++)
                {
                    int x;
                    cin >> x;
                    a[x] += i == k;
                }
        }

        int x = -1;
        int y = -1;

        for (int i=0; i<128; i++)
            if (a[i] == 2)
            {
                y = x;
                x = i;
            }

        cout << "Case #" << tt << ": ";
        if (!~x)
            cout << "Volunteer cheated!";
        else if (~y)
            cout << "Bad magician!";
        else cout << x;
        cout << endl;
    }
    return 0;
}
