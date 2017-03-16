#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int T, n;
vector<pair<int, int>> p;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> T;
    for (int tc = 0; tc < T; ++tc) {
        cout << "Case #" << tc + 1 << ": ";
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            p.push_back(make_pair(a, i));
        }

        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());

        int head = 0;
        while (p[0].first != 0) {
            if (head < 0) head = 0;
            while (head + 1 < n && p[head].first == p[head + 1].first) ++head;
//            cerr << "<" << head << " " << p[0].first << " " << p[head].first << ">";
            if (head == 0 || head == 2) {
                p[head].first -= 1;
                cout << char('A' + p[head].second) << " ";
                --head;
            }
            else {
                p[head].first -= 1;
                p[head - 1].first -= 1;
                cout << char('A' + p[head].second) << char('A' + p[head - 1].second) << " ";
                head -= 2;
            }
        }
        cout << endl;



        p.clear();
    }
}