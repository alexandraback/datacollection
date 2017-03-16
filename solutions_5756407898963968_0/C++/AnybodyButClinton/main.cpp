#include <iostream>
#include <fstream>

using namespace std;

ifstream in("A-small-attempt0.in");
ofstream out("output.out");

int g1[4][4],g2[4][4],t,a1,a2,c[4],s;

void scan()
{
    in>>a1;
    for(int i=0;i<4;i++)for(int j=0;j<4;j++)in>>g1[i][j];
    in>>a2;
    for(int i=0;i<4;i++)for(int j=0;j<4;j++)in>>g2[i][j];
}

void reset()
{
    for(int i=0;i<4;i++)c[i]=0;
    s=0;
}

void check()
{
    for(int i=0;i<4;i++)for(int j=0;j<4;j++)
    {
        if(g1[a1-1][i]==g2[a2-1][j])
        {
            c[s]=g1[a1-1][i];
            s++;
        }
    }
}

void print(int t)
{
    out<<"Case #"<<t<<": ";
    switch(s)
    {
        case 0:
        out<<"Volunteer cheated!"<<endl;
        break;
        case 1:
        out<<c[0]<<endl;
        break;
        default:
        out<<"Bad magician!"<<endl;
    }
}

int main()
{
    in>>t;
    for(int i=0;i<t;i++)
    {
        scan();
        reset();
        check();
        print(i+1);
    }
    return 0;
}
