#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string.h>
#include <climits>

#define repx(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repx(i,0,n)
#define pb push_back
#define full(v)	v.begin(),v.end()
#define VI vector<int>
#define VS vector<string>
#define LL long long
using namespace std;

int main()
{
ifstream cin("astringssmall.in");
ofstream cout("astringsmallout.txt");
int test,cas=0;
cin>>test;
while(test-- && ++cas)
{
    int n;
    cin>>n;
    VS v;
    rep(i,n)
    {
        string temp;
        cin>>temp;
        v.pb(temp);
    }
    string first="",check="";
    first += v[0][0];
    repx(i,1,v[0].size())
    {
        if(v[0][i] != v[0][i-1])
            first += v[0][i];
    }

    cout<<"Case #"<<cas<<": ";
    int ret = 0;
    bool fegla= false;
    repx(i,1,v.size())
    {
        check="";
        check+=v[i][0];
        repx(j,1,v[i].size())
        {
            if(v[i][j] != v[i][j-1] )
                check+= v[i][j];
        }
        if(first != check)
        {
            fegla = true;
            i=v.size();break;
        }
    }
    if(fegla)
    {
    cout<<"Fegla Won\n";
    continue;
    }
    int itepos[102]={0};
    rep(i,first.size())
    {
        VI cnt;
        int nn;
        rep(j,n)
        {
            nn = 0;
            int k;
            //repx(k,itepos[j],v[j].size())
            for(k=itepos[j]; k<v[j].size(); k++)
            {
                if(v[j][k] == v[j][itepos[j]])
                {
                    nn++;
                }
                else
                {
                    itepos[j] = k;
                    cnt.pb(nn);
                    break;
                }
            }
            if(k==v[j].size())
            {
                itepos[j]=k;
                cnt.pb(nn);
            }
        }
        int tem = 1000l;

        rep(j,101)
        {
            int sum = 0;
            rep(k,cnt.size())
            {
                sum += abs(cnt[k]-j);
            }
            tem = min(tem,sum);
        }
      //  cout<<tem<<"\n";
        ret+=tem;
    }
    cout<<ret<<"\n";

}
return 0;
}
