#include <cstdio>
#include <cmath>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

#define ll long long

#define TESTING 0
#define TESTING2 0

struct Node {
    int barber;
    ll count;
    ll time;
};

class comp {
public:
    bool operator() (const Node & a, const Node & b) {
        if (a.time == b.time) return a.barber > b.barber;
        return a.time > b.time;
    }
};

#define pqn priority_queue<Node, vector<Node>, comp>

ll m[1024];

void solve(int kase) {
    int result = 0;
    int b, n;
    scanf("%d %d", &b, &n);

    ll max_M = 0;

    for (int i = 0; i < b; ++i) {
        ll curr;
        scanf("%lld", &curr);
        m[i] = curr;
        if (curr > max_M) max_M = curr;
    }

    if (n <= b) {
        result = n;
    } else if (b == 1) {
        result = 1;
    } else {
        // estimate of time = n * max_M
        // binary search from there to get correct time
        ll estimate = (n * max_M) << 1;
#if TESTING
        printf("\testimate %lld\n", estimate);
#endif
        // binary search from there to get correct time
        ll max = estimate;
        ll min = 0;
        ll mid;
        --n;
        while (max-1 > min) {
            mid = (max + min) >> 1;
#if TESTING
            printf("\tmid %lld\n", mid);
#endif
            // check
            ll total_done = 0;
            for (int i = 0; i < b; ++i) {
                total_done += (mid / m[i]);
            }

            if (total_done <= n) {
                min = mid;
            } else {
                max = mid;
            }
        }

        // subtract max from mind

        min = mid - max_M;

        if (min < 0LL) min = 0LL;

        // simulate from here
        pqn pq;
        ll total_cut = 0;

        for (int i = 0; i < b; ++i) {
            // for current barber, how many has he cut
            ll cut = (min / m[i]);
            ll time_taken = cut * m[i];
            total_cut += cut;
            Node curr;
            curr.barber = i;
            curr.count = cut;
            curr.time = time_taken;
            pq.push(curr);
#if TESTING
            printf("cut %lld\n", cut);
#endif
        }

#if TESTING
        printf("total_cut %lld n %lld\n", total_cut, n);
#endif

        while (total_cut < n) {
            Node curr = pq.top();
            pq.pop();
            ++curr.count;
            curr.time += m[curr.barber];
            pq.push(curr);
            ++total_cut;
        }

        result = pq.top().barber+1;
/*




        // adjust to lower bound
        ll max_lower = 0;
        for (int i = 0; i < b; ++i) {
            ll bottom = (mid / m[i]) * m[i];
            if (!(mid % m[i])) bottom -= m[i];
#if TESTING
            printf("\t\tbottom: %lld\n", bottom);
#endif
            if (bottom > max_lower) max_lower = bottom;
        }

        ll total = max_lower;

#if TESTING
            printf("\ttotal %lld\n", total);
#endif
        ll actual_done = 0;
        for (int i = 0; i < b; ++i) {
            actual_done += (total / m[i]);
        }

        ll to_do = n - actual_done;

#if TESTING
            printf("\tto_do %lld\n", to_do);
#endif
        if (to_do < 0) {
            // find min barber
            ll min_time = 1LL<<35;
            int min_index = -1;
            for (int i = 0; i < b; ++i) {
                if (m[i] < min_time) {
                    min_time = m[i];
                    min_index = i;
                }
            }
            result = min_index + 1;
#if TESTING2
            printf("here todo lower than 0 %d\n", result);
#endif
        } else {
            for (int i = 0; i < b;) {
                if ((total % m[i]) == 0) {
                    if (to_do) {
                        --to_do;
                    } else {
                        result = i+1;
                        break;
                    }
                }
                ++i;
                i %= b;
            }
        }
*/
    }

    printf("Case #%d: %d\n", kase, result);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}
