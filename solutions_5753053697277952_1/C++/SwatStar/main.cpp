#include <iostream>
#include <fstream>
#include <inttypes.h>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    int64_t i, j, k, T, N, array[26], count = 0, max = 0, check = 0;
    ifstream filin;
    ofstream filout;
    filin.open ("input.txt");
    filout.open ("output.txt");
    filin >> T;
    for (i = 0; i < T; i++)
    {
        count = 0;
        check = 0;
        max = 0;
        filout << "Case #" << i + 1 << ":";
        filin >> N;
        for (j = 0; j < 26; j++)
        {
            array[j] = 0;
        }
        for (j = 0; j <N; j++)
        {
            filin >> array[j];
        }
        while (check == 0)
        {
            filout << " ";
            max = 0;
            count = 0;
            for (j = 0; j < N; j++)
            {
                if (array[j] > max)
                {
                    max = array[j];
                }
            }
            for (j = 0; j < N; j++)
            {
                if (array[j] == max)
                {
                    count++;
                }
            }
            if (count == 2)
            {
                for (j = 0; j < N; j++)
                {
                    if (max == array[j])
                    {
                        filout << (char)(j + 65);
                        array[j]--;
                    }
                }
            }
            else
            {
                for (j = 0; j < N; j++)
                {
                    if (max == array[j])
                    {
                        filout << (char)(j + 65);
                        array[j]--;
                        break;
                    }
                }
            }
            check = 1;
            for (j = 0; j < N; j++)
            {
                if (array[j] != 0)
                {
                    check = 0;
                }
            }
        }
        filout << "\n";
    }
    filin.close ();
    filout.close ();
    return 0;
}
