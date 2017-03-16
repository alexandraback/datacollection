#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int n;
int a[1010];
int interv;

void citire()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    interv = 0;
}

void solve1()
{
    int total = 0, crt;
    for(int i = 1; i < n; i++)
        if(a[i] < a[i-1])
        {
            interv = max(a[i-1] - a[i],  interv);
            total += a[i-1] - a[i];
        }

    printf("%d ", total);
}

void solve2()
{
    int total = 0;
    for(int i = 0; i < n-1; i++)
        total += min(a[i], interv);
    printf("%d\n", total);
}

int main()
{
    freopen("mush.in", "r", stdin);
    freopen("mush.out", "w", stdout);

    int t;
    scanf("%d\n", &t);
    for(int i = 0; i < t; i++)
    {
        citire();
        printf("Case #%d: ", i+1);
        solve1();
        solve2();
    }
    return 0;
}
