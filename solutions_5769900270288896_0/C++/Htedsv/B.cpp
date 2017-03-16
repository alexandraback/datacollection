#include <iostream>
using namespace std;
int un, r,c, n, MAX, best, ans;
bool f[103][103];
void deep(int x, int y, int n)
{
    if (n == 0)
    {
        if (ans < best)
        {
            best  = ans;
        }
        return;
    }
    if (ans > best)
        return;
    if (x == r+1 )
        return;
    int tx = x, ty = y+1;

    if (ty > c)
    {
        tx = x + 1;
        ty = 1;
    }

    f[x][y] = true;
    if (x > 0 && f[x-1][y]) 
        ans++;
    if (y > 0 && f[x][y-1])
        ans++;
    deep(tx, ty, n-1);
    if (x > 0 && f[x-1][y]) 
        ans--;
    if (y > 0 && f[x][y-1])
        ans--;
    f[x][y] = false;

    deep(tx, ty, n);
}

    
int main()
{
    int T;
    scanf("%d", &T);
    for (int I = 1; I <= T; ++I)
    {
        memset(f, 0, sizeof(f));
        scanf("%d%d%d", &r, &c, &n);
        MAX = r*c;
        best = MAX * MAX; ans = 0;
        deep(1, 1, n);
        printf("Case #%d: %d\n",I, best);
    }
}

