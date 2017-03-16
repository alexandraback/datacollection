#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("A-small-attempt0.in");
    ofstream fout("A-small-attempt0.out");
    // ifstream fin("B-large-practice.in");
    // ofstream fout("B-large-practice.out");

    if (!fin.is_open() || !fout.is_open())
    {
        return 1;
    }

    int t, t1 = 0;

    fin >> t;

    while (t1++ < t)
    {
        int n, temp, c1[4], c2[4];
        fin >> n;
        for (int i = 0; i < (n-1)*4; ++i)
        {
            fin >> temp;
        }
        for (int i = 0; i < 4; ++i)
        {
            fin >> c1[i];
        }
        for (int i = 0; i < (4-n)*4; ++i)
        {
            fin >> temp;
        }
        fin >> n;
        for (int i = 0; i < (n-1)*4; ++i)
        {
            fin >> temp;
        }
        for (int i = 0; i < 4; ++i)
        {
            fin >> c2[i];
        }
        for (int i = 0; i < (4-n)*4; ++i)
        {
            fin >> temp;
        }
        int num_found = 0, result;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (c1[i] == c2[j])
                {
                    num_found++;
                    result = c1[i];
                }
            }
        }
        fout << "Case #" << t1 << ": ";
        if (num_found == 1)
        {
            fout << result << endl;
        }
        else if (num_found > 1)
        {
            fout << "Bad magician!" << endl;
        }
        else
        {
            fout << "Volunteer cheated!" << endl;
        }

    }

    return 0;
}