#include <iostream>
#include <set>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <cmath>

using namespace std;


int nbT, nbStr;
string str[100];
int pos[100];
int nbCar[100];


int getRep(void)
{
    int rep = 0;
    while (true)
    {
        int isOver = 0;
        for (int i = 0; i < nbStr; i++)
            if (str[i].size() == pos[i])
                isOver++;
        //cout << isOver << endl;
        if (isOver != 0 && isOver != nbStr)
            return -1;
        else if (isOver == nbStr)
            break;

        char curC = str[0][pos[0]];


        int maxNb = 0;

        for (int s = 0; s < nbStr; s++)
        {
            nbCar[s] = 0;
            if (pos[s] >= str[s].size() || str[s][pos[s]] != curC)
                return -1;
            while (pos[s] < str[s].size() && str[s][pos[s]] == curC)
            {
                pos[s]++;
                nbCar[s]++;
            }
            maxNb = max(maxNb, nbCar[s]);
        }

        int bestNbChange = 100*100*100*10;


        for (int bidule = 0; bidule <= maxNb; bidule++)
        {
            int curNbChange = 0;
            for (int s = 0; s < nbStr; s++)
                curNbChange += abs(nbCar[s]-bidule);

            bestNbChange = min(bestNbChange, curNbChange);
        }

        rep += bestNbChange;
    }

    return rep;
}









int main()
{
    freopen("large.in", "r", stdin);

    //freopen("t.out", "w", stdout);

    cin >> nbT;
    for (int t = 1; t <= nbT; t++)
    {
        cin >> nbStr;
        for (int i = 0; i < nbStr; i++)
        {
            pos[i] = 0;
            cin >> str[i];
        }


        int rep = getRep();
        cout << "Case #" << t << ": ";
        if (rep == -1)
            cout << "Fegla Won" << endl;
        else
            cout << rep << endl;

    }
    return 0;
}
