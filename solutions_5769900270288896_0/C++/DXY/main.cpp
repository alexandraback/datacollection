#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;
typedef pair<int,int> P;
int R,C,n;
int decode(int r,int c){
    return r*C+c;
}
P encode(int X){
    return P(X/C,X%C);
}
int solve(){
    cin>>R>>C>>n;
    if(n==0)return 0;
    int comb = (1<<n)-1;
    int ans=R*C*10;
    while(comb < (1<<(R*C))){
        //对组合操作
        vector<int> A;A.clear();
        for(int i=0;i<R*C;i++){
            if(comb & (1<<i))A.push_back(i);
        }
        int cur=0;
        for(vector<int>::iterator it=A.begin();it!=A.end();it++){
            for(vector<int>::iterator ij=it+1;ij!=A.end();ij++){
                P ca = encode(*it) ,cb = encode(*ij);
                if(abs(ca.first-cb.first)+abs(ca.second-cb.second)==1){
                    cur++;
                    //cout<<ca.first<<","<<ca.second<<"::"<<cb.first<<","<<cb.second<<endl;
                }
            }
        }
        ans=min(ans,cur);
        int x = comb&-comb, y = comb+x;
        comb = ((comb&~y) / x>>1) | y;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    //freopen("/Users/DXY/Desktop/DXY/DXY/in.txt","r",stdin);
    freopen("/Users/DXY/Desktop/DXY/DXY/B-small-attempt0.in.txt","r",stdin);
    freopen("/Users/DXY/Desktop/DXY/DXY/out.txt","w",stdout);
    int T;scanf("%d",&T);
    for(int i=1;i<=T;i++){
        printf("Case #%d: %d\n",i,solve());
        //cout<<solve()<<endl;
    }
    
    return 0;
}
