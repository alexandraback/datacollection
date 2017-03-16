#include <iostream>
#include <fstream>

using namespace std;

int f1(int r, int c)
{
    int line1 = r / 2 + r % 2;
    int line2 = r / 2;

    int ans = (c / 2) * line1 + (c / 2) * line2 + (c % 2) * line1;
    return ans;
}
int side1(int r, int c, int cnt2)
{
    if (r == 1 || c == 1)
        return r * c - f1(r, c);
    return ((r + c) * 2 - 4) / 2;
}

int solve1(int r, int c, int n)
{
    int cnt0 = f1(r, c), ans = 0;
    cerr << cnt0 << endl;
    if (n > cnt0)
    {
        n -= cnt0;

        int cnt2 = 2;
        if (r % 2 + c % 2 == 2)
            cnt2 = 0;
        if (r == 1 || c == 1)
        {
            cnt2 = r * c - f1(r, c);
            if (r % 2 == 0 || c % 2 == 0)
                ans -= 1;
        }

        cerr << cnt2 << endl;
        if (n < cnt2)
            ans += n * 2;
        else
        {
            n -= cnt2;

            ans += cnt2 * 2;
            int cnt3 = side1(r, c, cnt2) - cnt2;
            cerr << cnt3 << endl;
            if (n <= cnt3)
                ans += n * 3;
            else
            {
                n -= cnt3;

                ans += cnt3 * 3;
                ans += n * 4;
                cerr << n << endl;
            }
        }
    }
    cerr << endl;
    return ans;
}

int f2(int r, int c)
{
    int line1 = r / 2;
    int line2 = r / 2 + r % 2;


    int ans = (c / 2) * line1 + (c / 2) * line2 + (c % 2) * line1;
    return ans;
}

int side2(int r, int c, int cnt2)
{
    if (r == 1 || c == 1)
        return r * c - f2(r, c);
    return ((r + c) * 2 - 4) / 2;
}

int solve2(int r, int c, int n)
{
    int cnt0 = f2(r, c), ans = 0;
    cerr << cnt0 << endl;
    if (n > cnt0)
    {
        n -= cnt0;

        int cnt2 = 2;
        if (r % 2 + c % 2 == 2)
            cnt2 = 4;
        if (r == 1 || c == 1)
        {
            cnt2 = r * c - f2(r, c);
            if (r % 2 == 0 || c % 2 == 0)
                ans -= 1;
        }
        cerr << cnt2 << endl;
        if (n < cnt2)
            ans += n * 2;
        else
        {
            n -= cnt2;

            ans += cnt2 * 2;
            int cnt3 = side2(r, c, cnt2) - cnt2;
            cerr << cnt3 << endl;
            if (n <= cnt3)
                ans += n * 3;
            else
            {
                n -= cnt3;

                ans += cnt3 * 3;
                ans += n * 4;
                cerr << n << endl;
            }
        }
    }
    cerr << endl;
    return ans;
}


int main()
{
    //int f = 2300;
    //rev(f);
    //cout << f;
    freopen("B-large.in", "r", stdin);
    freopen("out1.txt", "w", stdout);
    int t;
    cin >> t;
    for (int j = 1; j <= t; ++j)
    {
        int r, c, n;
        cin >> r >> c >> n;
        cerr << "test" << j << endl;
        cout << "Case #" << j << ": " << min(min(solve1(r,c,n), solve2(r,c,n)), min(solve1(c,r,n), solve2(c,r,n))) << endl;
    }
}
