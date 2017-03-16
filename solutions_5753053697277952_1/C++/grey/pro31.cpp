#include <iostream>
#include <fstream>
#include <set>
#include <math.h>

using namespace std;

ifstream fin("input");
ofstream fout("output");





int main()
{
    int inputnumber,ii,n,N,J,countcopy,maxppl,group,secondgroup;
//    int n;
    string ss;
    int total=0;
    
    fin>>inputnumber;

    for (int ii=1;ii<=inputnumber;ii++)
    {
        fin>>n;
        int p[n];
        int sum=0;
        for (int jj=0;jj<n;jj++)
        {
            fin>>p[jj];
            sum+=p[jj];
        }
        fout<<"Case #"<<ii<<": ";

        while (sum>0)
        {
            maxppl=0;
            for (int kk=0;kk<n;kk++)
                if (p[kk]>maxppl)
                {
                    maxppl=p[kk];
                    group=kk;
                }
            p[group]--;
            
            
            maxppl=0;
            for (int kk=0;kk<n;kk++)
                if (p[kk]>maxppl)
                {
                    maxppl=p[kk];
                    secondgroup=kk;
                }
            //cout<<maxppl<<endl;
            //cout<<sum<<endl;
            
            if (maxppl>(sum-1-maxppl))
            {
                p[secondgroup]--;
                sum-=2;
                fout<<char(group+'A')<<char(secondgroup+'A')<<" ";
            }
            else
            {
                fout<<char(group+'A')<<" ";
                sum--;
            }
        }
        fout<<endl;
    }
    return 0;
}