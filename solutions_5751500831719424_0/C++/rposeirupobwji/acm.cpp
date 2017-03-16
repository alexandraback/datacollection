#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iterator>
#include <ctime>

typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;

using namespace std;

#define ALL(a) a.begin(), a.end()
#define FOR(a) for (int i = 0; i < a; ++i)
#define mp(a, b) make_pair(a, b)
#define D(a) #a << ": " << a << "\n"

int main()
{
    int CASES;
    cin >> CASES;
    for (int CASE = 1; CASE <= CASES; ++CASE)
    {
        int n;
        cin >> n;
        vector<string> v;
        v.resize(n);
        FOR(n) cin >> v[i];

        int res = 0;

        while (1)
        {
            char choosen = 0;
            vector<int> cnts;
            cnts.clear();
            cnts.resize(n);

            for (int strC = 0; strC < v.size(); ++strC)
            {
                string& s = v[strC];
                if (s.empty())
                    continue;

                if (!choosen)
                    choosen = *s.begin();

                for (int i = 0; i < s.size(); ++i)
                {
                    if (s[i] != choosen)
                        break;

                    ++cnts[strC];
                }

                s = s.substr(cnts[strC]);
            }

            if (choosen == 0)
                break;

            if (*min_element(ALL(cnts)) == 0)
            {
                res = -1;
                break;
            }

            int currMax = *max_element(ALL(cnts));
            int currRes = currMax * n + 100;

            for (int i = 1; i <= currMax; ++i)
            {
                int tmp = 0;
                for (int j = 0; j < v.size(); ++j)
                    tmp += abs(cnts[j] - i);

                currRes = min(currRes, tmp);
            }

            res += currRes;
        }

        printf("Case #%d: ", CASE);
        if (res == -1)
            printf("Fegla Won\n");
        else
            printf("%d\n", res);
    }
    
    return 0;
}