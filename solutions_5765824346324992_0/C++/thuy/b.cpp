
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Barber
{
    int time;
    int index;

    bool operator < (const Barber& rhs) const
    {
        if (time == rhs.time) return index > rhs.index;
        return time > rhs.time;
    }
};

int gcd(int a, int b)
{
    while (true)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int gcdab = gcd(a, b);
    return gcdab ? (a / gcdab * b) : 0;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int B, N;
        cin >> B >> N;
        priority_queue<Barber> queue;
        vector<int> M;
        int mlcm = 1;
        for (int j = 0; j < B; ++j)
        {
            int mm;
            cin >> mm;
            M.push_back(mm);
            Barber b = {0, j};
            queue.push(b);
            mlcm = lcm(mlcm, mm);
        }

        int roundCustomerCount = 0;
        for (int j = 0; j < B; ++j) {
            roundCustomerCount += mlcm / M[j];
        }

        N = N % roundCustomerCount;
        if (N == 0) {
            N = roundCustomerCount;
        }

        int result = 0;
        while (true) {
            Barber b = queue.top();
            queue.pop();
            N = N - 1;
            if (N == 0) {
                result = b.index + 1;
                break;
            }
            Barber nextB = {b.time + M[b.index], b.index};
            queue.push(nextB);
        }

        cout << "Case #" << i + 1 << ": " << result << endl;
    }
    return 0;
}
