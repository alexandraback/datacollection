#include <iostream>
#include <string>
#include <set>

using namespace std;

main()
{
    int T;
    cin >> T;

    for (int X = 1; X <= T; ++X)
    {
        int row;
        cin >> row;

        int next_number;

        set<int> Possibilities1;

        for (int i = 1; i <= 4; ++i)
        {
            for (int j = 1; j <= 4; ++j)
            {
                cin >> next_number;
                if (i == row)
                {
                    Possibilities1.insert(next_number);
                }
            }
        }

        cin >> row;

        set<int> Intersection;

        for (int i = 1; i <= 4; ++i)
        {
            for (int j = 1; j <= 4; ++j)
            {
                cin >> next_number;
                if (i == row)
                {
                    if (Possibilities1.count(next_number) > 0)
                    {
                        Intersection.insert(next_number);
                    }
                }
            }
        }
        

        cout << "Case #" << X << ": ";

        if (Intersection.size() == 0)
        {
            cout << "Volunteer cheated!";
        }
        else if (Intersection.size() == 1)
        {
            cout << *(Intersection.begin());
        }
        else
        {
            cout << "Bad magician!";
        }

        cout << endl;
    }
}
