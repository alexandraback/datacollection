#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    int T,i,j,t,r1,r2,C[100][2];
    int A[4][4], B[4][4];
    ifstream File("A-small-attempt0 (1).in");
    File>>T;

    for(t=0; t<T; t++)
    {
        C[t][0]=0;
        C[t][1] = -1;
        File>>r1;
        r1--;
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                File>>A[i][j];
            }
        }
        File>>r2;
        r2--;
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                File>>B[i][j];
            }
        }

        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                if (A[r1][i] == B[r2][j])
                {
                    C[t][0]++;
                    C[t][1] = A[r1][i];
                }
            }
        }
    }

    ofstream ofile;
    ofile.open("out.txt");

    for(t=0;t<T;t++)
    {
        if (C[t][0] == 0)
        {
            ofile<<"Case #"<<(t+1)<<": "<<"Volunteer cheated!"<<endl;
        }
        if (C[t][0] == 1)
        {
             ofile<<"Case #"<<(t+1)<<": "<<C[t][1]<<endl;
        }
        if (C[t][0] > 1)
        {
             ofile<<"Case #"<<(t+1)<<": "<<"Bad magician!"<<endl;
        }
    }

}
