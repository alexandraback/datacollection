#include<stdio.h>
#include<iostream>
using namespace std;

int T,N,v[101010];

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    cin >> T;
    int num = 1;
    while(T--){
        cin >> N;
        for(int i=1;i<=N;++i){
            cin>>v[i];
        }
        int ret1 = 0,ret2=0;
        int diffmax = 0;
        for(int i=2;i<=N;++i){
            ret1 += max(0,v[i-1] - v[i]);
            diffmax = max(diffmax, v[i-1] - v[i]);
        }

        for(int i=2;i<=N;++i){
            ret2 += min(diffmax, v[i-1]);
        }
        printf("Case #%d: %d %d\n",num,ret1,ret2);
        ++num;
    }

}
