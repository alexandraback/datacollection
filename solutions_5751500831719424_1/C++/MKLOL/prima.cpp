#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<string>
#include<iostream>
#define pb push_back
#define sc second
#define fs first
#define mp make_pair
using namespace std;
vector<int> v;
int N,M;
long long ret;
int ok=1,T,ind,K;
vector<int> mv[1010];
string S[101010];
int check(vector<int> a,vector<int> b){

    if(a.size() != b.size())
        return 1;
    for(int i=0;i<a.size();++i){
        //printf("%d %d\n",a[i],b[i]);
        if(a[i]!=b[i])
        return 1;
    }

    return 0;
}
void printv(vector<int> v){
    for(int i=0;i<v.size();++i){
        printf("%d ",v[i]);
    }
    printf("\n");
}
void make(){
    vector<int> fs,sc;
    int ind=0,pus=0;

    for(int i=0;i<S[1].size();++i){
        if(i==0){
            fs.pb(S[1][i]);
            continue;
        }
        else if(S[1][i] != S[1][i-1])
        {
            fs.pb(S[1][i]);
            pus=1;
        }
    }
    for(int i=2;i<=N;++i){
        sc.clear();

        for(int j=0;j<S[i].size();++j){
            if(j==0){
            sc.pb(S[i][j]);
            continue;
            }
            else if(S[i][j] != S[i][j-1]){
                sc.pb(S[i][j]);
            }
        }
        if(check(fs,sc)){
            ok=0;
            return;
        }
    }
    for(int i=1;i<=N;++i){
        S[i]=S[i]+"1";
        int sz = 1;
        int ind = 1;
        for(int j=1;j<S[i].size();++j){
            if(S[i][j]!=S[i][j-1]){
                mv[ind].pb(sz);
                sz=1;
                K=max(K,ind);
                ind++;
            }else{
                ++sz;
            }
        }
    }
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    cin>>T;
    while(T--){
    for(int i=0;i<=100;++i){
        mv[i].clear();
    }
    cin>>N;
    ++ind;
    ok=1;
    K=0;
    v.clear();
    ret = 0;
    v.clear();
    for(int i=1;i<=N;++i){
        cin>>S[i];
        v.pb(S[i].size());
    }
    make();
    sort(v.begin(),v.end());
    for(int i=1;i<=K;++i){
        //printf("%d! ",mv[i].size());
        sort(mv[i].begin(),mv[i].end());
        int mid = mv[i].size()/2;
        for(int j=0;j<mv[i].size();++j){
            ret+=abs(mv[i][j] - mv[i][mid]);
        }
    }
    if(ok == 1){
    printf("Case #%d: %lld\n",ind,ret);
    }
    else{
        printf("Case #%d: Fegla Won\n",ind,ret);
    }
    }

}
