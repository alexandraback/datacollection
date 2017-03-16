#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void Soloved()
{
    int n, v, row;
    int cntVist[17] = {0};
    for (int c = 0; c < 2; ++c)
    {
        cin >> row;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                cin >> v;
                if (i + 1 == row) ++cntVist[v];
            }
        }
    }

    int cntResult = 0, lastNum = -1;
    for (int i = 1; i <= 16; ++i)
        if (cntVist[i] == 2) ++cntResult, lastNum = i;

    if (cntResult == 0)
        puts("Volunteer cheated!");
    else if (cntResult == 1)
        printf("%d\n", lastNum);
    else
        puts("Bad magician!");

}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    int nT = 1;
    scanf("%d", &nT);
    for (int nCase = 1; nCase <= nT; ++nCase)
    {
        printf("Case #%d: ", nCase);
        Soloved();
    }

    return 0;
}