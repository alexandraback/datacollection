#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <limits>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;
#define pb push_back

#include <fstream>
ifstream fin("input.txt");
ofstream fout("output.txt");
#define MAXN 3010
int T,N,sol[MAXN];
long long x[MAXN],y[MAXN];
int main()
{
    fin>>T;
    for(int t=1;t<=T;++t)
    {
        //cerr<<t<<endl;
        fout<<"Case #"<<t<<":\n";
        fin>>N;
        for(int i=0;i<N;++i) {fin>>x[i]>>y[i]; sol[i]=100000;}
        if(N==1) sol[0]=0;
        for(int i=0;i<N;++i)
        {
            for(int j=i+1;j<N;++j)
            {
                int sopra=0,sotto=0,ok=0;
                if(x[i]==x[j])
                {
                    for(int p=0;p<N;++p)
                    {
                        if(x[p]==x[i]) ok++;
                        else if(x[p]<x[i]) sotto++;
                        else sopra++;
                    }
                    sol[i]=min(sol[i],N-max(sotto,sopra)-ok);
                    sol[j]=min(sol[j],N-max(sotto,sopra)-ok);
                }
                else if(y[i]==y[j])
                {
                    for(int p=0;p<N;++p)
                    {
                        if(y[p]==y[i]) ok++;
                        else if(y[p]<y[i]) sotto++;
                        else sopra++;
                    }
                    sol[i]=min(sol[i],N-max(sotto,sopra)-ok);
                    sol[j]=min(sol[j],N-max(sotto,sopra)-ok);
                }
                else
                {
                    for(int p=0;p<N;++p)
                    {
                        long long val=(x[j]-x[i])*(y[p]-y[i]) - (y[j]-y[i])*(x[p]-x[i]);
                        if(val==0) ok++;
                        else if(val<0) sotto++;
                        else sopra++;
                    }
                    sol[i]=min(sol[i],N-max(sotto,sopra)-ok);
                    sol[j]=min(sol[j],N-max(sotto,sopra)-ok);
                }
            }
        }

        for(int i=0;i<N;++i) fout<<sol[i]<<"\n";
    }
}
