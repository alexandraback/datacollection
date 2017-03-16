#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

int cnt[28];
struct cmp{
    bool operator(int a, int b) {
        return cnt[a] < cnt[b];
    }
};

int main()
{
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        int n;
        cin >> n;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            cin >> cnt[i];
            count += cnt[i];
        }

        priority_queue<int, vector<int>, cmp> pq;
        for (int i = 0; i < n; ++i) {
            pq.insert(i);
        }

        string ans = "";
        while (count) {
            int now = pq.top();
            ans += (now + 'A');
i
        }

        cout << "Case #" << k << ": " << ans << endl;
    }

    return 0;
}
