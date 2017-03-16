#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>

using namespace std;

int solve(int r, int c, int n)
{
    int total = r * c;
    if (n <= (total + 1) / 2)
        return 0;
    int unhappiness = r * (c - 1) + c * (r - 1);
    int less = total - n;
    if (r == 1)
    {
        return unhappiness - 2 * less;
    }
    if (total % 2 == 0)
    {
        int t4 = (r - 2) * (c - 2) / 2;
        int t3 = (r - 2) + (c - 2);
        int t2 = 2;
        if (less > 0)
        {
            int toremove = min(less, t4);
            unhappiness -= toremove * 4;
            less -= toremove;
        }
        if (less > 0)
        {
            int toremove = min(less, t3);
            unhappiness -= toremove * 3;
            less -= toremove;
        }
        if (less > 0)
        {
            int toremove = min(less, t2);
            unhappiness -= toremove * 2;
            less -= toremove;
        }
        return unhappiness;
    }

    int cand1 = unhappiness;
    {
        int t4 = ((r - 2) * (c - 2) + 1) / 2;
        int t3 = r + c - 6;
        int t2 = 4;
        if (less > 0)
        {
            int toremove = min(less, t4);
            cand1 -= toremove * 4;
            less -= toremove;
        }
        if (less > 0)
        {
            int toremove = min(less, t3);
            cand1 -= toremove * 3;
            less -= toremove;
        }
        if (less > 0)
        {
            int toremove = min(less, t2);
            cand1 -= toremove * 2;
            less -= toremove;
        }
    }
    int cand2 = unhappiness;
    less = total - n;
    {
        int t4 = ((r - 2) * (c - 2) - 1) / 2;
        int t3 = r + c - 2;
        if (less > 0)
        {
            int toremove = min(less, t4);
            cand2 -= toremove * 4;
            less -= toremove;
        }
        if (less > 0)
        {
            int toremove = min(less, t3);
            cand2 -= toremove * 3;
            less -= toremove;
        }
    }
    return min(cand1, cand2);
}

int main()
{
    int t, test;
    scanf("%d", &test);
    for (t = 0; t < test; t++)
    {
        int r, c, n;
        scanf("%d %d %d", &r, &c, &n);
        if (r > c)
        {
            int temp = r;
            r = c;
            c = temp;
        }

        printf("Case #%d: %d\n", t+1, solve(r, c, n));
    }
    return 0;
}
