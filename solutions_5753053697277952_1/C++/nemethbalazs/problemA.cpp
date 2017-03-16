#include <bits/stdc++.h>
using namespace std;

int p[1000];

int main()
{
    int t;

    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        int s = 0;

        cin >> n;

        for (char c = 'A'; c < 'A'+n; ++c)
        {
            cin >> p[c];
            s += p[c];
        }

        cout << "Case #" << i+1 << ": ";

        while (s>1)
        {
            char max1 = 'A', max2 = 'A';

            for (char c = 'A'; c < 'A'+n; ++c)
            {
                if (p[c]>=p[max1])
                {
                    max1 = c;
                }
            }

            for (char c = 'A'; c < 'A'+n; ++c)
            {
                //cout << c << endl;

                if (c != max1 && p[c]>=p[max2])
                {
                    max2 = c;
                }
            }

            if (p[max2] == 1 && p[max1] == 1 && s == 3)
            {
                cout << max1 << ' ';
                p[max1]--;
                s--;
            }
            else
            {
                p[max1]--;
                p[max2]--;
                s -= 2;

                cout << max1 << max2 << ' ';
            }
        }

        if (s == 1)
        {
            for (char c = 'A'; c < 'A'+n; ++c)
            {
                if (p[c])
                {
                    cout << c;
                }
            }
        }

        cout << endl;
    }
}
