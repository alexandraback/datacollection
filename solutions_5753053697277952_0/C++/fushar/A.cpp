#include <bits/stdc++.h>
using namespace std;

int T;
int N;

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        priority_queue<pair<int, char>> pq;

        cout << "Case #" << tc << ":";
        cin >> N;
        for (int i = 0; i < N; i++) {
            int p;
            cin >> p;
            pq.emplace(p, 'A' + i);
        }

        while (!pq.empty()) {
            cout << " ";
            pair<int, char> u = pq.top();
            pq.pop();

            cout << u.second;

            if (!pq.empty()) {
                pair<int, char> v = pq.top();
                pq.pop();
                if (u.first == v.first && pq.empty()) {
                    cout << v.second;
                    if (v.first > 1) {
                        pq.emplace(v.first - 1, v.second);
                    }
                } else {
                    pq.push(v);
                }
            }

            if (u.first > 1) {
                pq.emplace(u.first - 1, u.second);
            }
        }

        cout << endl;
    }
}
