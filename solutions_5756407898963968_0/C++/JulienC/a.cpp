#include <iostream>
#include <vector>

using namespace std;

void solve(int t)
{
    int ans1;
    cin >> ans1;

    int tab1[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> tab1[i][j];
        }
    }

    int ans2;
    cin >> ans2;

    int tab2[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> tab2[i][j];
        }
    }

    int *chosenRow1 = tab1[ans1 - 1];
    int *chosenRow2 = tab2[ans2 - 1];
    vector<int> soln;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (chosenRow1[i] == chosenRow2[j])
            {
                soln.push_back(chosenRow1[i]);
            }
        }
    }

    cout << "Case #" << t << ": ";
    if (soln.empty())
    {
        cout << "Volunteer cheated!" << endl;
    }
    else if (soln.size() == 1)
    {
        cout << soln[0] << endl;
    }
    else
    {
        cout << "Bad magician!" << endl;
    }
}

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        solve(t);
    }

    return 0;
}

