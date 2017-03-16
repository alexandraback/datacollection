#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    vector<char> b(17, true);
    
    int c, t;
    for (int x = 0; x < 2; ++x) {
        cin >> c;
        for (int i = 1; i < 5; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> t;
                if (i != c) b[t] = false;
            }
        }
    }
    
    vector<int> m;
    for (int i = 1; i < b.size(); ++i) if (b[i]) m.push_back(i);
    if (m.size() == 0) cout << "Volunteer cheated!" << endl;
    else if (m.size() > 1) cout << "Bad magician!" << endl;
    else cout << m[0] << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
