#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

long gcd(long a, long b)
{
    long c;

    if (a < b) 
    {
        a += b; b = a - b; a -= b;
    }

    while (b != 0) 
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int lcm(long a, long b)
{
    return a * b / gcd(a, b);
}

int main()
{
    ifstream fin("B-small-attempt2.in");
    ofstream fout("B-small-attempt2.out");

    if (fin.is_open())
    {
        int T;
        fin >> T;

        for (int i = 0; i < T; ++i)
        {
            long B;
            fin >> B;

            long N;
            fin >> N;

            vector<long> requiredTimes;
            map<long, long> endTime;
            for (long j = 0; j < B; ++j)
            {
                int tmp;
                fin >> tmp;
                requiredTimes.push_back(tmp);
                endTime[j] = 0;
            }

            long gcdTime = (B >= 2) ? gcd(requiredTimes[0], requiredTimes[1]) : requiredTimes[0];
            long lcmTime = (B >= 2) ? lcm(requiredTimes[0], requiredTimes[1]) : requiredTimes[0];
            for (long j = 2; j < B; ++j)
            {
                gcdTime = gcd(gcdTime, requiredTimes[j]);
                lcmTime = lcm(lcmTime, requiredTimes[j]);
            }

            long peopleCountInLcmTime = 0;
            for (long j = 0; j < B; ++j)
            {
                peopleCountInLcmTime += (lcmTime / requiredTimes[j]);
            }

            if (N > peopleCountInLcmTime)
            {
                N %= peopleCountInLcmTime;
                if (N == 0)
                {
                    N = peopleCountInLcmTime;
                }
            }

            long ans = 0;
            long customerId = 0;
            long currentTime = 0;
            while (true)
            {
                bool isFound = false;
                for (long j = 0; j < B; ++j)
                {
                    if (currentTime >= endTime[j])
                    {
                        customerId++;
                        endTime[j] = currentTime + requiredTimes[j];

                        if (customerId == N)
                        {
                            ans = j + 1;
                            isFound = true;
                            break;
                        }
                    }
                }

                if (isFound)
                {
                    break;
                }

                currentTime += gcdTime;
            }

            cout << "Case #" << i + 1 << ": " << ans << endl;
            fout << "Case #" << i + 1 << ": " << ans << endl;
        }
    }
}