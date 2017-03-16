#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;

unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    if (x < y) return gcd(y, x);
    if (x % y == 0) return y;
    return gcd(y, x%y);
}

unsigned long long lcm(unsigned long long x, unsigned long long y)
{
    return (x / gcd(x, y)) * y;
}

int getServer(const vector<int>& M, int N)
{
    int B = M.size();
    unsigned long long period = M[0];
    for (int i = 1; i < B; ++i) {
        period = lcm(period, M[i]);
    }
    int customerPerPeriod = 0;
    for (int i = 0; i < B; ++i) {
        customerPerPeriod += (period / M[i]);
    }
    N %= customerPerPeriod;
    if (N == 0) N = customerPerPeriod;

    vector<int> remain(B, 0);
    int served = 0;
    while (served < N) {
        for (int i = 0; i < B; ++i) {
            if (remain[i] == 0) { // vacant
                ++served;
                remain[i] = M[i];
                if (served == N)
                    return i+1;
            }
        }
        int minremain = INT_MAX;
        for (int i = 0; i < B; ++i) {
            if (remain[i] < minremain)
                minremain = remain[i];
        }
        for (int i = 0; i < B; ++i) {
            remain[i] -= minremain;
        }
    }
}

int main(int argc, char ** argv)
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int B, N;
        cin >> B >> N;
        vector<int> M(B);
        for (int j = 0; j < B; ++j) {
            cin >> M[j];
        }
        cout << "Case #" << i << ": ";
        cout << getServer(M, N) << endl;
    }
    return 0;
}
