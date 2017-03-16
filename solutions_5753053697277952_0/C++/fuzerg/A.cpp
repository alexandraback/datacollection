#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <unordered_set>

using namespace std;

int T, N;

int main()
{
    ifstream fin("A-small.in");
    ofstream fout("A-small.out");
    fin >> T;
    for (int i = 0; i < T; ++ i)
    {
        fin >> N;
        int p[26];
        int total = 0;
        for (int j = 0; j < N; ++ j)
        {
            fin >> p[j];
            total += p[j];
        }
        int first, second, l1 = 0, l2 = 0;
        for (int j = 0; j < N; ++ j)
        {
            if (p[j] > l1)
            {
                first = j;
                l1 = p[j];
            }
        }
        for (int j = 0; j < N; ++ j)
        {
            if (p[j] > l2 && j != first)
            {
                second = j;
                l2 = p[j];
            }
        }
        fout << "Case #" << i + 1 << ": ";
        for (int j = 0; j < (l1 - l2) / 2; ++ j)
        {
            fout << (char)(first + 'A') << (char)(first + 'A') << ' ';
        }
        if ((l1 - l2) % 2 == 1) fout << (char)(first + 'A') << ' ';
        total -= (l1 - l2);
        for (int j = 0; j < N; ++ j)
        {
            if (j != first && j != second)
            {
                while (p[j] > 0)
                {
                    fout << (char)(j + 'A');
                    p[j] --;
                    if (p[j] > 0)
                    {
                        fout << (char)(j + 'A');
                        p[j] --;
                    }
                    fout << ' ';
                }
            }
        }
        for (int j = 0; j < l2; ++ j)
        {
            fout << (char)(first + 'A') << (char)(second + 'A') << ' ';
        }
        fout << endl;
    }
    return 0;
}
