#include <iostream>
#include <vector>
#include <limits>
#include "../../gcjoutput.h"

using namespace std;

long long calc(long long t, const vector <int> &a) {
    long long res = 0;
    for (int i = 0; i < a.size(); i++)
        res += t / a[i] + (t % a[i] != 0);
    return res;
}

long long bin_search(const vector<int> &a, long long n) {
    long long l = 0, r = 10L * 100000L * 1000000000000L;
    while (l < r - 1) {
        long long m = (r + l) / 2;
        long long num = calc(m, a);
        if (num < n)
            l = m;
        else
            r = m;
    }
    return r;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        int s;
        cin >> n >> s;
        vector <int> a(n);
        for (int j = 0; j < n; j++)
            cin >> a[j];

        long long T = bin_search(a, s);
        long long l = calc(T - 1, a);
        long long minT = numeric_limits<long long>::max();
        int minInd = 0;
        for (int j = 0; j < n; j++) {
            if ((T - 1) % a[j] == 0)
                if (l < s) {
                    minInd = j;
                    l++;
                }
        }

        output << nextCase << minInd + 1;

    }
    return 0;
}
