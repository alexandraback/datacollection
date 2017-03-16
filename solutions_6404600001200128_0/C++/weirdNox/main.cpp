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

int main()
{
    std::ifstream in("in");
    std::ofstream out("out");

    int T;
    in >> T;

    int n;
    for(int caseNum = 1; caseNum <= T; ++caseNum)
    {
        std::cout << "Case #" << caseNum << std::endl;
        out << "Case #" << caseNum << ": ";

        in >> n;
        std::vector<long> snapshots(n);
        for(int i = 0; i < n; ++i)
        {
            in >> snapshots[i];
        }

        long long minFirst = 0;
        long long minSecond = 0;
        long previous = 0;
        for(auto &snap : snapshots)
        {
            if(snap < previous)
            {
                minFirst += (previous - snap);
            }
            previous = snap;
        }

        previous = 0;
        long biggestDiff = 0;
        for(auto &snap : snapshots)
        {
            if(snap < previous)
            {
                biggestDiff = std::max(biggestDiff, previous-snap);
            }
            previous = snap;
        }
        snapshots.pop_back();
        for(auto &snap : snapshots)
        {
            if(snap < biggestDiff)
            {
                minSecond += snap;
            }
            else
            {
                minSecond += biggestDiff;
            }
        }


        out << minFirst << " " << minSecond << '\n';
    }

    return 0;
}


