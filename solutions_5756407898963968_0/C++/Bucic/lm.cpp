#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int n,rj,k,l,a[100][100],b[100][100],t;
int main()
{
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    fin>>t;
    for (int o=0; o<t; o++)
    {
        fin>>k;
        k--;
        for (int i=0; i<4; i++)
            for (int j=0; j<4; j++)
                fin>>a[i][j];
        fin>>l;
        l--;
        for (int i=0; i<4; i++)
            for (int j=0; j<4; j++)
                fin>>b[i][j];

        n=0;
        for (int i=0; i<4; i++)
            for (int j=0; j<4; j++)
                    if (a[k][i]==b[l][j])
                    {
                        n++;
                        rj=a[k][i];
                    }
        if (n>1) fout<<"Case #"<<o+1<<": Bad magician!"<<endl;
        if (n==0) fout<<"Case #"<<o+1<<": Volunteer cheated!"<<endl;
        if (n==1) fout<<"Case #"<<o+1<<": "<<rj<<endl;
    }
    return 0;
}
