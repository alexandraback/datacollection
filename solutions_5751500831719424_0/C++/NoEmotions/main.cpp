#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int ti=0;ti<t;++ti)
    {
        int n;
        cin>>n;
        vector<string> v(n);
        for(int i=0;i<n;++i)
            cin>>v[i];

        vector<pair<char,int> > d[n];
        for(int i=0;i<n;++i)
            for(int j=0;j<v[i].length();)
            {
                int l=0;
                char c=v[i][j];
                while(c==v[i][j])
                {
                    ++l;
                    ++j;
                }
                d[i].push_back(make_pair(c,l));
            }
        bool correct=true;
        int l=d[0].size();
        for(int i=1;i<n;++i)
            if(d[i].size()!=l)
            {
                correct=false;
                break;
            }

        if(correct)
            for(int i=1;i<n;++i)
                for(int j=0;j<d[0].size();++j)
                    if(d[0][j].first!=d[i][j].first)
                    {
                        correct=false;
                        break;
                    }

        long long changes=0;
        if(correct)
        {
            for(int i=0;i<d[0].size();++i)
            {
                int u[n];
                int mchanges=1000000000;
                for(int j=0;j<n;++j)
                    u[j]=d[j][i].second;

                int mx=0;
                for(int j=0;j<n;++j)
                    mx=max(mx,u[j]);
                for(int k=1;k<=mx;++k)
                {
                    int tchanges=0;
                    for(int j=0;j<n;++j)
                        tchanges+=abs(u[j]-k);
                    mchanges=min(mchanges,tchanges);
                }
                changes+=mchanges;
            }
        }

        cout<<"Case #"<<ti+1;
        if(correct)
        {
            cout<<": "<<changes<<endl;
        }else
            cout<<": Fegla Won"<<endl;

    }
    return 0;
}
