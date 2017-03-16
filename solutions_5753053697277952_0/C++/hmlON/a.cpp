#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

char ithLetter(int);

int main()
{

    ifstream in;
    in.open("A-small-attempt0.in");
    ofstream out;
    out.open("out.txt");

    int case_num;
    in >> case_num;

    for (int i_case = 1; i_case <= case_num; i_case++)
    {

        out << "Case #" << i_case << ": ";

        int n, sump = 0, maxp, maxpi;
        in >> n;
        int p[n];
        for (int i = 0; i < n; i++)
        {
            in >> p[i];
            sump += p[i];
        }

        if(sump % 2 == 1)
        {
            maxp = p[0]; maxpi = 0;
            for (int i = 1; i < n; i++)
                if (p[i] > maxp)
                {
                    maxp = p[i];
                    maxpi = i;
                }
            p[maxpi]--;
            out << ithLetter(maxpi) << " ";
            sump--;
        }

        while(sump > 0)
        {
            maxp = p[0]; maxpi = 0;
            for (int i = 1; i < n; i++)
                if (p[i] > maxp)
                {
                    maxp = p[i];
                    maxpi = i;
                }
            p[maxpi]--;
            out << ithLetter(maxpi);

            maxp = p[0]; maxpi = 0;
            for (int i = 1; i < n; i++)
                if (p[i] > maxp)
                {
                    maxp = p[i];
                    maxpi = i;
                }
            p[maxpi]--;
            out << ithLetter(maxpi) << " ";
            sump -= 2;
        }

        out << endl;

    }

    in.close();
    out.close();

    return 0;

}

char ithLetter(int i)
{
    return (char)(65+i);
}
















