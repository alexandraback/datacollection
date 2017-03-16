#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <limits.h>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#define mod 1000000007
#define LL long long
using namespace std;


int main()
{
 freopen("A-small-attempt0.in","r",stdin);freopen("output.in","w",stdout);
    ios_base::sync_with_stdio(0);
    int t ;
    cin >> t;
    for(int i = 0 ;i  <t;i++)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0 ; i <n;i++)
        {
            cin >> a[i];
        }
        int c1=0,  c2= 0;
        for(int i = 1;i<n;i++)
        {
            if(a[i]<a[i-1])
                c1+=a[i-1]-a[i];
        }
        bool can =true;
        double mi = -1;
        for(int i = 1 ; i <n;i++)
        {
            if(a[i]<a[i-1])
            {
                can =false;
                mi = max(mi,(a[i-1]-a[i])/10.0  );
            }
        }
        double t = mi * 10.0;
        if(!can)
        {
        for(int i =1 ; i <n;i++)
        {
                c2+=min(a[i-1],(int )t);
        }
        }
        cout << "Case #"<<i+1 << ": "<<c1 <<"  " <<c2<<endl;

    }
    return 0;
}


