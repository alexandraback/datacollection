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
#define MAXN 1010
int T,B,N;
long long M[MAXN];

bool calcola(long long tempo)
{
    long long pos=0;
    for(int i=0;i<B;++i)
    {
        pos+=(tempo+M[i]-1)/M[i];
    }
    return pos<N;
}

int calcolasol(long long tempo)
{
    long long pos=0;
    vector<int> ok;
    for(int i=0;i<B;++i)
    {
        pos+=(tempo+M[i]-1)/M[i];
        if(tempo%M[i]==0) ok.pb(i+1);
    }

    return ok[N-pos-1];
}

int main()
{
    fin>>T;
    for(int t=1;t<=T;++t)
    {
        fout<<"Case #"<<t<<": ";
        fin>>B>>N;
        for(int i=0;i<B;++i)
            fin>>M[i];
        if(N<=B) fout<<N<<"\n";
        else
        {
            long long lo=0,hi=1LL*N*100001 + 1;
            while(lo+1<hi)
            {
                long long mid=(lo+hi)/2;
                if(calcola(mid)) lo=mid;
                else hi=mid;
            }
            fout<<calcolasol(lo)<<"\n";
        }
    }
}
