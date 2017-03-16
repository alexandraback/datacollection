#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int T,N,M[1005];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    cin>>T;
    for(int ca=1;ca<=T;ca++)
    {
        cin>>N;
        for(int i=1;i<=N;i++) cin>>M[i];
        int ans1=0,ans2=0;
        int cwj=0;
        for(int i=1;i<N;i++)
        {
            if(M[i]>M[i+1])
            {
                ans1+=(M[i]-M[i+1]);
                cwj=max(cwj,M[i]-M[i+1]);
            }
        }
        for(int i=1;i<N;i++)
        {
            if(M[i]<cwj) ans2+=M[i];
            else ans2+=cwj;
        }
        cout<<"Case #"<<ca<<": "<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
