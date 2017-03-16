// gcj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

long long GetCount(vector<long long> const & b, long long time)
{
    long long count = 0;
    for (int i = 0; i < b.size(); ++i)
        count += time / b[i] + 1;
    return count;
}

bool CanDoInTime(vector<long long> const & b, long long N, long long time)
{
    long long count = GetCount(b, time);

    return count >= N;
}

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream ifstr("B-large.in");
    ofstream ofstr("B-large.out");

    int T;
    ifstr >> T;
    for (int t = 0; t < T; ++t)
    {
        long long B, N;
        ifstr >> B >> N;
        vector<long long> b(B);
        for (int i = 0; i < B; ++i)
            ifstr >> b[i];

        long long l = 0;
        long long r = *max_element(b.begin(), b.end()) * N;
        while (l != r)
        {
            long long time = (l + r) / 2;
            if (CanDoInTime(b, N, time))
                r = time;
            else
                l = time + 1;
        }

        long long prevCount = l > 0 ? GetCount(b, l - 1) : 0LL;

        int res = 1;
        for (int i = 0; i < b.size(); ++i)
        {
            if (l % b[i] == 0 && ++prevCount == N)
            {
                res = i + 1;
                break;
            }
        }

        ofstr << "Case #" << t + 1 << ": " << res << endl;
    }

    return 0;
}
