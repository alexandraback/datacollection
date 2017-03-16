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

int arr[4][2];

int main()
{
    int CASES;
    cin >> CASES;
    for (int CASE = 1; CASE <= CASES; ++CASE)
    {
        int choosen, tmp;
        cin >> choosen;

        FOR(4)
        {
            if (i+1 == choosen)
                scanf("%d%d%d%d", &arr[0][0], &arr[1][0], &arr[2][0], &arr[3][0]);
            else
                scanf("%d%d%d%d", &tmp, &tmp, &tmp, &tmp);
        }

        cin >> choosen;

        FOR(4)
        {
            if (i + 1 == choosen)
                scanf("%d%d%d%d", &arr[0][1], &arr[1][1], &arr[2][1], &arr[3][1]);
            else
                scanf("%d%d%d%d", &tmp, &tmp, &tmp, &tmp);
        }

        set<int> s1, s2, s_res;
        FOR(4)
            s1.insert(arr[i][0]),
            s2.insert(arr[i][1]);

        std::set_intersection(ALL(s1), ALL(s2), std::inserter(s_res, s_res.begin()));

        printf("Case #%d: ", CASE);

        if (s_res.empty())
            printf("Volunteer cheated!\n");
        else if (s_res.size() > 1)
            printf("Bad magician!\n");
        else
            printf("%d\n", *s_res.begin());
    }

    return 0;
}