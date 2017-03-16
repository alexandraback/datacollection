#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

char oChar(int x) {
    return (char)('A' + x);
}


int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    priority_queue< pair<int,int> > pq;

    int T,N;
    cin>>T;
    for(int ca=1;ca<=T;ca++) {
        cin>>N;
        while(pq.empty() != true) pq.pop();
        int sum = 0;
        for(int i=0;i<N;i++) {
            int x;
            cin>>x;
            pair<int,int> tmp;
            tmp.first = x;
            tmp.second = i;
            pq.push(tmp);
            sum += x;
        }
        cout<<"Case #"<<ca<<":";
        if(sum%2 == 1) {
            pair<int,int> tmp = pq.top();
            pq.pop();
            cout<<" "<<oChar(tmp.second);
            tmp.first--;
            if(tmp.first > 0) pq.push(tmp);
            sum--;
        }
        while(sum > 0) {
            pair<int,int> t1=pq.top();
            pq.pop();
            pair<int,int> t2=pq.top();
            pq.pop();
            cout<<" "<<oChar(t1.second)<<oChar(t2.second);
            t1.first--;
            t2.first--;
            if(t1.first > 0) pq.push(t1);
            if(t2.first > 0) pq.push(t2);
            sum -= 2;
        }
        cout<<endl;
    }
    return 0;
}
