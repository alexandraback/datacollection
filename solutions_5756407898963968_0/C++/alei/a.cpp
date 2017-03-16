#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<set>
typedef long long int uli;
using namespace std;

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("data.out","w",stdout);
    int t,a1,a2,v;
    cin>>t;
    set<int>sa;
    vector<int>si;
    for(int tc=1;tc<=t;tc++){
        sa.clear();
        si.clear();
        cin>>a1;
        a1--;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cin>>v;
                if(i==a1)sa.insert(v);
            }
        }
        cin>>a2;
        a2--;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cin>>v;
                if(i==a2 && sa.count(v)==1)
                    si.push_back(v);
            }
        }
        cout<<"Case #"<<tc<<": ";
        if(si.size()==1) cout<<si[0]<<endl;
        else if(si.size()>1) cout<<"Bad magician!"<<endl;
        else cout<<"Volunteer cheated!"<<endl;
    }
    return 0;
}
