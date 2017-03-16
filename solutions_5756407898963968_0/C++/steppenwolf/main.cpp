#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void readInput(int &answer, int grid[4][4])
{
    cin >> answer;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin >> grid[i][j];
        }
    }
}

void solve()
{
    int answer;
    int grid[4][4];
    set<int> rows[2];

    for (int i = 0; i < 2; ++i)
    {
        readInput(answer, grid);
        rows[i].insert(grid[answer - 1], grid[answer - 1] + 4);
    }

    vector<int> setUnion(4, 0);
    vector<int>::iterator it;

    it = set_intersection(rows[0].begin(), rows[0].end(), rows[1].begin(), rows[1].end(), setUnion.begin());
    setUnion.resize(it - setUnion.begin());

    int unionSize = setUnion.size();

    if (unionSize == 1)
    {
        cout << setUnion[0] << endl;
    }
    else if (unionSize > 1)
    {
        cout << "Bad magician!" << endl;
    }
    else
    {
        cout << "Volunteer cheated!" << endl;
    }
}

int main()
{
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test)
    {
        cout << "Case #" << test << ": ";
        solve();
    }

    return 0;
}
