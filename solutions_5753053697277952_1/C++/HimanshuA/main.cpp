#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int n,i;
    bool operator<(const node& a) const
    {
        return n < a.n;
    }
};

int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cout<<"Case #"<<t<<": ";

        int N;
        cin>>N;

        priority_queue<node> P;
        int total=0;
        for(int i=0;i<N;i++)
        {
            node a;
            cin>>a.n;
            a.i=i;
            P.push(a);
            total+=a.n;
        }

        while(total--)
        {
            node a=P.top();
            cout<<(char)('A'+a.i);
            P.pop();
            a.n--;
            P.push(a);

            a=P.top();
            if(a.n>total/2)
            {
                total--;
                cout<<(char)('A'+a.i);
                P.pop();
                a.n--;
                P.push(a);
            }
            cout<<' ';
        }

        cout<<endl;
    }
    return 0;
}