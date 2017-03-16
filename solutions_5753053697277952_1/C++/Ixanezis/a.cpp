#include <iostream>
#include <set>
#include <functional>

using namespace std;

void solve(int test) {
    cout << "Case #" << test << ":";

    set<pair<int, char>, greater<pair<int, char>>> s;
    int n; cin >> n;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        s.emplace(a, char(i + 'A'));
    }

    while (s.size() > 2) {
        pair<int, char> p = *s.begin();
        s.erase(s.begin());
        cout << ' ' << p.second;
        --p.first;
        if (p.first)
            s.insert(p);
    }

    pair<int, char> p1 = *s.begin();
    s.erase(s.begin());
    pair<int, char> p2 = *s.begin();

    while (p1.first) {
        if (p1.first != p2.first)
            throw runtime_error("Does not match");
        cout << ' ' << p1.second << p2.second;
        --p1.first;
        --p2.first;
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    for (int e=1; e<=t; ++e)
        solve(e);
}
