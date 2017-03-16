#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int mx = 70005;

int num[mx];

bool judge(int x){
    int nn[mx];
    int top=0;
    int xx=x;
    while(x){
        nn[top++]=x%10;
        x/=10;
    }
    for(int i=0; i<top; ++i){
        if(nn[i]==0) continue;
        if(xx % nn[i] != 0) return 0;
    }
    return 1;
}


int main(){
    freopen("/Users/w/Desktop/out.txt","w",stdout);
    int n=0;
    int p=30000;
    for(int i=1; i<=10000; ++i){
        if(judge(i)){
            for(int j=1; j<=70000; ++j){
                if(i>=(j-1)*p+1 && i<=j*p){
                    num[j]++;
                    break;
                }
            }
        }
        
    }
    for(int i=1; i<=70000; ++i){
        num[i]+=num[i-1];
    }
    for(int i=1; i<=70000; ++i){
        cout<<num[i]<<",";
    }
    cout<<endl;
    cout<<n<<"--"<<endl;
    return 0;
}





/*int main(){
    int x,y,posx,posy;
    int p=30000;
    while(cin>>x>>y){
        for(int i=1; i<=70000; ++i){
            if((i-1)*p+1<=x && x<=i*p){
                posx=i;
                break;
            }
        }
        for(int i=1; i<=70000; ++i){
            if((i-1)*p+1<=y && y<=i*p){
                posy=i;
                break;
            }
        }
        for(int i=(posx-1)*p+1; i<x; ++i){
            if(judge(i)) nn++;
        }
        for(int i=y+1; i<=posy*p; ++i){
            if(judge(i)) mm++;
        }
        cout<<num[posy]-num[posx-1]-nn-mm<<endl;
    }
    return 0 ;
}*/