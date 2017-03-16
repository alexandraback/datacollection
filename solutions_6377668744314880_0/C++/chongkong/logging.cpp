#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> point;

int _log[15];
int cache[1 << 15];
int order[15];

long long ccw(point a, point b, point c) {
    b.first -= a.first; b.second -= a.second;
    c.first -= a.first; c.second -= a.second;
    return b.first * (long long)c.second - c.first * (long long)b.second;
}

void convex_hull_init(vector<point> &dat) {
    vector<point> original = dat;
    sort(dat.begin(), dat.end());
    for (int i = 0; i < dat.size(); i++) {
        for (int j = 0; j < dat.size(); j++) {
            if (original[i].first == dat[j].first && original[i].second == dat[j].second)
                order[i] = j;
        }
    }
}

// returns indices that consists convex hull (including edge)
vector<int> convex_hull(vector<point> &dat) {
    if (dat.size() <= 3) {
        vector<int> ret;
        for (int i = 0; i < dat.size(); i++) {
            ret.push_back(i);
        }
        return ret;
    }

    vector<int> upper, lower;
    for (int i = 0; i < dat.size(); i++) {
        while (upper.size() >= 2
            && ccw(dat[*++upper.rbegin()], dat[*upper.rbegin()], dat[i]) > 0)
            upper.pop_back();
        while (lower.size() >= 2
            && ccw(dat[*++lower.rbegin()], dat[*lower.rbegin()], dat[i]) < 0)
            lower.pop_back();
        upper.push_back(i);
        lower.push_back(i);
    }
    upper.insert(upper.end(), ++lower.rbegin(), --lower.rend());
    return upper;
}

void bfs(vector<point>& dat, int n) {
    // bitmap_remaining, bitmap_convex 
    queue<pair<int, int>> q;
    int br = (1 << n) - 1;
    int bc = 0;
    
    auto convex_index = convex_hull(dat);
    for (int index : convex_index) {
        bc |= (1 << index);
        _log[index] = 0;
    }

    q.push(make_pair(br, bc));

    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        int br = top.first, bc = top.second;
        
        if (cache[br] != -1)
            continue;
        cache[br] = 0;

        for (int i = 0; i < n; i++) {
            if (((1 << i) & br) == 0) continue;
            if ((1 << i) & bc) {
                int _br = br ^ (1 << i);
                vector<point> _dat;
                for (int k = 0; k < n; k++) {
                    if ((1 << k) & _br)
                        _dat.push_back(dat[k]);
                }
                auto convex_index = convex_hull(_dat);
                sort(convex_index.begin(), convex_index.end());
                int _bc = 0;
                for (int j = 0, k = 0, t = 0; k < n; k++) {
                    if ((_br & (1 << k)) == 0)
                        continue;
                    else {
                        if (convex_index[j] == t) {
                            _bc |= (1 << k);
                            j++;
                        }
                        t++;
                    }
                }
                for (int k = 0; k < n; k++) {
                    if (!((1 << k) & bc) && ((1 << k) & _bc)) {
                        if (_log[k] == -1) _log[k] = n - __popcnt(_br);
                    }
                }

                q.push(make_pair(_br, _bc));
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        fprintf(stderr, "Case #%d solved\n", tc);
        cout << "Case #" << tc << ":" << endl;

        memset(cache, -1, sizeof cache);
        memset(_log, -1, sizeof _log);

        int n;
        cin >> n;
        vector<point> dat;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            dat.emplace_back(x, y);
        }

        convex_hull_init(dat);
        bfs(dat, n);
        for (int i = 0; i < n; i++) {
            cout << _log[i] << endl;
        }
    }
}