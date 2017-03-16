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

long long n,b,arr[1009], ko=0;
bool check(long long t)
{
    long long sum=0;
    for(int f=0;f<b;f++)
    {
        sum+=(t+arr[f]-1)/arr[f];
    }
    ko=sum;
    return (sum>=n);
}

long long bs(long long a,long long b)
{
    long long mid=(a+b)/2;
    if(!check(mid)&&check(mid+1))
        return mid;
    if(!check(mid))
        return bs(mid+1,b);
    return bs(a,mid-1);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        cin>>b>>n;
        for(int f=0;f<b;f++)
            cin>>arr[f];
        long long temp=bs(0,1e18);
        priority_queue<pair<long long,long long> > q;
        ko=0;
        for(int f=0;f<b;f++)
        {
            ko+=(temp+arr[f]-1)/arr[f];
            q.push(make_pair(-((temp+arr[f]-1)/arr[f]*arr[f]-temp),-f-1));
        }
        while(ko+1<n)
        {
            pair<long long,long long>pp=q.top();
            pp.first-=arr[-pp.second-1];
            q.pop();
            q.push(pp);
            ko++;
        }
        cout<<"Case #"<<tc<<": "<<-q.top().second<<endl;
    }
}
