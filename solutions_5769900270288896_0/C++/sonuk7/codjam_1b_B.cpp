#include<bits/stdc++.h>
using namespace std;
int ar[10][10];
int ok(int i,int j,int r,int c) {
    return i>=0 && i<r && j>=0 && j<c && ar[i][j]==1;
}
int get(int r,int c,int l,int n) {
    int k=0,zz=l;
    while(l!=0) { if(l&1) k++; l>>=1;  }
    if(k!=n) return r*c*10;
    //cout<<zz<<endl;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            int v=(c*i+j);
            int z=zz&(1<<v);
            if(z!=0) z=1;
            ar[i][j]=z;
        }
    }
    int ans=0;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(ar[i][j]==0) continue;
            if(ok(i+1,j,r,c)) ans++;
            if(ok(i,j+1,r,c)) ans++;
        }
    }
    return ans;
}
int main() {
    int t,r,c,n;
    scanf("%d",&t);
    for(int t1=1;t1<=t;t1++) {
        scanf("%d%d%d",&r,&c,&n);
        int z=r*c;
        int minans=100000;
        for(int i=0;i<(1<<z);i++) {
            int got=get(r,c,i,n);
            minans=min(got,minans);
        }
        printf("Case #%d: %d\n",t1,minans);
    }
    return 0;
}
