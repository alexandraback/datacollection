#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int a;
        cin>>a;a--;
        set<int> s,q;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                int c;
                cin>>c;
                if(i==a)
                {
                    s.insert(c);
                }

            }
        }
        int b;
        cin>>b;b--;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                int c;
                cin>>c;
                if(i==b)
                {
                    if(s.find(c)!=s.end())
                        q.insert(c);
                }
            }
        }
        cout<<"Case #"<<z+1<<": ";
        if(q.size()==1)
        {
            cout<<*q.begin()<<endl;
        }
        else if(q.empty())
        {
            cout<<"Volunteer cheated!"<<endl;
        }
        else
        {
            cout<<"Bad magician!"<<endl;
        }
    }
    return 0;
}
