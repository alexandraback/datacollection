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
    int t,n;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        cin>>n;
        int mini=1e9,arr[100];
        priority_queue<pair<int,int> >q;
        for(int f=0;f<n;f++)
        {
            cin>>arr[f];
            q.push(make_pair(arr[f],f));
        }
        cout<<"Case #"<<tc<<":";
        while(q.size())
        {
            int i=q.top().second,j;
            q.pop();
            if(q.size()==1&&q.top().first==arr[i])
            {
                cout<<" "<<char('A'+i)<<char('A'+q.top().second);
                j=q.top().second;
                q.pop();
                arr[i]--;
                arr[j]--;
                if(arr[i])
                q.push(make_pair(arr[i],i));
                if(arr[j])
                q.push(make_pair(arr[j],j));
            }
            else
            {
                cout<<" "<<char('A'+i);
                arr[i]--;
                if(arr[i])
                q.push(make_pair(arr[i],i));
            }
        }
        cout<<endl;
    }
    return 0;
}
