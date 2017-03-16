#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define FILE "file"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF = numeric_limits<int>::max();
const ll LLINF = numeric_limits<ll>::max();
const ull ULLINF = numeric_limits<ull>::max();
const double PI = acos(-1.0);

int main()
{
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int tt = 1; tt <= T; tt++)
    {
        int n;
        cin >> n;
        vector<pair<int, char>> p(n);
        for(int i = 0; i < n; i++)
        {
            cin >> p[i].first;
            p[i].second = 'A' + i;
        }
        cout << "Case #" << tt << ": ";
        if(p.size() > 2)
        {
                sort(all(p));
            while(p.back().first != 1)
            {
                sort(all(p));
                int sum = 0;
                for(auto k: p)
                    sum += k.first;
                for(auto k: p)
                {
                    if(k.first * 2 > sum)
                    {
                        cerr << tt << endl;
                        cerr << k.second << " HAS " << k.first << " " << sum << endl;
                        return -1;
                    }
                }

//                        for(auto kk: p)
//                            cerr << kk.first << " " << kk.second << endl;
                p.back().first--;
                cout << p.back().second << " ";
                sort(all(p));
            }
            sort(all(p));
            if(p[0].first != p.back().first)
            {
                cerr << tt << endl;
                cerr << p[0].first << " " <<p.back().first << endl;
            }
            while(p.size() > 2)
            {
                cout << p.back().second << " ";
                p.pop_back();
            }
            cout << p[0].second << p[1].second;
        }
        else
        {
            sort(all(p));
            while(p[0].first != p[1].first)
            {
                p[1].first--;
                cout << p[1].second << " ";
            }
            while(p[0].first)
            {
                p[0].first--;
                cout << p[0].second << p[1].second << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}
