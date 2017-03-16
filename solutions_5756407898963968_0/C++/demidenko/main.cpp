#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <bitset>
#include <map>
#include <cmath>
#include <memory.h>
using namespace std;
typedef long long ll;

const int N = 1e6+6;

void solve(int test){
    
    int i1,i2;
    bitset<111> s1,s2;
    cin>>i1;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            int x;
            cin>>x;
            if(i1==i+1) s1[x]=1;
        }
    }
    cin>>i1;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            int x;
            cin>>x;
            if(i1==i+1) s2[x]=1;
        }
    }
    
    s1&=s2;
    int res = s1.count(); 
    
    cout<<"Case #"<<test<<": ";
    
    if(res==0) cout<<"Volunteer cheated!"; else
    if(res>1) cout<<"Bad magician!"; else{
        for(int i=0;i<s1.size();++i) if(s1[i]) cout<<i;
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

