#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("out1.txt", "w", stdout);

    int t;
    cin>>t;

    for(int cas=1; cas<=t; cas++){

        int n, x, y, a, b;
        cin>>n;
        set<pair<int, int> >S;
        int m=0;
        for(int i=0; i<n; i++){
            cin>>x;
            S.insert(make_pair(x, i));
            m+=x;
        }

        cout<<"Case #"<<cas<<": ";

        while(m)
        {
            x=(*S.rbegin()).first;
            a=(*S.rbegin()).second;

            S.erase(make_pair(x, a));

            y=(S.rbegin())->first;
            b=(*(S.rbegin())).second;

            S.insert(make_pair(x, a));

            if(m%2==0){
                cout<<char(a+'A');
                S.erase(make_pair(x, a));
                S.insert(make_pair(x-1, a));
                x--;
                cout<<char(b+'A')<<" ";
                S.erase(make_pair(y, b));
                S.insert(make_pair(y-1, b));
                y--;
                m-=2;
            }
            else if(m%2==1){
                cout<<char(a+'A')<<" ";
                S.erase(make_pair(x, a));
                S.insert(make_pair(x-1, a));
                x--;
                m-=1;
            }

            if(x==0){
                S.erase(make_pair(x, a));
            }
            if(y==0){
                S.erase(make_pair(x, b));
            }
        }
        cout<<endl;

    }

    return 0;
}
