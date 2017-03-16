#include <iostream>
#include <vector>
#include "../../gcjoutput.h"
#include <limits>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int j = 0; j < n; j++)
            cin >> a[j];
        long long val1 = 0;
        for (int j = 0; j < n - 1; j++)
            if (a[j] > a[j + 1])
                val1 += a[j] - a[j + 1];

        long long val2 = 0;
        int maxDiff = 0;
        for (int j = 0; j < n - 1; j++)
            if (a[j] > a[j + 1])
                if (a[j] - a[j + 1] > maxDiff)
                    maxDiff = a[j] - a[j + 1];
        for (int j = 0; j < n - 1; j++)
            val2 += min(maxDiff, a[j]);

        output << nextCase << val1 << ' ' << val2;
    }
    return 0;
}
