#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Party {
    Party(int i, int c) : index(i), count(c) {}
    int index;
    int count;
};

bool operator<(const Party& a, const Party& b) {
    return a.count < b.count;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N; cin >> N;
        vector<int> vec(N, 0); priority_queue<Party> pq;
        for (int n = 0; n < N; ++n) { cin >> vec[n]; pq.push(Party(n, vec[n])); }

        cout << "Case #" << t << ": ";
        while (!pq.empty()) {
            Party p1 = pq.top(); pq.pop();
            Party p2 = pq.top();
            if (p1.count > p2.count) {
                cout << char('A' + p1.index) << char('A' + p1.index) << " ";
                p1.count -= 2; if (p1.count > 0) pq.push(p1);
            }
            else {
                pq.pop();
                if (pq.size() == 1 && p1.count == 1) {
                    --p1.count; cout << char('A' + p1.index) << " "; pq.push(p2);
                }
                else {
                    --p1.count; --p2.count;
                    cout << char('A' + p1.index) << char('A' + p2.index) << " ";
                    if (p1.count > 0) pq.push(p1);
                    if (p1.count > 0) pq.push(p2);
                }
            }
        }

        cout << endl;
    }
    return 0;
}
