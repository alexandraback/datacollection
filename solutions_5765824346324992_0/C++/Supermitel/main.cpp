#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int t, b, n, m[1010];

long long clienti(long long time)
{
    long long rez = 0;
    for (int i = 0; i < b; i++)
        rez += (time)/(1LL * m[i]) + 1;
    return rez;
}

long long clienti2(long long time)
{
    long long rez = 0;
    for (int i = 0; i < b; i++)
        rez += ceil((1.0*time)/(1LL * m[i]));
    return rez;
}

long long cautBin(long long st, long long dr)
{
    if (st == dr)
        return st;
    else if (st > dr)
    {
        cerr << "WHAT!!";
        return dr;
    }
    long long mid = (st+dr)/2;
    if (clienti(mid) >= n)
        cautBin(st, mid);
    else
        cautBin(mid+1, dr);
}

int solve()
{
    long long tm = 1LL * n * m[0];
    long long timp = cautBin(0, tm);
    long long g = clienti2(timp);
    for (int i = 0; i < b; i++)
        if(timp%(1LL * m[i]) == 0)
        {
            g++;
            if (g == n)
                return i+1;
        }
}

int main()
{
    freopen("barb.in", "r", stdin);
    freopen("barb.out", "w", stdout);

    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d %d", &b, &n);
        for (int j = 0; j < b; j++)
            scanf("%d", &m[j]);
        int y = solve();
        printf("Case #%d: %d\n", i, y);
    }

    return 0;
}
