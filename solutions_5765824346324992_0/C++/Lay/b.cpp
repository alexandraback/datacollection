#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <sstream>
#include <map>
#include <queue>
#include <stack>

using namespace std;

long long gcd(long long x,long long y)
{
    return y==0 ? x:gcd(y,x%y);
}

long long lcm(long long x,long long y)
{
    return x*y/gcd(x,y);
}

int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){

        int b;
        long long n;
        cin>>b>>n;
        
        vector<int> bar(b);
        for(int i=0;i<b;i++){
            cin>>bar[i];
        }
        
        int res;
        if(n<=b) res=n;
        else if(b==1) res=1;
        else{
            
            long long g=gcd(bar[0],bar[1]),l=lcm(bar[0],bar[1]);
            for(int i=2;i<b;i++){
                g=gcd(g,bar[i]);
                l=lcm(l,bar[i]);
            }
            
            long long next=b+1;
            bool ok=false;
            vector<int> ind;
            for(int i=0;i<b;i++) ind.push_back(i);
                
            for(long long x=g;x!=l && !ok;x+=g){
                for(int i=0;i<b && !ok;i++){
                    if(x%bar[i]==0){
                        if(next==n){res=i+1; ok=true;}
                        else ind.push_back(i);
                        next++;
                    }
                }
            }
            
            
            if(!ok){
//                cout<<"ind=[";
//              for(int i=0;i<ind.size();i++) cout<<ind[i]<<" ";
//                cout<<"]"<<endl;
                res=ind[(n-1)%ind.size()]+1;
            }
            
        }
        printf("Case #%d: %lld\n",t,res);
    }
    
    return 0;
}