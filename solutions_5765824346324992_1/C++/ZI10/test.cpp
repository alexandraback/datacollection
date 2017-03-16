#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
    int T;
    cin >> T;
    for (int z = 0; z < T; ++z)
    {
        long long MAX = 100000;
        long long B, N;
        cin >> B >> N;
        vector <long long> A(B);
        for (int i = 0; i < B; ++i)
        {
            cin >> A[i];
        }
        long long l = 0;
        long long r = N * MAX;
        while (r - l > 1)
        {
            long long m = (l + r) / 2;
            long long sum = 0;
            for (int i = 0; i < B; ++i)
            {
                sum += m / A[i] + 1;
            }
            if (sum >= N)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
       // cout << r << endl;

        long long q = N;
        long long Ans = 0;
        for (int i = 0; i < B; ++i)
        {
            q -= (r - 1) / A[i] + 1;
        }
       // cout << "Q" << q << endl;
        for (int i = 0; i < B; ++i)
        {
            if (r % A[i] == 0)
            {
                --q;
            }
            if (q == 0)
            {
                Ans = i + 1;
                break;
            }
        }
        if (N <= B)
        {
            Ans = N;
        }
        cout << "Case #" << z + 1 << ": " << Ans << endl;
    }
    return 0;
}
