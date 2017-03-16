#include<bits/stdc++.h>
using namespace std;

pair<int,int> a,b;
priority_queue<pair<int,int> > q;
int main()
{
    int n;
    int t;
    int sum;
    ifstream in ("A-large (2).in");
    ofstream out ("largesenate.txt");

    in>>t;
    for(int ts=1;ts<=t;ts++){

        out<<"Case #"<<ts<<": ";

        in>>n;
        sum = 0;
        for(int i=0;i<n;i++){
            in>>a.first;
            a.second = i;
            sum+=a.first;
            q.push(a);
        }

        while(!q.empty()){
            a = q.top();
            q.pop();

            out<<(char)(a.second+65);
            a.first--;
            sum--;
            if(!q.empty()){
                b = q.top();
                q.pop();
                if(b.first>(sum/2)){
                    out<<(char)(b.second+65);
                    b.first--;
                    sum--;
                }
                if(b.first!=0)
                    q.push(b);
            }
            if(a.first!=0)
                q.push(a);

            out<<" ";
        }

        out<<endl;
    }

    return 0;
}
