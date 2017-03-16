#include <iostream>
#include <fstream>
using namespace std;

bool f[17];

void Clear()
{
    for(int i=1;i<=16;i++)f[i]=false;
}

int main()
{
    ifstream fin("magic trick.in");
    ofstream fout("magic trick.out");

    int t;
    fin>>t;

    for(int i=1;i<=t;i++)
    {
        Clear();

        int c=0;
        int card;

        int sel;

        fin>>sel;
        for(int j=0;j<16;j++)
        {
            int x;
            fin>>x;
            if(j/4+1==sel)f[x]=true;
        }

        fin>>sel;
        for(int j=0;j<16;j++)
        {
            int x;
            fin>>x;
            if(j/4+1==sel&&f[x]){c++;card=x;}
        }

        fout<<"Case #"<<i<<": ";
        switch(c)
        {
            case 0: fout<<"Volunteer cheated!"; break;
            case 1: fout<<card; break;
            default: fout<<"Bad magician!"; break;
        }
        fout<<'\n';
    }


return 0;
}
