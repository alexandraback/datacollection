
#include <algorithm>
#include <iostream>

using namespace std;

int n;
int a[1024];

int solve1() {
    int r = 0;
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            r += a[i - 1] - a[i];
    return r;
}

int solve2() {
    int rate = 0;
    for (int i = 1; i < n; i++)
        rate = max(rate, a[i - 1] - a[i]);

    int r = 0;
    for (int i = 0; i + 1 < n; i++)
        r += min(a[i], rate);
    return r;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int y = solve1(), z = solve2();
        cout << "Case #" << t << ": " << y << " " << z << endl;
    }
}
