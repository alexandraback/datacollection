#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>

typedef long long ll;
using namespace std;
#define INF (int)2e9
#define LLINF (ll)4e18
#define mod 1000000007
#define SIZE 100000

int calc(){
    int r,c,n,ans=INF;
    scanf("%d%d%d",&r,&c,&n);
    
    vector<int> vec(r*c);
    
    for(int i=0;i<n;i++)
        vec[r*c-1-i]=1;
    
    do{
        int cc=0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                
                if(vec[i*c+j]==0) continue;
                
                if(r-1>i){
                    if(vec[(i+1)*c+j]==1) cc++;
                }
                
                if(c-1>j){
                    if(vec[i*c+1+j]==1) cc++;
                }
                
            }
        }
        
        ans=min(ans,cc);
        
    }while(next_permutation(vec.begin(), vec.end()));
    
    return ans;
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    for(int i=1;i<=T;i++){
        printf("case #%d: %d\n",i,calc());
    }
    
    return 0;
}
