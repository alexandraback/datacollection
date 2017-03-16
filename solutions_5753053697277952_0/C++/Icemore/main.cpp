#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define forv(i, a) forn(i, (int)(a).size())

typedef long long lng;


vector<pair<int, int>> solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> ans;
    priority_queue<pair<int, int>> q;

    forn(i, n)
    {
        int p;
        cin >> p;

        q.push(make_pair(p, i));
    }

    while(q.size() != 2)
    {
        auto cur = q.top();
        q.pop();

        ans.push_back(make_pair(cur.second, -1));

        cur.first--;
        if(cur.first != 0)
            q.push(cur);
    }

    vector<pair<int, int>> left;
    left.push_back(q.top());
    q.pop();
    left.push_back(q.top());
    q.pop();

    while(left[0].first > left[1].first)
    {
        ans.push_back(make_pair(left[0].second, -1));
        left[0].first--;
    }

    forn(i, left[0].first)
    {
        ans.push_back(make_pair(left[0].second, left[1].second));
    }

    return ans;
}

char to_char(int val)
{
    return 'A'+val;
}

void print(vector<pair<int, int>>& ans)
{
    for(auto& cur : ans)
    {
        cout << to_char(cur.first);
        if(cur.second != -1)
            cout << to_char(cur.second);
        cout << " ";
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    int T;
    cin >> T;
    forn(tc, T) {
        auto ans = solve();

        std::cout << "Case #" << tc + 1 << ": ";
        print(ans);
        std::cout << endl;
    }
    
    return 0;
}
