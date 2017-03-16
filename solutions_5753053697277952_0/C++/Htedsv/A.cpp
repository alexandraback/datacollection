#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool cmp(const pair<int,int> & x, const pair<int,int> & y)
{
    return x.second > y.second;
}
int n;
void move_down(vector<pair<int, int> > &a,  int p)
{
    while (true)
    {
        int r = (p + 1) * 2, l = (p + 1) * 2 - 1;
        if (l >= n)
            break;
        if (r < n && a[r].second > a[l].second)
        {
            l = r;
        }
        if (a[l].second > a[p].second)
        {
            pair<int, int> tmp = a[p]; a[p] = a[l]; a[l] = tmp;
            p = l;
        }
        else
            break;
    }
    return ;
}
int main()
{
    int T, x;
    cin >> T;
    for (int I = 1; I <= T; ++I)
    {
        cout << "Case #" << I << ":";
        cin >> n;
        vector<pair<int, int> > a(n);
        int sums = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            sums += x;
            a[i] = make_pair(i, x);
        }
        sort(a.begin(), a.end(), cmp);
        while (sums > 0)
        {
            if (a[0].second > max(a[1].second, a[2].second)+1)
            {
                a[0].second -= 2;
                sums -=2;
                cout << " " << char('A'+a[0].first) << char('A'+a[0].first);
                move_down(a, 0);
            }
            else if (a[0].second > max(a[1].second, a[2].second))
            {
                a[0].second -= 1;
                sums--;
                cout << " " << char('A'+a[0].first);
            }
            else if (sums % 2 == 0)
            {
                cout << " " << char('A'+a[0].first);
                a[0].second -= 1;
                sums--;
                move_down(a, 0);
                cout << char('A'+a[0].first);
                a[0].second -= 1;
                sums--;
                move_down(a, 0);
            }
            else
            {
                cout << " " << char('A'+a[0].first);
                a[0].second -= 1;
                sums--;
                move_down(a, 0);
            }
        }
        cout << endl;
        
    }
}
