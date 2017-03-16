#include <iostream>

using namespace std;

#define HHH 1002

int n;
int a[HHH];

void sol1() {
    int total = 0;
    for (int i = 0; i < n - 1; i++)
        total += max(0, a[i] - a[i + 1]);
    cout << total << " ";
}

void sol2() {
    int maxDrop = 0;
    for (int i = 0; i < n - 1; i++)
        maxDrop = max(maxDrop, a[i] - a[i + 1]);

    int total = 0;
    for (int i = 0; i < n - 1; i++) {
        total += min(maxDrop, a[i]);
    }
    cout << total << endl;
}

int main() {
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << "Case #" << c << ": ";
        sol1();
        sol2();
    }
}