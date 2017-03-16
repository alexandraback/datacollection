#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int num1[1000],num2[1000];
char f1[1000],f2[1000],s1[1000],s2[1000];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas;
    scanf("%d",&cas);
    for (int t = 1; t <= cas; ++t)
    {
        int n;
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        scanf("%d",&n);
        scanf("%s",s1);
        scanf("%s",s2);
        int l1 = strlen(s1), l2 = strlen(s2), t1 = 0, t2 = 0;
        char last = s1[0];
        num1[t1]++;
        f1[t1] = last;
        for (int i = 1; i <l1; ++i)
        {
            if (s1[i] == last)
            {
                num1[t1]++;
            }
            else
            {
                num1[++t1]++;
                last = s1[i];
                f1[t1] = last;
            }
        }
        last = s2[0];
        num2[t2]++;
        f2[t2] = last;
        for (int i = 1; i < l2; ++i)
        {
            if (s2[i] == last)
            {
                num2[t2]++;
            }
            else
            {
                num2[++t2]++;
                last = s2[i];
                f2[t2] = last;
            }
        }
        bool can = true;
        int ans = 0;
        if (t1 != t2) can = false;
        else for (int i = 0; i <= t1; ++i)
        {
            if (f1[i] != f2[i])
            {
                can = false;
                break;
            }
            else
            {
                ans += abs(num1[i]-num2[i]);
            }
        }
        printf("Case #%d: ",t);
        if (can) printf("%d\n",ans);
        else printf("Fegla Won\n");
    }
    return 0;
}
