#include <iostream>
#include <vector>
using namespace std;

long long whenCut(long long b, long long n, const vector<long long>& cost)
{
    long long left = 0, right = 20000000000000000LL, mid;
    long long when = right;
    while (left <= right)
    {
        mid = (left + right) / 2;
        //cout << mid << endl;
        long long can = 0;
        for (int i = 1; i <= b; ++i)
            can += mid / cost[i] + 1;
        if (can >= n)
        {
            when = when < mid ? when : mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return when;
}

long long calculate(long long b, long long n, const vector<long long>& cost)
{
    long long when = whenCut(b, n, cost);
    long long canFinish = 0;
    for (int i = 1; i <= b; ++i)
        canFinish += when / cost[i] + 1;
    for (int i = b; i >= 1; --i)
    {
        if (when % cost[i] == 0)
        {
            //cout << canFinish << " " << n << endl;
            if (canFinish == n) return i;
            --canFinish;
        }
    }
    return -1;
}

int main()
{
    int cases;
    cin >> cases;
    for (int t = 1; t <= cases; ++t)
    {
        long long b, n;
        cin >> b >> n;
        vector<long long> cost;
        cost.resize(b + 1);
        for (int i = 1; i <= b; ++i)
            cin >> cost[i];
        cout << "Case #" << t << ": " << calculate(b, n, cost) << endl;
    }
    return 0;
}
