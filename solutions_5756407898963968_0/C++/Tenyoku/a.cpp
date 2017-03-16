#include <cstdio>

int rn[2];
int deck[2][4][4];

int main()
{
    int T;
    scanf("%d", &T);
    for(int ca=1; ca<=T; ++ca)
    {
        for(int k=0; k<2; ++k)
        {
            scanf("%d", &rn[k]);
            --rn[k];
            for(int i=0; i<4; ++i)
                for(int j=0; j<4; ++j)
                    scanf("%d", &deck[k][i][j]);
        }
        bool check[17];
        for(int i=0; i<17; ++i) check[i] = false;
        for(int j=0; j<4; ++j) check[deck[0][rn[0]][j]] = true;
        int ans, cnt=0;
        for(int j=0; j<4; ++j)
            if(check[deck[1][rn[1]][j]]==true)
            {
                ans=deck[1][rn[1]][j];
                cnt++;
            }
        printf("Case #%d: ", ca);
        if(cnt == 0)
            puts("Volunteer cheated!");
        else if(cnt > 1)
            puts("Bad magician!");
        else
            printf("%d\n", ans);
    }
    return 0;
}
