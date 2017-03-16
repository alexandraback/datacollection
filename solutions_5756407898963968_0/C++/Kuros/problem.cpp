#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <fstream>
using namespace std;
#define mo 1000000007ll
#define eps 1e-8
#define inf 2147480000
ifstream in("A-small-attempt2.in");
ofstream out("ans.txt");
int t;
int n;
int box[17];
int aox[5][5];
int main()
{
    ios::sync_with_stdio(0);
    in>>t;
    int cac=0;
    while(t--)
    {
        cac++;
        in>>n;
        memset(box,0,sizeof(box));
        for(int i=1;i<=4;i++)
            for(int j=1;j<=4;j++)
                in>>aox[i][j];
        for(int i=1;i<=4;i++)
            box[aox[n][i]]++;
        in>>n;
        for(int i=1;i<=4;i++)
            for(int j=1;j<=4;j++)
                in>>aox[i][j];
        for(int i=1;i<=4;i++)
            box[aox[n][i]]++;
        int num=0;
        for(int i=1;i<=16;i++)
            if(box[i]==2)   num++;
        out<<"Case #"<<cac<<": ";
        if(num==0)
            out<<"Volunteer cheated!"<<endl;
        else if(num>1)
            out<<"Bad magician!"<<endl;
        else
        {
            for(int i=1;i<=16;i++)
                if(box[i]==2)
                {
                    out<<i<<endl;
                    break;
                }
        }
    }
}
