#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
#define Author "DemoVersion"
int dx[]={0,0,-1,1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,1,-1,-1};
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
int main(){
        ios_base::sync_with_stdio(0);
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int T,Z,a,b,u,j,i,cnt;
    cin>>T;
    for(Z=1;Z<=T;Z++){
        int A[20]={0},B[20]={0};
        cin>>a;
        for(j=1;j<=4;j++){
            for(i=1;i<=4;i++){
                cin>>u;
                if(j==a){
                    A[u]=1;
                }
            }
        }
        cin>>a;
        for(j=1;j<=4;j++){
            for(i=1;i<=4;i++){
                cin>>u;
                if(j==a){
                    B[u]=1;
                }
            }
        }
        cnt=0;
        for(i=0;i<20;i++){
            if(A[i]&&B[i]){
                    cnt++;
                    b=i;
            }
        }
        cout<<"Case #"<<Z<<": ";
        if(cnt==0){
            cout<<"Volunteer cheated!";
        }else if(cnt==1){
            cout<<b;
        }else{
            cout<<"Bad magician!";
        }
        cout<<endl;
    }

    return 0;
}
