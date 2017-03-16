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

    int first[2], last[2];

    first[0] = first[1] = 0;
    last[0] = last[1] = 0;

    while (first[0] < strlist[0].length() && first[1] < strlist[1].length())
    {
        last[0] = first[0];
        while (last[0] < strlist[0].length() && strlist[0][last[0]] == strlist[0][first[0]])
            last[0]++;

        last[1] = first[1];
        while (last[1] < strlist[1].length() && strlist[1][last[1]] == strlist[1][first[1]])
            last[1]++;

        if (strlist[1][first[1]] != strlist[0][first[0]])
        {
            return -1;
        }
        result += abs((last[0]-first[0])-(last[1]-first[1]));

        first[0] = last[0];
        first[1] = last[1];
    }

    if (first[0] != strlist[0].length() || first[1] != strlist[1].length())
        return -1;

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
