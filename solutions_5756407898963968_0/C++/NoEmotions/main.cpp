#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        int a,b;
        int t1[4][4],t2[4][4];
        cin>>a;
        for(int j=0;j<4;++j)
            for(int k=0;k<4;++k)
                cin>>t1[j][k];
        cin>>b;
        for(int j=0;j<4;++j)
            for(int k=0;k<4;++k)
                cin>>t2[j][k];

        int t[16];

        for(int j=0;j<16;++j)
            t[j]=0;

        for(int j=0;j<4;++j)
            ++t[t1[a-1][j]-1];

        for(int j=0;j<4;++j)
            ++t[t2[b-1][j]-1];

        vector<int> v;
        for(int j=0;j<16;++j)
            if(t[j]==2)
                v.push_back(j+1);
        cout<<"Case #"<<i+1<<": ";

        if(v.size()==0)
            cout<<"Volunteer cheated!"<<endl;
        else if(v.size()==1)
            cout<<v[0]<<endl;
        else
            cout<<"Bad magician!"<<endl;
    }
    return 0;
}
