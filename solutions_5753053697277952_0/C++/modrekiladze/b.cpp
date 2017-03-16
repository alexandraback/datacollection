#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <fstream>
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
using namespace std;
int main()
{
    int T,n;
    ifstream cin("A-small-attempt0.in");
    ofstream cout("Aout.txt");
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        int m,mm,s;
        bool b=0;
        pair <char,char> p;
        vector <pair<char,char> > w;
        while(1)
        {
            m=-1;
            mm=0;
            b=0;
            s=0;
            for(int i=1;i<n;i++)
            {
                if(v[i]==0) continue;
                b=1;
                s+=v[i];
                if(v[i]==v[mm]) {m=i;}
                if(v[i]>v[mm]) {mm=i;m=-1;}
            }
             if(!b) break;
             s+=v[0];
            if(m==-1 || s==3)
            {
                v[mm]--;
                p.fs=(char)('A'+mm);
                p.sc='.';
                w.pb(p);
            }
            else
                {
                v[mm]--;
                v[m]--;
                p.fs=(char)('A'+mm);
                p.sc=(char)('A'+m);
                w.pb(p);
                }

            }
            cout<<"Case #"<<t+1<<": ";
    for(int i=0;i<w.size();i++)
    {
        cout<<w[i].fs;
        if(w[i].sc != '.') cout<<w[i].sc;
        cout<<" ";
    }
    cout<<endl;
    }
   return 0;
}
