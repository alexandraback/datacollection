#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
using namespace std;
typedef long long ll;

const int N = 1e6+6;

int calc(vector<int> v){
    sort(v.begin(), v.end());
    int ans = 1e9;
    for(int x=v[0]; x<=v.back(); ++x){
        int res = 0;
        for(int i=0;i<v.size();++i) res+=abs(x-v[i]);
        ans = min(ans, res);
    }
    return ans;
}

void solve(int test){
    
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;++i) cin>>s[i];
    
    set<string> q;
    for(int i=0;i<n;++i){
        string t;
        for(int k=0;k<s[i].length();++k) if(!k || s[i][k]!=s[i][k-1]) t+=s[i][k];
        q.insert(t);
    }
    
    bool ok = q.size()==1;
    
    int ans = 0;
    if(ok){
        string t = *q.begin();
        for(int i=0;i<t.length();++i){
            vector<int> v(n);
            for(int k=0;k<n;++k){
                int c = 0;
                for(int j=0;j<s[k].length();++j) if(s[k][j]!=t[i]) break; else ++c;
                v[k] = c;
                s[k] = s[k].substr(c);
            }
            ans+=calc(v);
        }
    }
    
    cout<<"Case #"<<test<<": ";
    
    if(!ok) cout<<"Fegla Won"; else{
        cout<<ans;
    }
    
    cout<<endl;
}

int main(){
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    
    int tn;
    cin>>tn;
    for(int ti=1;ti<=tn;++ti){
        cerr<<ti<<"..."<<endl;
        solve(ti);
        cerr<<ti<<" ok."<<endl;
    }
    
    
    return 0;
}

