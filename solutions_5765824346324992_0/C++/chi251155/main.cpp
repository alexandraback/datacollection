#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <map>
#include <list>
#include <algorithm>
#include <utility>
#include <numeric>

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        int B, N;
        cin >> B >> N;
        vector<int> Ms;
        Ms.reserve(B);
        for(int i = 0; i < B; ++i)
        {
            int M;
            cin >> M;
            Ms.push_back(M);
        }
        int lcmM = accumulate(Ms.begin(), Ms.end(), 1, lcm);
        int turns = 0;
        for(int i = 0; i < B; ++i)
        {
            turns += lcmM / Ms[i];
        }
        N %= turns;
        if(N == 0) N = turns;
        vector<int> Bs(B, 0);
        int cutb = -1;
        for(int n = 1; n <= N; ++n)
        {
            bool seated = false;
            int min = INT_MAX;
            for(int b = 0; b < B; ++b)
            {
                if(Bs[b] == 0)
                {
                    Bs[b] = Ms[b];
                    cutb = b;
                    seated = true;
                    break;
                }
                else if(Bs[b] < min)
                {
                    min = Bs[b];
                }
            }
            if(seated)
            {
                continue;
            }
            for(int b = 0; b < B; ++b)
            {
                Bs[b] -= min;
            }
            for(int b = 0; b < B; ++b)
            {
                if(Bs[b] == 0)
                {
                    Bs[b] = Ms[b];
                    cutb = b;
                    break;
                }
            }
        }
        cout << "Case #" << t << ": " << cutb + 1 << endl;
    }
    return 0;
}
