#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <deque>
using namespace std;

void main()
{
    FILE *in = fopen("A-small-attempt0.in", "r");
    FILE *out = fopen("A-small-attempt0.out", "w");

    int T;
    fscanf(in, "%d", &T);
    for (int caseId = 1; caseId <= T; ++caseId)
    {
        int N;
        fscanf(in, "%d", &N);

        deque<int> list;
        int m;
        fscanf(in, "%d", &m);
        list.push_back(m);
        int ans1 = 0;
        int ans2 = 0;
        int maxDiff = 0;
        for (int i = 1; i < N; ++i)
        {
            fscanf(in, "%d", &m);
            int lastm = list[list.size() - 1];
            if (lastm > m)
            {
                ans1 += lastm - m;
            }
            maxDiff = (lastm - m > maxDiff) ? lastm - m : maxDiff;
            list.push_back(m);
        }
        for (int i = 0; i < N - 1; ++i)
        {
            ans2 += (list[i] >= maxDiff) ? maxDiff : list[i];
        }
        fprintf(out, "Case #%d: %d %d\n", caseId, ans1, ans2);
    }

    fclose(in);
    fclose(out);
}
