#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

#include <iostream>
#include <numeric>

long long gcd(long long a, long long b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

long long lcm(long long a, long long b)
{
    long long temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

long long lcm_all(vector<int> M)
{
    return std::accumulate(M.begin(), M.end(), 1, lcm);
}

int solve(vector<int> M, int N) {
    vector<int> turn(M.size(), 0);

    for (int i = 0; i < N-1; ++i) {
        int min_idx = 0;
        for (int j = 0; j < turn.size(); ++j) {
            if (turn[min_idx] > turn[j])
                min_idx = j;
        }
        turn[min_idx] += M[min_idx];
    }

    int min_idx = 0;
    for (int j = 0; j < turn.size(); ++j) {
        if (turn[min_idx] > turn[j])
            min_idx = j;
    }

    return min_idx+1;
}

int main() {
    int T;
    cin >> T;

    for (int test=1; test <= T; ++test) {
        int B, N;
        cin >> B >> N;
        vector<int> M(B, 0);
        for (int i=0; i < B; ++i)
            cin >> M[i];

        long long l = lcm_all(M);

        long long turn = 0;
        for (int i = 0; i < M.size(); ++i)
            turn += l / M[i];

        N %= turn;
        if (N==0)
            N = turn;

        printf("Case #%d: %d\n", test, solve(M, N));
    }
    return 0;
}
