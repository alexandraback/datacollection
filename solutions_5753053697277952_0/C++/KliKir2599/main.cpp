#include <iostream>
#include <fstream>

using namespace std;

std::ifstream fin("input.in");
std::ofstream fout("output.out");


int main()
{
    int a [26];
    int n, i, t, j, z;

    fin >> t;
    for (i=0; i<t; i++)
    {
        fin >> n;
        for (j=0; j<n; j++) fin >> a[j];

        fout << "Case #" << i + 1 << ": ";

        int max1, nummax;
        bool emp = false;
        int sum = 0;
        for (j=0; j<n; j++) sum += a[j];
        if (n==2) for (j=0; j<a[0]; j++) fout << "AB" << " ";
        if (n!=2)
        {
            for (j=0; j<sum-2; j++)
            {
                max1 = -1000;
                for (z=0; z<n; z++)
                {
                    if (a[z]>max1)
                    {
                        max1 = a[z];
                        nummax = z;
                    }
                }
                char x;
                x = char(int('A') + nummax);
                fout << x << " ";
                a[nummax]--;
            }
            for (j=0; j<n; j++) if (a[j]!=0) fout << char(int('A') + j);
        }
        fout << endl;
    }
    return 0;
}
