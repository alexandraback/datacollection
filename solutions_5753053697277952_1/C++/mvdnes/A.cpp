#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void doit() {
    priority_queue<pair<int, char>> q;
    int N;
    cin >> N;
    int total = 0;
    for (int i = 0; i < N; ++i) {
        int m;
        cin >> m;
        q.push(make_pair(m, 'A' + i));
        total += m;
    }

    while (!q.empty()) {
        auto p1 = q.top();
        q.pop();
        if (q.empty()) {
            cerr << "Queue was empty to early..." << endl;
            return;
        }
        auto p2 = q.top();
        q.pop();

        cout << " ";
        cout << p1.second;
        --p1.first;
        total--;

        if (total != 2) {
            if (p1.first > 0 && p1.first >= p2.first) {
                cout << p1.second;
                --p1.first;
            }
            else {
                cout << p2.second;
                --p2.first;
            }
            total--;
        }

        if (p1.first > 0) {
            q.push(p1);
        }
        if (p2.first > 0) {
            q.push(p2);
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ":";
        doit();
    }
    return 0;
}
