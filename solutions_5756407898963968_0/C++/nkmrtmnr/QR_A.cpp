#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <string.h>

using namespace std;

int main(int argc, const char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Error:%d\n", __LINE__);
        return -1;
    }

    ifstream fin(argv[1]);
    ofstream fout("out.txt");

    int f;

    int T;
    fin >> T;
    for (int j = 0; j < T; j++)
    {
        int a1;
        fin >> a1;
        int t1[4][4];
        for (int i = 0; i < 4; i++)
        {
            fin >> t1[i][0] >> t1[i][1] >> t1[i][2] >> t1[i][3];
        }
        int a2;
        fin >> a2;
        int t2[4][4];
        for (int i = 0; i < 4; i++)
        {
            fin >> t2[i][0] >> t2[i][1] >> t2[i][2] >> t2[i][3];
        }

        int y;
        int count = 0;
        for (int i = 0; i < 4; i++)
        {
            int x = t1[a1 - 1][i];
            if (x == t2[a2 - 1][0]
                || x == t2[a2 - 1][1]
                || x == t2[a2 - 1][2]
                || x == t2[a2 - 1][3])
            {
                count++;
                y = x;
            }
        }

        if (count == 0)
        {
            fout << "Case #" << j+1 << ": " << "Volunteer cheated!" << endl;
        }
        else if (count == 1)
        {
            fout << "Case #" << j+1 << ": " << y << endl;
        }
        else
        {
            fout << "Case #" << j+1 << ": " << "Bad magician!" << endl;
        }
    }

    return (0);
}
