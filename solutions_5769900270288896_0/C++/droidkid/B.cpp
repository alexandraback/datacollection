#include<iostream>
using namespace std;

int bitCnt(int n){
    int ret = 0;
    while(n){
        if(n&1)ret++;
        n=n/2;
    }
    return ret;
}
int arr[16][16];
int check(int r, int c, int val){
    int f = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(val & 1<<f)arr[i][j]=1;
            else arr[i][j] = 0;
            f++;
        }
    }
    int ans = 0;
    for(int i=0; i<r; i++){
        for(int j=1; j<c; j++){
            if(arr[i][j-1] && arr[i][j])ans++;
        }
    }

    for(int j=0; j<c; j++){
        for(int i=1; i<r; i++){
            if(arr[i][j] && arr[i-1][j])ans++;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    for(int T=1; T<=t; T++){
        cout<<"Case #"<<T<<": ";
        int r,c,n;
        cin>>r>>c>>n;
        int total = r*c;
        int ans = 1e8;
        for(int i=0; i<(1<<total); i++){
            if(bitCnt(i)!=n)continue;
            ans = min(ans, check(r,c,i));
        }
        cout<<ans<<endl;
    }
    
}
