#include <iostream>

using namespace std;

bool d[100];

int t;
int main()
{
    cin>>t;
    for (int c=1;c<=t;++c)
    {
        for (int i=1;i<17;++i)
            d[i]=false;
        int a;
        cin>>a;
        --a;
        for (int i=0;i<4;++i)
        {
            for (int j=0;j<4;++j)
            {
                int x;
                cin>>x;
                if (i==a)
                    d[x]=true;
            }
        }
        cin>>a;
        --a;
        for (int i=0;i<4;++i)
        {
            for (int j=0;j<4;++j)
            {
                int x;
                cin>>x;
                if (i==a)
                    d[x]&=true;
                else
                    d[x]=false;
            }
        }
        cout<<"Case #"<<c<<": ";
        int cnt=0;
        for (int i=1;i<17;++i)
            cnt+=d[i];
        if (cnt==0)
            cout<<"Volunteer cheated!";
        else if (cnt>1)
            cout<<"Bad magician!";
        else
        {
            for (int i=1;i<17;++i)
                if (d[i])
                    cout<<i;
        }

        cout<<"\n";
    }
    return 0;
}

