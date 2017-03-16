#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
using namespace std;
int t[100005];
int main(){
    int n,m;
    while(scanf("%d",&n,&m)==1){
        int p,maxx=n,minn=0;
        for(int i=0;i<m;i++){
            scanf("%d",&p);
            maxx=max(maxx,p);
            minn=min(minn,p);
        }
        long long sum=0;
        int len1=minn,len2=maxx;
        sum+=len1*len2-len1*(len1+1)/2;
        sum+=len1*(len1+1)/2;

    }
    return 0;
}
