#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<fstream>
#define eps 1e-5
#define mod 1000000007
using namespace std;
int t,n,num;
int p[30];
int main(){
    freopen("A-large.in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>t;
    for(int _=1;_<=t;++_){
        cin>>n;num=0;

        for(int i=0;i<n;++i)
        {
            cin>>p[i];
            num+=p[i];
        }
        cout<<"Case #"<<_<<":";
        int f=0;
        if(num&1)
        {
            int maxp=0,ip=-1;
            for(int i=0;i<n;++i)
            {
                if(p[i]>maxp){
                    maxp=p[i];
                    ip=i;
                }
            }
            p[ip]--;
            cout<<" "<<(char)('A'+ip);
            num--;
        }
        while(num--){
            if(!f)cout<<" ";
            f=1-f;
            int maxp=0,ip=-1;
            for(int i=0;i<n;++i)
            {
                if(p[i]>maxp){
                    maxp=p[i];
                    ip=i;
                }
            }
            p[ip]--;
            cout<<(char)('A'+ip);
        }
        cout<<endl;
    }
    return 0;
}
