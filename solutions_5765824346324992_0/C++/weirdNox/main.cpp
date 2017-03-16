#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

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
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main()
{
    std::ifstream in("in");
    std::ofstream out("out");

    int T;
    in >> T;

    long long b, n;
    for(int caseNum = 1; caseNum <= T; ++caseNum)
    {
        std::cout << "Case #" << caseNum << std::endl;
        out << "Case #" << caseNum << ": ";

        in >> b >> n;

        std::vector<long> time(b);
        for(int i = 0; i < b; ++i)
        {
            in >> time[i];
        }

        long long currentCustomer = 1;
        std::vector<long> timeLeft(b);
        long long leastCm = std::accumulate(time.begin(), time.end(), 1, lcm);
        long long modulo = 0;
        for(auto &tempTime : time)
        {
            modulo += leastCm / tempTime;
        }
        n = n % modulo;
        if(n == 0) n += modulo;
        while(currentCustomer != n)
        {
            auto nextBarber = std::find(timeLeft.begin(), timeLeft.end(), 0);
            if(nextBarber != timeLeft.end())
            {
                (*nextBarber) = time[std::distance(timeLeft.begin(), nextBarber)];
            }
            else
            {
                long lowestTime = std::numeric_limits<long>::max();
                for(auto &time : timeLeft)
                {
                    lowestTime = std::min(lowestTime, time);
                }

                for(auto &time : timeLeft)
                {
                    time -= lowestTime;
                }

                auto nextBarber = std::find(timeLeft.begin(), timeLeft.end(), 0);
                if(nextBarber != timeLeft.end())
                {
                    (*nextBarber) = time[std::distance(timeLeft.begin(), nextBarber)];
                }
                else
                {
                    throw 1;
                }
            }

            ++currentCustomer;
        }

        int myBarber = 0;
        auto nextBarber = std::find(timeLeft.begin(), timeLeft.end(), 0);
        if(nextBarber != timeLeft.end())
        {
            myBarber = std::distance(timeLeft.begin(), nextBarber) + 1;
        }
        else
        {
            long lowestTime = std::numeric_limits<long>::max();
            for(auto &time : timeLeft)
            {
                lowestTime = std::min(lowestTime, time);
            }

            for(auto &time : timeLeft)
            {
                time -= lowestTime;
            }

            auto nextBarber = std::find(timeLeft.begin(), timeLeft.end(), 0);
            if(nextBarber != timeLeft.end())
            {
                myBarber = std::distance(timeLeft.begin(), nextBarber) + 1;
            }
            else
            {
                throw 1;
            }
        }


        out << myBarber << '\n';
    }

    return 0;
}


