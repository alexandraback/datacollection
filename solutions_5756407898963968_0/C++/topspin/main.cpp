#include <stdio.h>
#include <iostream>
#include <fstream>
#include <fstream>

using namespace std;

int c[4][4];

int main()
{
    ifstream fin("input.txt", ios::in);
    ofstream fout("output.txt", ios::out);
    fout.precision(20);

    int T;
    fin >> T;
    for (int it = 0; it < T; it++)
    {
        int r1, r2;
        fin >> r1;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                fin >> c[i][j];
        int ans = -1;
        fin >> r2;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                int cc;
                fin >> cc;
                if (i == r2 - 1)
                {
                    for (int k = 0; k < 4; k++)
                        if (c[r1 - 1][k] == cc)
                        {
                            if (ans == -1)
                                ans = cc;
                            else
                                ans = -2;
                        }
                }
            }
        if (ans == -1)
            fout << "Case #" << it + 1 << ": Volunteer cheated!";
        else if (ans == -2)
            fout << "Case #" << it + 1 << ": Bad magician!";
        else
            fout << "Case #" << it + 1 << ": " << ans;
        fout << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
