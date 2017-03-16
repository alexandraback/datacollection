#include <iostream>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

void cans(int test, int ans)
{
    cout << "Case #" << test << ": " << ans << endl;
}

struct point
{
    int x, y;
};

set < pair <int, pair <int, int> > > s;
map <pair <int, int>, int> m;
int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        s.clear();
        m.clear();
        int r, c, n;
        cin >> r >> c >> n;
        int ans = 2 * r * c - r - c;
        s.insert({2, {1,1}});
        m[{1,1}] = 2;
        m[{r,c}] = 2;
        m[{1,c}] = 2;
        m[{r,1}] = 2;
        s.insert({2, {r,1}});
        s.insert({2, {1,c}});
        s.insert({2, {r,c}});
        for (int i = 2; i < r; i++)
        {
            s.insert({3, {i,1}});
            s.insert({3, {i,c}});
            m[{i,1}] = 3;
            m[{i,c}] = 3;
        }
        for (int i = 2; i < c; i++)
        {
            s.insert({3, {1,i}});
            s.insert({3, {r,i}});
            m[{1,i}] = 3;
            m[{r,i}] = 3;
        }
        for (int i = 2; i < r; i++)
            for (int j = 2; i < c; i++)
            {
                s.insert({4, {i,j}});
                m[{i,j}] = 4;
            }
        int nn = r * c - n;
        while(nn)
        {
            nn--;
            auto it = s.rbegin();
            int cnt = it->first;
            ans -= max(0,cnt);
            int rr = it->second.first;
            int cc = it->second.second;
            s.erase({cnt, {rr, cc}});
            s.erase({m[{rr, cc+1}], {rr, cc+1}});
            s.erase({m[{rr, cc-1}], {rr, cc-1}});
            s.erase({m[{rr+1, cc}], {rr+1, cc}});
            s.erase({m[{rr-1, cc}], {rr-1, cc}});
            if (m.find({rr,cc+1}) != m.end())m[{rr,cc+1}]--;
            if (m.find({rr+1,cc}) != m.end())m[{rr+1,cc}]--;
            if (m.find({rr,cc-1}) != m.end())m[{rr,cc-1}]--;
            if (m.find({rr-1,cc}) != m.end())m[{rr-1,cc}]--;
            if (rr + 1 <= r)s.insert({m[{rr+1,cc}], {rr+1,cc}});
            if (cc + 1 <= c)s.insert({m[{rr,cc+1}], {rr,cc+1}});
            if (rr - 1 >= 1)s.insert({m[{rr - 1,cc}], {rr - 1,cc}});
            if (cc - 1 >= 1)s.insert({m[{rr,cc - 1}], {rr,cc -1}});
        }
        cans (tt, max(0,ans));
        //cans (tt,ans);
    }
    return 0;
}
