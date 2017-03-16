#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> partie;

int main()
{
    int T;
    cin >> T;
    int ile;

    int a, b, n;
    char x;

    for(int t = 1; t <= T; ++t)
    {
        partie.clear();
        ile = 0;
        cin >> n;
        for(int i = 0; i < n; ++i)
        {
            cin >> a;
            partie.push_back(make_pair(a, i));
            ile+=a;
        }

        cout << "Case #" << t << ": ";

        while(ile > 0)
        {
            sort(partie.rbegin(), partie.rend());
            /*for(int i  = 0; i < partie.size(); ++i)
            {
                cout << partie[i].first << " " << partie[i].second << endl;
            }*/
            if (partie[0].first - 1 > (ile - 1) / 2)
            {
                x = 65 + partie[0].second;
                ile-=2;
                partie[0].first -= 2;
                cout << x << x << " ";
            }
            else if (partie[1].first > (ile - 1) / 2)
            {
                x = 65 + partie[0].second;
                ile-=2;
                partie[0].first -= 1;
                cout << x;
                x = 65 + partie[1].second;
                partie[1].first -= 1;
                cout << x << " ";
            }
            else
            {
                ile -= 1;
                x = 65 + partie[0].second;
                partie[0].first-=1;
                cout << x << " ";
            }
        }

        cout << endl;
    }
    return 0;
}
