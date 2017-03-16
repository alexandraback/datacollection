/* In the Name of God */
#include <iostream>
#include <set>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <string>
#include <fstream>
#include <cmath>
#include <deque>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include<cstdio>
#define lch(r) (2*(r)+1)
#define rch(r) (2*(r)+2) 
#define inf (1<<30)
#define F first
#define S second
#define mod 1000000007
using namespace std;
typedef pair<int ,int > pii;
typedef long long ll;
const int  MAXN = 100000+10;
ifstream fin("A-large.in");
ofstream fout("out.out");
vector<char>v[101];
int  main()
{
   ios_base::sync_with_stdio(false);
         int t,test=1;
         fin>>t;
        while(t)
        {
                int n , ans=0 , p=0;
                fin>>n;
                for(int i=1;i<=n;i++)
               {
                        v[i].clear();
                        string s;
                        fin>>s;
                        for(int j=0;j<s.size();j++)
                         v[i].push_back(s[j]);
               }
                        while( p==0&& v[1].size())
                        {
                                for(int i=1;i<=n;i++) 
                                 if(v[i].size()==0||v[i][v[i].size()-1]!=v[1][v[1].size()-1])
                                  p=1;
                            int te[101]={0};
                            char c=v[1][v[1].size()-1];
                           for(int i=1;i<=n;i++)
                            while(v[i].size() && v[i][v[i].size()-1] ==c)
                            {
                                te[i]++;
                                v[i].pop_back();
                            }
                            int q=mod ; 
                          for(int i=1;i<=101;i++) 
                           {
                                int sum=0;
                                for(int j=1;j<=n;j++)
                                 sum+=abs(te[j]-i);
                                 q=min(sum , q);
                           }
                           ans+=q;
                        }
                        if(v[1].size()==0)
                         for(int i=1;i<=n;i++)
                          if(v[i].size()!=0)
                           p=1;
                           fout<<"Case #"<<test<<": ";
                      if(p==1)
                       fout<<"Fegla Won"<<endl;
                      else
                       fout<<ans<<endl;     
                t--;
                test++;
        }
} 
