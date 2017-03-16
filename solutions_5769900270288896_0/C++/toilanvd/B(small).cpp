#include <cstdio>
#include <cstring>

using namespace std;

int n, m, k, q;
int a[25][25];
int dx[]= {1, 0, 0, -1};
int dy[]= {0, 1, -1, 0};
int res;

bool ok(int x, int y){
    if(x<=0 || y<=0 || x>n || y>m) return false;
    return true;
}

void backtrack(int i, int j, int t, int s){
    if(s>=res) return;
    if(i==n+1){
        if(t==0) res= s;
        return;
    }
    if(j==m) backtrack(i+1,1,t,s);
    else backtrack(i,j+1,t,s);
    if(t>0){
        a[i][j]= 1;
        if(ok(i-1,j)==true && a[i-1][j]==1) s++;
        if(ok(i,j-1)==true && a[i][j-1]==1) s++;
        if(j==m) backtrack(i+1,1,t-1,s);
        else backtrack(i,j+1,t-1,s);
        a[i][j]= 0;
    }
}

int main(){
    freopen("B(small).in","r",stdin);
    freopen("B(ok).out","w",stdout);

    int test; scanf("%d", &test);
    for(int timer=1;timer<=test;timer++){
        scanf("%d%d%d", &n, &m, &k); q= k;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]= 1; k= n*m-k;
        while(k--){
            int maxi= -1, x, y;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(a[i][j]==0) continue;
                    int cnt= 0;
                    for(int t=0;t<4;t++){
                        if(ok(i+dx[t],j+dy[t])==true && a[i+dx[t]][j+dy[t]]==1) cnt++;
                    }
                    if(cnt>maxi){
                        maxi= cnt; x= i; y= j;
                    }
                }
            }
            a[x][y]= 0;
        }
        res= 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //printf("%d ", a[i][j]);
                if(a[i][j]==0) continue;
                for(int t=0;t<2;t++){
                    if(ok(i+dx[t],j+dy[t])==true && a[i+dx[t]][j+dy[t]]==1) res++;
                }
            }
            //printf("\n");
        }

        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]= 0;
        backtrack(1,1,q,0);

        printf("Case #%d: %d\n", timer, res);
    }

    return 0;
}
