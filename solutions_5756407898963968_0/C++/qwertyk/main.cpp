#include <iostream>

using namespace std;

int i, j, t, n, arr[4], x, y, v;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.out", "w", stdout);

    cin >> t;

    for(i = 1; i <= t; ++i)
    {
        v = 0;
        cin >> n;
        --n;
        for(j = 0; j < n; ++j)
            cin >> x >> x >> x >> x;
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
        for(j = ++n; j < 4; ++j)
            cin >> x >> x >> x >> x;
        
        cin >> n;
        --n;
        for(j = 0; j < n; ++j)
            cin >> x >> x >> x >> x;
        for(j = 0; j < 4; ++j)
        {
            cin >> x;
            if(x == arr[0] || x == arr[1] || x == arr[2] || x == arr[3])
            {
                ++v;
                y = x;
            }
        }
        for(j = ++n; j < 4; ++j)
            cin >> x >> x >> x >> x;

        if(v == 0) cout << "Case #" << i << ": Volunteer cheated!" << endl;
        else if(v == 1) cout << "Case #" << i << ": " << y << endl;
        else cout << "Case #" << i << ": Bad magician!" << endl;
    }

    return 0;
}
