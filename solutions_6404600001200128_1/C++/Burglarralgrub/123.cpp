#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#define MAXN 1005
using namespace std;
int n;
int star[MAXN];
int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("Aout.out", "w", stdout);
    int t;
    int numCase = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &star[i]);
        int ans1 = 0;
        int ans2 = 0;
        int temp = 0;
        for(int i = 0; i < n - 1; i++)
        {
            //printf("%d\n", star[i]);
            if(star[i] > star[i + 1])
            {
                ans1 += (star[i] - star[i + 1]);
            }
            else
                ans1 += 0;
        }
        for(int i = 0; i < n - 1; i++)
        {
            if(star[i] > star[i + 1])
            {
                temp = max(temp, star[i] - star[i + 1]);
            }
        }
        for(int i = 0; i < n - 1; i++)
        {
            if(star[i] >= temp) ans2 += temp;
            else
                ans2 += star[i];
        }
        printf("Case #%d: %d %d\n", numCase++, ans1, ans2);
    }
    return 0;
}
