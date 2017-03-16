#include<bits/stdc++.h>
#define ll long long
#define pn() printf("\n")
#define si(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define sll(x) scanf("%I64d",&x)
#define pll(x) printf("%I64d",x)
#define sc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define sf(x) scanf("%f",&x)
#define pf(x) printf("%f",x)
#define sd(x) scanf("%lf",&x)
#define pd(x) printf("%lf",x)
#define sld(x) scanf("%Lf",&x)
#define pld(x) printf("%Lf",x)
#define MOD 1000000007LL
using namespace std;
int finalans=1000000;
int r,c,n;
bool board[17][17];
int findansnow(){
    int ans=0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<c;j++){
            if(board[i][j]&&board[i][j+1]){
                ans++;
            }
        }
    }
    for(int i=1;i<=c;i++){
        for(int j=1;j<r;j++){
            if(board[j][i]&&board[j+1][i]){
                ans++;
            }
        }
    }
    return ans;
}
void printboard(){
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
}
void brute(){
    int total=r*c;
    for(int i=0;i<(1<<(r*c));i++){
        memset(board,false,sizeof(board));
        int cnt=0;
        for(int j=0;j<r*c;j++){
            if(i&(1<<j)){
                int row=j/c;
                int col=j%c;
                board[row+1][col+1]=true;
                cnt++;
            }
        }
        if(cnt==n){
            //cout<<"i="<<i<<endl;
            int x=findansnow();
//            if(x<finalans||i==5){
//                printboard();
//                cout<<x<<endl;
//            }
            finalans=min(finalans,x);
        }
    }
}
int main(void){
    ifstream f1("C:\\Users\\Shivam Goel\\Desktop\\input.txt");
    ofstream f2("C:\\Users\\Shivam Goel\\Desktop\\output.txt");
    int t,tt=1;
    f1>>t;
    while(t--){
        memset(board,false,sizeof(board));
        finalans=1000000;
        f1>>r>>c>>n;
        brute();
        f2<<"Case #"<<tt<<": "<<finalans<<"\n";
        printf("Case #%d: %d\n",tt,finalans);
        //cout<<winner<<endl;
        tt++;
    }
    return 0;
}
