#include<cstdio>
int t, ct;
int a, x, y[2][4];
int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    scanf("%d", &t);
    for(ct=1; ct<=t; ct++){
        for(int i=0; i<2; i++){
            scanf("%d", &a);
            for(int j=1; j<=4; j++){
                for(int k=0; k<4; k++){
                    scanf("%d", &x);
                    if(a==j)    y[i][k]=x;
                }
            }
        }
        int ans=0;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(y[0][i]==y[1][j]){
                    ans++;
                    x=y[0][i];
                    break;
                }
            }
        }
        printf("Case #%d: ", ct);
        if(ans==0)  puts("Volunteer cheated!");
        else if(ans==1) printf("%d\n", x);
        else    puts("Bad magician!");
    }
    return 0;
}
