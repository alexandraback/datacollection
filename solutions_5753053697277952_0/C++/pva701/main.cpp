#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
typedef long long ll;
void solve() {
    set<pair<int, int> > s;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        s.insert(make_pair(-x, i));
    }
    while (s.size() != 2) {
        pair <int, int> beg = *s.begin();
        s.erase(s.begin());
        printf("%c ", beg.second + 'A');
        ++beg.first;
        if (beg.first != 0)
            s.insert(beg);
    }

    pair <int, int> beg = *s.begin();
    s.erase(s.begin());
    pair <int, int> beg1 = *s.begin();
    for (int i = 0; i < -beg.first; ++i)
        printf("%c%c ", beg.second + 'A', beg1.second + 'A');
    printf("\n");
}

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

