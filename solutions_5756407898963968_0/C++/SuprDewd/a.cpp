#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T &x) { return x.size(); }

// assert or gtfo

int board1[4][4], board2[4][4];

int main()
{
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++)
    {
        int r1;
        scanf("%d\n", &r1);

        for  (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                scanf("%d", &(board1[i][j]));
            }
        }

        int r2;
        scanf("%d\n", &r2);

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                scanf("%d", &(board2[i][j]));
            }
        }

        vector<int> a, b;
        for (int i = 0; i < 4; i++)
            a.push_back(board1[r1 - 1][i]);

        for (int i = 0; i < 4; i++)
            b.push_back(board2[r2 - 1][i]);

        sort(all(a));
        sort(all(b));

        vector<int> c(100);
        int cnt =set_intersection(all(a), all(b), c.begin()) - c.begin();

        printf("Case #%d: ", t+1);

        if (cnt == 1)
            printf("%d\n", c[0]);
        else if (cnt == 0)
            printf("Volunteer cheated!\n");
        else
            printf("Bad magician!\n");
    }

    return 0;
}

