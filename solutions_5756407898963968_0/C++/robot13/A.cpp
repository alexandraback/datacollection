#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;


int main()
{
    int t;
    scanf("%d", &t);
    int a[5][5];
    bool flag[17];
    for(int CASE = 1; CASE <= t; CASE ++)
    {
        int first, second;
        scanf("%d", &first);
        for(int i = 1; i <= 4; i ++)
            for(int j = 1; j <= 4; j ++)
                scanf("%d", &a[i][j]);
        for(int i = 1; i <= 16; i ++)
            flag[i] = false;
        for(int i = 1; i <= 4; i ++)
        {
            flag[a[first][i]] = true;
        }
        scanf("%d", &second);
        for(int i = 1; i <= 4; i ++)
            for(int j = 1; j <= 4; j ++)
                scanf("%d", &a[i][j]);
        for(int i = 1; i <= 4; i ++)
        {
            if(i != second)
            {
                for(int j = 1; j <= 4; j ++)
                {
                    flag[a[i][j]] = false;
                }
            }
        }
        int res;
        int num = 0;
        for(int i = 1; i <= 16; i ++)
        {
            if(flag[i])
            {
                res = i;
                num ++;
            }
        }
        if(num == 0)
            printf("CASE #%d: Volunteer cheated!\n", CASE);
        else if(num > 1)
            printf("Case #%d: Bad magician!\n", CASE);
        else
            printf("Case #%d: %d\n", CASE, res);
    }
    return 0;
}
