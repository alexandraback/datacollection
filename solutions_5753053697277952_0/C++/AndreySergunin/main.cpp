#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <complex>
#include <ctime>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        cout << "Case #" << t + 1 << ": ";
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sum = n;
        while (sum > 0) {
            int m1 = -1, m2 = -1;
            for (int i = 0; i < n; ++i) {
                if (m1 == -1 || a[i] > a[m1]) {
                    m2 = m1;
                    m1 = i;
                }
                else {
                    if (m2 == - 1 || a[i] > a[m2])
                        m2 = i;
                }
            }

            if (sum > 2) {
                cout << (char)(m1 + 'A') << " ";
                --a[m1];
                if (a[m1] == 0)
                    --sum;
            }
            else {
	            cout << (char)(m1 + 'A') << (char)(m2 + 'A') << " ";
	            --a[m1];
                if (a[m1] == 0)
                    --sum;
	            --a[m2];
                if (a[m2] == 0)
                    --sum;
            }
        }
        cout << endl;

        
    }

    return 0;
}