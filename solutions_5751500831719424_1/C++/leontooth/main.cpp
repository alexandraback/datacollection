// =========================================================
//
//       Filename:  The Repeater
//
//    Description:
//
//        Version:  1.0
//        Created:  05/03/2014
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  Tao Lin, tlin005@gmail.com
//        Company:  CGG
//      Copyright:  Copyright (c) 05/03/2014
//
// =========================================================

#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

int solve(std::vector < string > strlist)
{
    int result = 0;

    int N;
    N = strlist.size();

    int first[100], last[100];

    int i;
    for (i = 0; i < N; ++i)
    {
        first[i] = 0;
        last[i] = 0;
    }

    bool done = false;
    while (!done)
    {
        // find section
        for (i = 0; i < N; ++i)
        {
            char foo = strlist[i][first[i]];

            //no match
            if (foo != strlist[0][first[0]])
            {
                result = -1;
                return result;
            }

            last[i] = first[i];
            while (last[i] < strlist[i].length() && strlist[i][last[i]] == foo)
                last[i]++;
        }

        // match sections
        int x, m, best;
        m = last[0]-first[0];
        for (i = 0; i < N; ++i)
            m = max(m, last[i]-first[i]);
        best = m*N;
        for (x = 1; x <= m; ++x)
        {
            int act = 0;
            for (i = 0; i < N; ++i)
                act += abs((last[i]-first[i])-x);
            best = min(best, act);
        }
        result += best;

        // next run
        for (int i = 0; i < N; ++i)
        {
            first[i] = last[i];
            done = (first[i] == strlist[i].length());
        }
    }

    for (int i = 0; i < N; ++i)
    {
        if (first[i] != strlist[i].length())
            return -1;
    }

    return result;
}

int main()
{
    // load input
    unsigned int case_no;
    cin >> case_no;

    for (unsigned int t = 0; t < case_no; ++t)
    {
        int N;
        cin >> N;

        std::vector < string > strlist;
        string buf;
        strlist.clear();
        for (int i = 0; i < N; ++i)
        {
            cin >> buf;
            strlist.push_back(buf);
        }

        // sove problem
        int result;
        result = solve(strlist);

        cout << "Case #" << t+1 << ": ";
        if (result >= 0)
            cout << result << endl;
        else
            cout << "Fegla Won" << endl;
    }

    return 0;

}
