#include <iostream>
#include <algorithm>
#include <cstdio>
#include <bitset>

using namespace std;

int T;
int la, lb;
char s[20];
bitset<20> a;
bitset<20> b;
bitset<20> rez;

void citire()
{
    int x;
    scanf("%d\n", &la);
    for(int i = 1; i < la; i++) {gets(s);scanf("\n");}
    for(int i = 0; i < 4; i++)
    {
        scanf("%d ", &x);
        a[x] = 1;
    }
    for(int i = la+1; i <= 4; i++) {gets(s);scanf("\n");}
    scanf("%d\n", &lb);
    for(int i = 1; i < lb; i++) {gets(s);scanf("\n");}
    for(int i = 0; i < 4; i++)
    {
        scanf("%d ", &x);
        b[x] = 1;
    }
    for(int i = lb+1; i <= 4; i++) {gets(s);scanf("\n");}
}

void solve()
{
    rez = a & b;
   // cerr<<rez;
    if(rez == 0)
    {
        printf("Volunteer cheated!\n");
        return;
    }
    int sol;
    for(int i = 1; i <= 16; i++)
        if(rez[i])
    {
        rez[i] = 0;
        if(rez == 0)
            printf("%d\n", i);
        else printf("Bad magician!\n");
        return;
    }
}

int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    scanf("%d", &T);
    for(int i = 1; i <= T; i++)
    {
        printf("Case #%d: ", i);
        a = 0;
        b = 0;
        citire();
        solve();
    }
    return 0;
}
