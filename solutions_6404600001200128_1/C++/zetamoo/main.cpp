#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int n,arr[1009];
        cin>>n;
        for(int f=0;f<n;f++)
            cin>>arr[f];
        int a=0, b=0,c=0;
        for(int f=1;f<n;f++)
            a+=max(0,arr[f-1]-arr[f]);
        for(int f=1;f<n;f++)
            b=max(b,arr[f-1]-arr[f]);
        for(int f=0;f<n-1;f++)
        {
            c+=min(arr[f],b);
        }
        cout<<"Case #"<<tc<<": "<<a<<" "<<c<<endl;
    }
}
