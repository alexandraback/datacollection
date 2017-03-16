#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef pair<int,char> PII;
priority_queue<PII> que;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,N,x;

    cin>>T;
    for(int cas = 1;cas <= T;cas ++)
    {

        int sum = 0;
        cin>>N;
        for(int i = 0;i < N;i ++)
        {
            cin>>x;
            que.push(make_pair(x,i + 'A'));
            sum += x;
        }
        cout<<"Case #"<<cas<<":";
        if(sum & 1)
        {
            PII p = que.top();
            que.pop();
            cout<<" "<<p.second;
            p.first = p.first - 1;
            if(p.first > 0)
                    que.push(p);
        }
        while(!que.empty())
        {
            PII p = que.top();
            que.pop();
            PII q = que.top();

            if(p.first == q.first)
            {
                que.pop();
                cout<<" "<<p.second<<q.second;
                p.first = q.first = p.first - 1;
                if(p.first > 0)
                    que.push(p),que.push(q);
            }
            else
            {
                cout<<" "<<p.second<<p.second;
                p.first = p.first - 2;
                if(p.first > 0)
                    que.push(p);
            }

            /*
            if(que.empty() || que.top().first != p.first)
            {
                cout<<" "<<p.second;
                p.first = p.first - 1;
                if(p.first > 0)
                    que.push(p);
            }
            else
            {
                PII q = que.top();
                que.pop();
                cout<<" "<<p.second<<q.second;
                p.first = q.first = p.first - 1;
                if(p.first > 0)
                    que.push(p),que.push(q);
            }
            */

        }
        cout<<endl;

    }
}
