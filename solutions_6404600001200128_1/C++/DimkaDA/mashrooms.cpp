// gcj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream ifstr("A-large.in");
    ofstream ofstr("A-large.out");

    int T;
    ifstr >> T;
    for (int t = 0; t < T; ++t)
    {
        int N;
        ifstr >> N;
        vector<int> m(N);
        for (int i = 0; i < N; ++i)
            ifstr >> m[i];

        int y = 0;
        int z = 0;
        int val = 0;
        for (int i = 1; i < N; ++i)
        {
            y += max(0, m[i - 1] - m[i]);
            val = max(val, (m[i - 1] - m[i]));
        }
        for (int i = 0; i + 1 < N; ++i)
        {
            z += min(val, m[i]);
        }

        ofstr << "Case #" << t + 1 << ": " << y << " " << z << endl;
    }

	return 0;
}

