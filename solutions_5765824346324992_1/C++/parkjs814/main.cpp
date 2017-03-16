#include <iostream>

using namespace std;

int N, B, bx[1000];

long long f() {
    int i;
    long long lastMid;
    long long low = 0;
    long long high = 100000000000000;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long sum = 0;
        for (i = 0; i < B; i++) {
            sum += mid / bx[i];
        }
        if (sum >= N) {
            high = mid - 1;
            lastMid = mid;
        }
        else if (sum < N) {
            low = mid + 1;
        }
    }
    return lastMid;
}

int main() {
    freopen("hair.in", "r", stdin);
    freopen("hair.out", "w", stdout);

    int T, t;
    cin >> T;
    for (t = 0; t < T; t++) {
        cin >> B >> N;
        int i, j;
        for (i = 0; i < B; i++) {
            cin >> bx[i];
        }
        if (N <= B) {
            cout << "Case #" << t + 1 << ": " << N << endl;
            continue;
        }
        N -= B;

        long long num = f();
        long long sum = 0;
        for (i = 0; i < B; i++) {
            sum += num / bx[i];
        }
        int count = 0;
        for (i = B - 1; i >= 0; i--) {
            if (num % bx[i] == 0) {
                if (count == sum - N) break;
                count++;
            }
        }
        cout << "Case #" << t + 1 << ": " << i + 1 << endl;
    }
    return 0;
}