#include <iostream>

using namespace std;

void skipRow()
{
    int t;
    cin >> t >> t >> t >> t;
}

void readRow(int* dest)
{
    cin >> dest[0] >> dest[1] >> dest[2] >> dest[3];
}

void solveCase()
{
    int row;
    int candidates1[4];
    int candidates2[4];

    cin >> row;
    for (int i = 1; i <= 4; ++i)
    {
        if (i == row)
            readRow(candidates1);
        else
            skipRow();
    }

    cin >> row;
    for (int i = 1; i <= 4; ++i)
    {
        if (i == row)
            readRow(candidates2);
        else
            skipRow();
    }

    int numCommon = 0;
    int common;
    for (int i = 0; i < 4; ++i)
    {
        int card = candidates1[i];
        for (int j = 0; j < 4; ++j)
        {
            if (card == candidates2[j])
            {
                ++numCommon;
                common = card;
            }
        }
    }
    
    if (numCommon == 0)
        cout << "Volunteer cheated!";
    else if (numCommon == 1)
        cout << common;
    else
        cout << "Bad magician!";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}