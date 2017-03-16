#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
const char no[]="Volunteer cheated!";
const char mul[]="Bad magician!";
bool ok[2][100];
int a[7][7];
void process(int tc) {
    memset(ok,false,sizeof ok);
    REP(i,2) {
        int c;
        scanf("%d",&c);
        FOR(j,1,4) FOR(k,1,4) scanf("%d",&a[j][k]);
        FOR(j,1,4) ok[i][a[c][j]]=true;
    }
    int val=0;
    int cnt=0;
    FOR(i,1,16) if (ok[0][i] && ok[1][i]) {
        cnt++;
        val=i;
    }
    printf("Case #%d: ",tc);
    if (cnt==0) printf("%s\n",no);
    if (cnt>=2) printf("%s\n",mul);
    if (cnt==1) printf("%d\n",val);
}
int main(void) {
#ifndef GCJ
    freopen("tmp.txt","r",stdin);
#endif
    int t;
    scanf("%d",&t);
    FOR(i,1,t) process(i);
    return 0;
}
