#include <iostream>
#include <stdio.h>
using namespace std;
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        gcd(b, a % b);
}
int main()
{
    freopen("stuff.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, n, b, barb[1000], g, l, p, ans, d;
    cin >> t;
    for(int a = 1; a <= t; a++)
    {
        l = 1;
        d = 0;
        ans = -1;
        fill(barb, barb + 1000, 0);
        cin >> b >> n;
        for(int i = 0; i < b; i++)
            cin >> barb[i];
        for(int i = 0; i < b; i++)
        {
            if(i == 0)
            {
                g = barb[i];
                l = g;
            }
            else
            {
                g = gcd(l, barb[i]);
                if(barb[i] % g == 0)
                    l *= barb[i] / g;
                else
                    l *= barb[i];
            }
        }
        for(int i = 0; i < b; i++)
            d += l / barb[i];
        p = n;
        p %= d;
        if(p == 0)
            ans = b;
        else
        {
            for(int i = 0; i >= 0; i ++)
            {
                for(int j = 0; j < b; j++)
                {
                    if(i % barb[j] == 0)
                        p--;
                    if(p == 0)
                    {
                        ans = j+1;
                        break;
                    }
                }
                if(ans != -1)
                    break;
            }
        }
        cout << "Case #" << a << ": " << ans << "\n";
    }
    return 0;
}
