#include <iostream>
#include <climits>

using namespace std;

#define SHOW_A(x) {cout << #x << " = " << x << endl;}
#define SHOW_B(x, y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define SHOW_C(x, y, z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}
#define REACH_HERE {cout << "REACH_HERE! line: " << __LINE__ << endl;}

struct Point {
    long long x;
    long long y;

    long long at_right_of(Point& that, Point& base) {
        Point vec_self = {this->x - base.x, this->y - base.y};
        Point vec_that = {that.x - base.x, that.y - base.y};

        long long product = vec_self * vec_that;
        if (product > 0)
            return 1; // "this" is at right of "that"
        if (product == 0)
            return 0; // "this" is at right of "that"
        return -1; // "this" is NOT at right of "that"
    };
    long long operator* (Point& that) {
        return this->x * that.y - this->y * that.x;
    };
};


#define HHH 3002

long long n;
Point p[HHH];

long long get(long long i, long long j) {
    long long left = 0, right = 0;
    for (long long k = 0; k < n; k++) {
        if (k == j || k == i)
            continue;

        int temp = p[k].at_right_of(p[j], p[i]);
        if (temp == 1)
            right++;
        if (temp == -1)
            left++;
        // SHOW_C(temp, left, right);
    }
    return min(left, right);
}

void sol() {
    if (n < 4) {
        for (long long i = 0; i < n; i++)
            cout << 0 << endl;
        return ;
    }
    for (long long i = 0; i < n; i++) {
        long long ans = INT_MAX;
        // SHOW_A(i);
        for (long long j = 0; j < n; j++) {
            if (i == j)
                continue;
            // SHOW_B(i, j);
            long long tempAns = get(i, j);
            ans = min(ans, tempAns);
        }
        cout << ans << endl;
    }
}

int main() {
    long long test;
    cin >> test;
    for (long long t = 1; t <= test; t++) {
        cin >> n;
        for (long long i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;
        
        cout << "Case #" << t << ":" << endl;
        sol();
    }
}