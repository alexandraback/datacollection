#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int V[17];

void read()
{
    int row, x;
    cin >> row;
    for (int i=1; i<=4; i++)
    {
        for (int j=1; j<=4; j++)
        {
            cin >> x;
            if (i == row)
                V[x]++;
        }
    }
}

int main()
{
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int nc;
    cin >> nc;
    for (int tc=1; tc<=nc; tc++)
    {
        memset(V, 0, sizeof(V));
        read(); read();
        int cant = 0, ans=-1;
        for (int i=1; i<=16; i++)
        {
            if (V[i] > 1)
            {
                cant++;
                ans = i;
            }
        }
        cout << "Case #" << tc << ": ";
        if (cant == 1)
        {
            cout << ans << endl;
        }
        else if (cant > 1)
        {
            cout << "Bad magician!" << endl;
        }
        else
        {
            cout << "Volunteer cheated!" << endl;
        }
    }
    fclose (stdout);
    return 0;
}

