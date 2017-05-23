#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<fstream>
using namespace std;

ifstream fin("A-small-attempt0.in");
ofstream fout("ans.out");

int t,a1,a2;
int u=4;
bool ans[17];
int main()
{
    int i,j,k,times;
    int temp;
    
    fin>>t;
    for(times=1;times<=t;times++)
    {
        memset(ans,0,sizeof(ans));
        fin>>a1;
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                fin>>temp;
                if(i==a1)
                {
                    ans[temp]=1;
                }
            }
        }
        fin>>a2;
        u=4;
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                 fin>>temp;
                 if(i!=a2 && ans[temp]==1)
                 {
                     ans[temp]=0;
                     u--;
                 }
            }
        }
        
        fout<<"Case #"<<times<<": ";
        if(u==1)
        {
             for(i=1;i<=16;i++)
             {
                  if(ans[i]==1)
                  {
                      fout<<i<<endl;
                  }
             }
        }
        else if(u==0)
        {
             fout<<"Volunteer cheated!"<<endl;
        }
        else
        {
            fout<<"Bad magician!"<<endl;
        }
    }
    
    system("pause");
    return 0;
}
