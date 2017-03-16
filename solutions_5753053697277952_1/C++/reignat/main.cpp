#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <set>
#include <map>

typedef long long int ll;

using namespace std;

int a[30];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        int p = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            p += a[i];
        }
        set<pair<int, int>, greater<pair<int, int> > > s;
        for (int i = 0; i < n; ++i)
            s.insert(make_pair(a[i], i));
        vector<int> ans;
        while (p > 0) {
            if (p != 3) {
                int num1 = s.begin()->first;
                int par1 = s.begin()->second;
                s.erase(s.begin());
                s.insert(make_pair(num1 - 1, par1));
                int num2 = s.begin()->first;
                int par2 = s.begin()->second;
                s.erase(s.begin());
                s.insert(make_pair(num2 - 1, par2));
                ans.push_back(par1);
                ans.push_back(par2);
                p -= 2;
            } else {
                int num1 = s.begin()->first;
                int par1 = s.begin()->second;
                s.erase(s.begin());
                s.insert(make_pair(num1 - 1, par1));
                p -= 1;
                ans.push_back(par1);
            }
        }
        reverse(ans.begin(), ans.end());
        cout << "Case #" << t << ": ";
        while (ans.size() > 0) {
            if (ans.size() != 3) {
                int par1 = ans.back();
                ans.pop_back();
                int par2 = ans.back();
                ans.pop_back();
                cout << char('A' + par1) << char('A' + par2);
                if (ans.size() > 0)
                    cout << ' ';
                else
                    cout << '\n';
            } else {
                cout << char('A' + ans.back()) << " ";
                ans.pop_back();
            }
        }
    }
    return 0;
}