#include <bits/stdc++.h>
using namespace std;

#ifdef mahou_shoujo_madoka
    #define LLF "%I64d"
#else
    #define LLF "%lld"
#endif

const int INF = 1000000007;

int gao(int n, int m, int s){
    if(1){ // chessy
        int cnt=0;
        for(int i=0;i<n;i++)
            cnt+=(m+(i%2==0?1:0))/2;
        if(cnt>=s) return 0;
    }
    int ret=INF;
    if(2){ // pattern 1
        /*
        w.o.o.w
        .x.x.x.
        o.x.x.o
        .x.x.x.
        w.o.o.w
        */
        int cnt=0,use[5]={};
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(i) cnt++;
            if(j) cnt++;
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if((i+j)%2==0){
            int x=4;
            if(i==0) x--;
            if(i==n-1) x--;
            if(j==0) x--;
            if(j==m-1) x--;
            use[x]++;
        }
        int gap=n*m-s;
        for(int i=4;i>=0;i--){
            int tmp=min(gap,use[i]);
            gap-=tmp;
            cnt-=tmp*i;
        }
        ret=min(ret,cnt);
    }

    if(3){ // pattern 2
        /*
        .o.o.o.
        o.x.x.o
        .x.x.x.
        o.x.x.o
        .o.o.o.
        */
        int cnt=0,use[5]={};
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(i) cnt++;
            if(j) cnt++;
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if((i+j)%2==1){
            int x=4;
            if(i==0) x--;
            if(i==n-1) x--;
            if(j==0) x--;
            if(j==m-1) x--;
            use[x]++;
        }
        int gap=n*m-s;
        for(int i=4;i>=0;i--){
            int tmp=min(gap,use[i]);
            gap-=tmp;
            cnt-=tmp*i;
        }
        ret=min(ret,cnt);
    }
    return ret;
}

int main(){
    int cs;
    scanf("%d",&cs);
    for(int no=1;no<=cs;no++){
        int n,m,s;
        scanf("%d%d%d",&n,&m,&s);
        if(n>m) swap(n,m);
        printf("Case #%d: %d\n",no,gao(n,m,s));
    }
}
