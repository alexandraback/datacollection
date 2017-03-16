#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int f[17], test, row;

int main(){
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &test);
    for (int uu = 1; uu <= test; uu++)
    {
        memset(f, 0, sizeof(f));
        printf("Case #%d: ", uu);
        for (int Q = 1; Q <= 2; Q++)
        {
            scanf("%d", &row);
            for (int i = 1; i <= 4; i++)
                for (int j = 1; j <= 4; j++)
                {
                    int x;
                    scanf("%d", &x);
                    if (i == row) ++f[x];
                }
        }
        int cnt = 0, position = 0;
        for (int i = 1; i <= 16; i++)
            if (f[i] == 2) ++cnt, position = i;
        if (!cnt) printf("Volunteer cheated!\n");
        else if (cnt == 1) printf("%d\n", position);
        else printf("Bad magician!\n");
    }
}
