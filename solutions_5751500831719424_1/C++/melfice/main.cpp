#include <bits/stdc++.h>

using namespace std;

main()
 {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;

    for(int z=0;z<T;z++)
    {
        cout<<"Case #"<<z+1<<": ";
        int n;
        cin>>n;
        string in[n];
        for(int i=0;i<n;i++)
            cin>>in[i];
        string temp;

        int c=1;
        vector<vector<int>> cnt(n);
        for(int i=1;i<in[0].size();i++)
            if(in[0][i]!=in[0][i-1])
            {
                temp+=in[0][i-1];
                cnt[0].push_back(c);
                c=1;
            }
            else c++;
        temp+=in[0][in[0].size()-1];
        int k=temp.size();
        int sum=0;
        cnt[0].push_back(c);

        for(int i=1;i<n;i++)
        {
            c=1;
            string t;
            for(int j=1;j<in[i].size();j++)
                if(in[i][j]!=in[i][j-1])
                {
                    t+=in[i][j-1];
                    cnt[i].push_back(c);
                    c=1;
                }
                else c++;
            t+=in[i][in[i].size()-1];
            cnt[i].push_back(c);
            if(t!=temp)
            {
                cout<<"Fegla Won"<<endl;
                goto NX;
            }
        }
        for(int i=0;i<k;i++)
        {
            int ans=1e9;
            for(int j=1;j<=100;j++)
            {
                int cur=0;
                for(int l=0;l<n;l++)
                    cur+=abs(j-cnt[l][i]);
                ans=min(ans,cur);
            }
            sum+=ans;
        }
        cout<<sum<<endl;

        NX:;
    }
}

