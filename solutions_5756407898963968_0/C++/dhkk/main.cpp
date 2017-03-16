#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int ans[8], n;

int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int _, cas = 0;
    scanf("%d", &_);
    while (_--)
    {
        scanf("%d", &n);
        n--;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int a;
                scanf("%d", &a);
                if (i == n) ans[j] = a;
            }
        }
        scanf("%d", &n);
        n--;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int a;
                scanf("%d", &a);
                if (i == n) ans[j+4] = a;
            }
        }
        sort(ans, ans+8);
        int cnt = 0, p;
        for (int i = 0; i < 7; i++)
        {
            if (ans[i] == ans[i+1])
            {
                cnt++;
                p = ans[i];
            }
        }
        printf("Case #%d: ", ++cas);
        if (!cnt) printf("Volunteer cheated!\n");
        else if (cnt == 1) printf("%d\n", p);
        else printf("Bad magician!\n");
    }
    return 0;
}
