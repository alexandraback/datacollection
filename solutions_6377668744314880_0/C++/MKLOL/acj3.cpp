#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#define fs first
#define sc second
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef pair<long long, long long> pct;

int N;
int M;
pair<long long, long long> a[101010];
pct v[121010];
pct stiv[121010];

long long signc(pct a,pct b,pct c){

    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);

}

long long cmp(pct a, pct b){

    if(signc(v[1],a,b) == 0){
        return a < b;
    }
    return signc(v[1],a,b)<0;

}


int k;
map<pair<long long,long long>, int> h;
void makeConvex(){

    int pos=1;
    for(int i=2;i<=N;++i){
        if(v[i]<v[pos]){
            pos = i;
        }
    }
    swap(v[pos],v[1]);

    sort(v+2,v+N+1,cmp);
    k = 0;
    for(int i=1;i<=N;++i){
        while(k>=2 && (signc(stiv[k-1],stiv[k],v[i]) > 0)) --k;

        stiv[++k] = v[i];
    }

    for(int i=1;i<=N;++i){
        int ok = 0;
        for(int j=k;j>1;--j){
            if(signc(stiv[j],stiv[j-1],v[i]) == 0){
                ok = 1;
            }
            if(signc(stiv[1],stiv[k],v[i]) == 0){
                ok = 1;
            }
        }
        if(ok){
            h[v[i]] = min(h[v[i]],M-N);
        }
    }
}
void make(int x){
    N = 0;
    for(int i=0;i<17;++i){
        if( (1<<i) & x ){
            ++N;
            v[N] = a[i+1];
        }
    }
    makeConvex();
}
int T;
int main(){

    freopen("test.in","r",stdin);
    freopen("test2.out","w",stdout);

    cin>>T;
    int num = 0;
    while(T--){
        ++num;
        cin>>M;
        h.clear();
        for(int i=1;i<=M;++i){
            cin>>a[i].fs>>a[i].sc;
            h[mp(a[i].fs,a[i].sc)] = M-1;
        }

        for(int i=1;i<(1<<M);++i){
            make(i);
        }
        cout<<"Case #"<<num<<":"<<endl;
        for(int i=1;i<=M;++i){
            cout<<h[mp(a[i].fs,a[i].sc)]<<endl;
        }
    }

    return 0;
}
