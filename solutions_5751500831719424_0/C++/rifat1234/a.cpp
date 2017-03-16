//#include <bits/stdc++.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <numeric>
#include <stack>
#include <functional>
#include <bitset>
#include <iomanip>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstring>
#include <cstdlib>

#define _ ios_base::sync_with_stdio(0);
#define ms(ar,val) memset(ar,val,sizeof(ar))
#define all(s) (s).begin(),(s).end()
#define rp1(i,s,n) for(int i=s;i<n;++i)
#define rp(i,n) rp1(i,0,n)
#define abs(x) (((x)< 0) ? (-(x)) : (x))
#define pb push_back
#define LL long long
#define Read(x) freopen(x,"r",stdin)
#define Write(x) freopen(x,"w",stdout)
#define st(N,pos) (sts[N]=sts[N] | (1<<pos))
#define check(N,pos) ((bool)(sts[N] & (1<<pos)))
#define i_s(num)  static_cast<ostringstream*>( &(ostringstream() << num) )->str();
#define inf INT_MAX
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define PQ priority_queue
#define F first
#define S second
#define bits(n) __builtin_popcount(n)
#define EPS 1e-11
#define hi 110

///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;


string s[hi];
vector <int> v[hi];
vector <int> num[hi];
int main()
{
#if defined( rifat_pc )
    Write("out.txt");
    Read("A-small-attempt1 (2).in");
#endif
    int tst,cnt=1;
    cin>>tst;
    while(tst--)
    {
        int n;
        cin>>n;
        rp(i,n)cin>>s[i];
        rp(i,hi)v[i].clear();
        rp(i,hi)num[i].clear();
        int x=0;

        rp(i,n)
        {
            x=1;
            rp(j,s[i].size()-1)
            {
                if(s[i][j]!=s[i][j+1])
                {
                    num[i].pb(x);
                    v[i].pb(s[i][j]-'a');
                    x=1;
                }
                else x++;
            }
            if(s[i][s[i].size()-1]==s[i][s[i].size()-2])v[i].pb(s[i][s[i].size()-1]-'a'),num[i].pb(x);
            else {num[i].pb(x);v[i].pb(s[i][s[i].size()-1]-'a');}
        }

        set <int> st;
        rp(i,n)st.insert(v[i].size());
        bool ok=1;
        if(st.size()!=1)ok=0;
        st.clear();
//        rp(i,n){
//
//            rp(j,v[0].size()){
//                cout<<num[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        if(ok)
        {
            rp(i,n-1)if(ok)rp(j,v[i].size())
                if(v[i][j]!=v[i+1][j])
                {
                    ok=0;
                    break;
                }
        }
        if(ok)
        {
            rp(i,v[0].size())
            {
                st.clear();
                rp(j,n)st.insert(v[j][i]);
                if(st.size()!=1)ok=0;
            }
        }
        int ans[hi];
        rp(i,hi)ans[i]=inf;

        if(ok)rp(j,v[0].size())rp1(i,1,105)
        {
            int tot=0;
            rp(k,n)
            {
                tot+=abs(num[k][j]-i);
            }
            //cout<<i<<"->"<<tot<<endl;
            ans[j]=min(ans[j],tot);
        }
        int val=0;
        rp(i,v[0].size())val+=ans[i];
        if(!ok)cout<<"Case #"<<cnt++<<": Fegla Won"<<endl;
        else cout<<"Case #"<<cnt++<<": "<<val<<endl;
    }


    return 0;
}


