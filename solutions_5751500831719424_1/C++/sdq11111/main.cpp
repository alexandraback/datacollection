#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int INF = 2e9;
int num[1000][1000],tot[1000];
char f[1000][1000],s[1000];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas;
    scanf("%d",&cas);
    for (int t = 1; t <= cas; ++t)
    {
        int n;
        memset(num,0,sizeof(num));
        memset(tot,0,sizeof(tot));
        scanf("%d",&n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s",s);
            char last = s[0];
            tot[i] = 1;
            f[i][tot[i]] = last;
            for (int j = 0; s[j]; ++j)
            {
                if (s[j] == last)
                {
                    num[i][tot[i]]++;
                }
                else
                {
                    num[i][++tot[i]]++;
                    last = s[j];
                    f[i][tot[i]] = last;
                }
            }
        }
        bool can = true;
        for (int i = 2; i <= n; ++i)
        {
            if (tot[i] != tot[1])
            {
                can = false;
                break;
            }
        }
        for (int i = 1; i <= tot[1]; ++i)
        {
            char tmp = f[1][i];
            for (int j = 1; j <= n; ++j)
            {
                if (f[j][i] != tmp)
                {
                    can = false;
                    break;
                }
            }
        }
        printf("Case #%d: ",t);
        if (can)
        {
            int finans = 0;
            for (int i = 1; i <= tot[1]; ++i)
            {
                int ans = INF;
                for (int j = 1; j <= 100; ++j)
                {
                    int temp = 0;
                    for (int k = 1; k <= n; ++k)
                    {
                        temp += abs(num[k][i]-j);
                    }
                    if (temp < ans)
                    {
                        ans = temp;
                    }
                }
                finans += ans;
            }
            printf("%d\n",finans);
        }
        else
        {
            printf("Fegla Won\n");
        }
    }
    return 0;
}
