#include <stdio.h>
#define min(a,b) a<b?a:b
int cc[1 << 18];
int R, C, N;
int comp(int i)
{
        int r,c, aa=0;
        for (r = 0; r < R; r++){
                for (c = 0; c < C; c++)
                {
                        if (c > 0 && (i & (1 << (r * C + c))) && (i & (1 << (r * C + c - 1))))
                                aa++;
                        if (r > 0 && (i & (1 << (r * C + c))) && (i & (1 << (r * C + c - C))))
                                aa++;
                }
        }
        return aa;
}
int main(){
        int mm,i,tt;
        freopen("input.in", "r", stdin);
        freopen("out.txt", "w", stdout);
        scanf("%d",&mm);
        for (tt=1;tt<=mm;++tt){
                scanf("%d %d %d",&R,&C,&N);
                int b = R * C * N * 100;
                for (i = 1; i < (1 << (R * C)); i++){
                        cc[i] = cc[i - (i & -i)] + 1;
                        if (cc[i] == N)
                               b = min(b, comp(i));
                }
                printf("Case #%d: %d\n", tt, b);
        }
}
