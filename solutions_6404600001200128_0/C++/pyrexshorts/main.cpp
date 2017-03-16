#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("stuff.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, n, mush[10000] = {0};
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int y = 0, x = 0, r = 0;
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> mush[j];
        for(int i = 1; i < n; i++)
        {
            if(mush[i] - mush[i-1] < 0)
                x += mush[i] - mush[i-1];
        }
        for(int i = 1; i < n; i++)
        {
            r = min(r, mush[i] - mush[i-1]);
        }
        if(r > 0)
            y = 0;
        else
        {
            r = r * -1;
            for(int i = 0; i < n-1; i++)
            {
                y += min(r, mush[i]);
            }
        }
        if(x < 0)
            x *= -1;
        cout << "Case #" << i+1 << ": " << x << " " << y << endl;
    }
    return 0;
}
