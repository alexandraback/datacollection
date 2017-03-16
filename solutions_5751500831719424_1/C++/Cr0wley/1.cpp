//                                                  به نام خداوند بخشنده ی مهربان
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <complex>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>

# define xx first
# define yy second
# define pb push_back
# define pp pop_back
# define eps 1e-9
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int maxn=100+5;
int ted[maxn][30];
vector<int> v[maxn];
string s[maxn];
int ans,n;
inline int get_min(int pos){
    int ret=1000000000,tmp;
    for(int i=1 ; i<=n ; i++){
        tmp=v[i][pos]-v[i][pos-1];
        int mini=0;
        for(int j=1 ; j<=n ; j++)
            mini+=abs(tmp-(v[j][pos]-v[j][pos-1]));
        ret=min(ret,mini);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    int t;cin>>t;
    for(int q=1 ; q<=t ; q++){
        ans=0;
        for(int i=1 ; i<=100 ; i++)
            v[i].clear();
        string t[maxn];
        cin>>n;
        for(int i=1 ; i<=n ; i++){
            cin>>s[i];
            int pos=0;
            t[i]+=s[i][pos];
            v[i].pb(0);
            while(pos<(int)s[i].size()){
                while(t[i][(int)t[i].size()-1]==s[i][pos] && pos<(int)s[i].size())pos++;
                t[i]+=s[i][pos];
                v[i].pb(pos);
            }
            v[i].pb((int)s[i].size());
        }
        cout<<"Case #"<<q<<": ";
        bool flag=true;
        for(int i=1 ; i<n ; i++){
            for(int j=i+1 ; j<=n ; j++)if(t[i]!=t[j])
                    flag=false;
        }
        if(!flag)
            cout<<"Fegla Won\n";
        else{
            for(int i=1 ; i<(int)v[1].size() ; i++)
                ans+=get_min(i);
            cout<<ans<<'\n';
        }
    }
    return 0;
}
