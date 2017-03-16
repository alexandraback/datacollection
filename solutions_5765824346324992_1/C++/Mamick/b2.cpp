#include <iostream>
#include <string>
#include <array>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;
long long t, n, b;
long long m[1005];

long long numberServed(long long t) {
    long long served = 0;
    for (int i = 1; i <= b; i++) {
        served += t / m[i] + 1;
    }
    return served;
}

long long findTime(long long min, long long max) {
    while (min <= max) {
        long long mid = (min + max) / 2;
        // cout << mid << " " << numberServed(mid) << " " << min << " " << max << endl;
        if (numberServed(mid) < n && numberServed(mid + 1) >= n) {
            return mid;
        } else if (numberServed(mid) >= n) {
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }
    throw -1;
}

int main() {
    cin >> t;
    for (int test = 1; test <= t; test++) {
        cin >> b >> n;
        priority_queue<pair<long long, long long> > queue;
        for (int i = 1; i <= b; i++) {
            cin >> m[i];
        }
        if (n <= b) {
            cout << "Case #" << test << ": " << n << endl;
            continue;
        }
        long long t = findTime(0, 100000LL * 1000000000LL * 10LL);
        // cout << "time: " << t << endl;
        long long minTime = 9999999999LL;
        for (int i = 1; i <= b; i++) {
            long long t2 = m[i] - (t % m[i]);
            if (t2 == 0) {
                t2 = m[i];
            }
            // cout << t2 << " " << -1 << endl;
            queue.push(make_pair(-1 * t2, -i));
        }
        long long nS = numberServed(t);
        while (nS + 1 < n) {
            queue.pop();
            nS++;
        }
        cout << "Case #" << test << ": " << (-1 * queue.top().second) << endl;
    }
}