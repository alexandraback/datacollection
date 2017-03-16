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
int T,N,a[MAXN];

int main()
{
    fin>>T;
    for(int t=1;t<=T;++t)
    {
        fout<<"Case #"<<t<<": ";
        fin>>N;
        int sol=0,maxl=0;
        for(int i=0;i<N;++i)
        {
            fin>>a[i];
            if(i!=0 && a[i-1]>a[i]) sol+=a[i-1]-a[i] , maxl=max(a[i-1]-a[i],maxl);
        }
        fout<<sol<<" ";
        sol=0;
        for(int i=0;i<N-1;++i) sol+=min(maxl,a[i]);
        fout<<sol<<"\n";
    }
    return 0;
}
