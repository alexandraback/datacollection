#include <iostream>

using namespace std;

int t;
int n;
int m[1111];

void solve(int x) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> m[i];
    int a = 0;
    for (int i = 1; i < n; i++) {
        if (m[i] < m[i-1]) a += (m[i-1]-m[i]);
    }
    int b = 0, u = 0;
    for (int i = 1; i < n; i++) {
        if (m[i] < m[i-1]) u = max(u, m[i-1]-m[i]);
    }
    for (int i = 0; i < n-1; i++) {
        b += min(m[i], u);
    }
    cout << "Case #" << x << ": " << a << " " << b << "\n";
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
