#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

#define cin in
#define cout out

struct str
{
    char b;
    int num;
};

int main()
{
    int t;
    cin>>t;
    for (int i=0;i<t;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        vector<str> t[150];
        int n;
        cin>>n;
        for (int j=0;j<n;j++)
        {
            string h;
            cin>>h;
            int y=0;
            str nw;
            nw.b=h[0];
            nw.num=1;
            for (int k=1;k<h.length();k++)
            {
                if (h[k]==h[k-1])
                    nw.num++;
                else
                {
                    t[j].push_back(nw);
                    nw.b=h[k];
                    nw.num=1;
                }
            }
            t[j].push_back(nw);
        }
        bool lol=0;
        for (int j=1;j<n;j++)
        {
            if (t[j].size()!=t[0].size())
            {
                lol=1;
                break;
            }
            for (int k=0;k<t[0].size();k++)
                if (t[j][k].b!=t[0][k].b)
                    lol=1;
                    break;
        }
        if (lol)
        {
            cout<<"Fegla Won"<<endl;
            continue;
        }
        long long ans=0;
        for (int j=0;j<t[0].size();j++)
        {
            long long curr=12345678932165;
            for (int k=1;k<=100;k++)
            {
                long long tek=0;
                for (int h=0;h<n;h++)
                    tek+=abs(k-t[h][j].num);
                curr=min(curr,tek);
            }
            ans+=curr;
        }
        cout<<ans<<endl;
    }
    return 0;
}