#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <array>

using namespace std;

map<int, vector<int>> s;
int n;

string c2s(char c)
{
    string s = "A";
    s[0] = c;
    return s;
}

void solve()
{
    s.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s[x].push_back(i);
    }

    int it =0;
    while (!s.empty()) {  
        // for (auto& p: s) {
        //     cout << p.first << ": ";
        //     for (auto& x: p.second) {
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "==" << endl;
        // if (it++ > 10) {
        //     break;
        // } 
        bool npair = false;
        for (auto i = s.rbegin(); i != s.rend(); ++i) {
            auto &p = *i;
            if (p.second.size() % 2 == 1) {
                int a = p.second.back();
                cout << c2s('A' + a) << " ";
                p.second.resize(p.second.size() - 1);
                if (p.first != 1) {
                    s[p.first - 1].push_back(a);
                }
                if (p.second.size() == 0) {
                    s.erase(p.first);
                }
                npair = true;
                break;
            }
        }

        if (npair) {
            continue;
        }

        for (auto &p: s) {
            int a = p.second[0], b = p.second[1];
            cout << c2s('A' + a) << c2s('A' + b) << " ";
            p.second.resize(p.second.size() - 2);
            if (p.first != 1) {
                // cerr << "HERE" << " "  << p.first - 1 << endl;
                s[p.first - 1].push_back(a);
                // cerr << "HERE" << " "  << p.first - 1 << endl;
                s[p.first - 1].push_back(b);
            }
            if (p.second.size() == 0) {
                s.erase(p.first);
            }
            break;
        }
    }

}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        printf("Case #%d: ", i + 1);
        solve();
        cout << endl;
    }
    return 0;
}