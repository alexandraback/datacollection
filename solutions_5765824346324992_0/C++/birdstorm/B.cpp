#include<bits/stdc++.h>
using namespace std;
int m[1005];
int Move[100000*1000];
set< pair<long long, int> > q;
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t; cin>>t;
    for(int cs=1; cs<=t; cs++){
        int B, n; cin>>B>>n;
        q.clear();
        for(int i=0; i<B; i++){
            scanf("%d",&m[i]);
            q.insert(make_pair(0,i));
        }
        int cnt=0;
        while(true){
            pair<long long, int> now=*q.begin();
            Move[cnt++]=now.second+1;
//            printf("~~%lld %d\n",now.first,now.second);
            q.erase(now);
            q.insert(make_pair(now.first+m[now.second],now.second));
            if((*q.begin()).first==(*q.rbegin()).first) break;
            if(cnt>=n) break;
        }
        printf("Case #%d: %d\n",cs,Move[(n-1)%cnt]);
    }
    return 0;
}
