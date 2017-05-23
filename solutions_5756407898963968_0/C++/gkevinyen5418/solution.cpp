#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int T;
bool OAO[20];
int row;
int card[4][4];

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    scanf("%d", &T);

    for(int Ti = 0; Ti < T; Ti++)
    {
        memset(OAO, 0, sizeof(OAO));
        scanf("%d", &row);

        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                scanf("%d", &card[i][j]);
                if( i == row-1 ) OAO[ card[i][j]] = true;
            }

        scanf("%d", &row);

        int cnt = 0, pre;

        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                scanf("%d", &card[i][j]);
                if( i == row-1 && OAO[ card[i][j]] ) cnt++, pre = card[i][j];
            }

        printf("Case #%d: ", Ti+1);

        if( cnt == 0 ) puts("Volunteer cheated!");
        else if( cnt == 1 ) printf("%d\n", pre);
        else puts("Bad magician!");
    }
}
