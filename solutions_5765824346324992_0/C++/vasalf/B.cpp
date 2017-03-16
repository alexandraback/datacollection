#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

long long answer(long long tm, vector<long long>& m)
{
    long long res = 0;
    for (long long barb : m)
        res += (tm + barb) / barb;
    return res;
}

int solve(int n, int b, vector<long long> m)
{
    long long lt = -1, rt = 1e18;
    while (lt < rt - 1)
    {
        long long mid = (lt + rt) / 2;
        if (answer(mid, m) < n)
            lt = mid;
        else
            rt = mid;
    }
    //Now rt is time
    long long num_to_skip = n - 1 - answer(lt, m);
//    cout << rt << " " << answer(lt, m) << " " << num_to_skip << endl;
    for (int i = 0; i < b; i++)
    {
        if (rt % m[i] == 0)
        {
            if (num_to_skip == 0)
                return i + 1;
            num_to_skip--;
        }
    }
    assert(false);
    return -1;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int b, n;
        cin >> b >> n;
        vector<long long> m(b);
        for (int j = 0; j < b; j++)
            cin >> m[j];
        cout << "Case #" << i + 1 << ": " << solve(n, b, m) << endl; 
    }
    return 0;
}
