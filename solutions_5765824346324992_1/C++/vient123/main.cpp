#include <bits/stdc++.h>

using namespace std;

struct my
{
    int num;
    long long time;
    my() {}
    my(int num, long long time) : num(num), time(time) {}
    friend bool operator <(const my & a, const my & b)
    {
        return a.time != b.time ? a.time > b.time : a.num > b.num;
    }
};

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int TESTS;
    cin >> TESTS;
    for (int TEST = 1; TEST <= TESTS; TEST++)
    {
        cout << "Case #" << TEST << ": ";
        int b, n;
        cin >> b >> n;
        vector<long long> V(b);
        for (auto & x : V)
            cin >> x;
        long long L = -1, R = 1e14 + 2;
        while (R - L - 1)
        {
            auto M = (L + R) / 2;
            unsigned long long num = b;
            for (auto x : V)
                num += M / x;
            if (num < n)
                L = M;
            else
                R = M;
        }
        for (int i = 0; i < b; i++)
            n -= L / V[i];
        n -= b;
        for (int i = 0; i < b; i++)
            if (R % V[i] == 0)
            {
                if (n == 1)
                {
                    cout << i + 1 << '\n';
                    break;
                }
                else
                    --n;
            }
    }
}
