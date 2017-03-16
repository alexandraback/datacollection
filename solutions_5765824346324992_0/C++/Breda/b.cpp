#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int mdc(int a, int b)
{
    int r;
    while(b!=0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int mmc(int a, int b)
{
    return a*b/mdc(a,b);
}

int res()
{
    int n, b, v[1000], i, t, r, rmmc, s;
    priority_queue<pair<int, int> > fila;
    scanf("%d %d", &b, &n);
    scanf("%d", &v[0]);
    rmmc = v[0];
    fila.push(pair<int, int>(0, 0));
    for(i=1;i<b;i++)
    {
        scanf("%d", &v[i]);
        rmmc = mmc(rmmc, v[i]);
        fila.push(pair<int, int>(0, -i));
    }
    s = 0;
    for(i=0;i<b;i++)
        s+=rmmc/v[i];
    n%=s;
    if(n==0)
        n = s;
    for(i=1;i<=n;i++)
    {
        r = -fila.top().second;
        t = -fila.top().first;
        fila.pop();
        fila.push(pair<int, int>(-(t+v[r]), -r));
    }
    return r;
}

int main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1;i<=t;i++)
    {
        int r = res();
        printf("Case #%d: %d\n", i, r+1);
    }
    return 0;
}
