#include<stdio.h>
#include<iostream>
using namespace std;

long long T,N,K;
long long st,dr,mij;
long long v[101000];
long long calc(long long val){
    long long num = 0;
    for(int i=1;i<=N;++i){
        num += 1 + (val / v[i]);
        if(num >= K)
            return 1LL;
    }
    //cout<<num<<"!"<<endl;
    return 0LL;
}
long long calcv(long long val){
    long long num = 0;
    for(int i=1;i<=N;++i){
        num += 1 + (val / v[i]);
    }
    return num;
}

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    cin >> T;
    int num = 1;
    while(T--){
        cin >> N >> K;
        for(int i=1;i<=N;++i){
            cin>>v[i];
        }
        st=0;
        dr = 1010101010101010LL;
        long long ret = -1;
        while(st <= dr){
            mij = (st + dr) / 2;
            int val = calc(mij);
            if(val){
                dr = mij - 1;
                ret = mij;
            }
            else st = mij + 1;
        }
        //cout<<ret<<endl;
        int res = 0;
        long long cc = K - calcv(ret-1);
        //cout<<K<<" "<<calcv(ret)<<" "<<calcv(ret-1)<<endl;
        //cout << cc << endl;
        for(int i=1;i<=N;++i) {
            if(ret % v[i] == 0 && cc <= 1){
                res = i;
                break;
            } else if(ret % v[i] == 0){
                --cc;
            }
        }
        printf("Case #%d: %d\n",num,res);
        ++num;
    }

}
