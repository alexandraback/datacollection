#include <iostream>
#include<cstdio>
#include<cstring>
#include <queue>
using namespace std;
#define f first
#define s second
#define mp make_pair

priority_queue < pair < int , char > > pq;

int n;
void read(){
    int i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        pq.push(mp(x,i+'A'));
    }
}

void solve(){
    int x;
    char c;
    string st="";
    while(pq.size()){
        x=pq.top().f;
        c=pq.top().s;
        pq.pop();
        if(x==0) continue;
        st+=c;
        x--;
        pq.push(mp(x,c));
    }
    int i,l=st.size();
    if(l&1){
        for(i=0;i<l-3;i+=2)
            cout<<st[i]<<st[i+1]<<" ";
        cout<<st[i]<<" "<<st[i+1]<<st[i+2]<<endl;
    }
    else{
        for(i=0;i<l;i+=2)
            cout<<st[i]<<st[i+1]<<" ";
        cout<<endl;
    }
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int x=0,T;
    scanf("%d",&T);
    while(T--){
        read();
        printf("Case #%d: ",++x);
        solve();
    }
    return 0;
}
