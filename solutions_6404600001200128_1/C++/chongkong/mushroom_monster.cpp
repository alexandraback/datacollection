#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int plate[1000];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n;
        int total_eaten = 0, max_eaten = 0, const_eaten = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> plate[i];

        for (int i = 1; i < n; i++) {
            if (plate[i-1] > plate[i]) {
                int eaten = plate[i-1] - plate[i];
                total_eaten += eaten;
                max_eaten = max_eaten > eaten ? max_eaten : eaten;
            }
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (plate[i] > max_eaten) {
                const_eaten += max_eaten;
            }
            else {
                const_eaten += plate[i];
            }
        }

        cout << "Case #" << tc << ": " << total_eaten << " " << const_eaten << endl;
    }
}