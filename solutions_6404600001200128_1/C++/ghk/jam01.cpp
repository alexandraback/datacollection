/*************************************************************************
    > File Name: jam01.cpp
    > Author: Guo Hengkai
    > Created Time: 2015/4/11 11:40:12
 ************************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

const string PROG = "A-large";
FILE *fin, *fout;

int T;
int smax;
int ans;

int main()
{
    fin = fopen((PROG + ".in").c_str(), "r");
    fout = fopen((PROG + ".out").c_str(), "w");

    fscanf(fin, "%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        fscanf(fin, "%d", &smax);
        ans = 0;

        fgetc(fin);  // Skip the space
        char num;
        int sum = 0;
        for (int i = 0; i <= smax; ++i)
        {
            fscanf(fin, "%c", &num);
            int m = max(i - sum, 0);
            ans += m;

            int n = num - '0';
            sum += (n + m);
        }

        fprintf(fout, "Case #%d: %d\n", t, ans);
    }

    return 0;
}
