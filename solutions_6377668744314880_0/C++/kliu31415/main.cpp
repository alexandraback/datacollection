#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int x[3000],y[3000];
int trees;
int min_cut[3000];
void set_min_cut()
{
    double m,b,yPoint;//y=mx+b
    int on_right,on_left;
    int cur_min;
    for(int tree=0;tree<trees;tree++){
    cur_min=1000000;
    for(int i=0;i<trees;i++)
    {
        if(i==tree)continue;
        on_right=0;
        on_left=0;
        if(x[i]==x[tree])
        {
            for(int k=0;k<trees;k++)
            {
                if(x[k]>x[i])on_right++;
                else if(x[k]<x[i])on_left++;
            }
        }
        else
        {
            m=(y[i]-y[tree])/(double)(x[i]-x[tree]);
            b=y[i]-x[i]*m;
            for(int k=0;k<trees;k++)
            {
                yPoint=m*x[k]+b;
                if(abs(y[k]-yPoint)<1e-7)continue;
                if(y[k]>yPoint)on_right++;
                else if(y[k]<yPoint)on_left++;
            }
        }
        int min=on_right<on_left?on_right:on_left;
        if(min<cur_min)cur_min=min;
    }
    min_cut[tree]=cur_min;
    }
}
int main()
{
    ifstream fin("c.in");
    ofstream fout("logging.out");
    int cases;
    fin >> cases;
    for(int c=0;c<cases;c++)
    {
        fin >> trees;
        for(int i=0;i<trees;i++)fin >> x[i] >> y[i];
        if(trees>1)set_min_cut();
        else min_cut[0]=0;
        fout << "Case #" << c+1 << ":\n";
        for(int i=0;i<trees;i++)fout << min_cut[i] << "\n";
    }
    return 0;
}
