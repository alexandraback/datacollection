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


int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        long long res1=0,res2=0;
        
        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                res1+=a[i]-a[i+1];
            }
        }
        
        long long diff=-1;
        for(int i=0;i<n-1;i++){
            diff=max(diff,a[i]-a[i+1]);
        }
        
    //    cout<<"diff="<<diff<<endl;
        
        for(int i=0;i<n-1;i++){
            if(a[i]<=diff) res2+=a[i];
            else res2+=diff;
        }
        
        printf("Case #%d: %lld %lld\n",t,res1,res2);
    }
    
    return 0;
}