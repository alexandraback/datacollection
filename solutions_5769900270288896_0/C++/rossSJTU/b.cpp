#include<stdio.h>
#include<algorithm>
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int dex[1000005];
int dey[1000005];
int r,c;
inline bool inside(int x,int y)
{
    return (x>=0&&x<r&&y>=0&&y<c);
}
int main ()
{
    int T;
    int n,ans;
    int deg,x,y;
    
    scanf("%d",&T);
    for(int _ = 1;_<=T;_++){
        scanf("%d%d%d",&r,&c,&n);
        x = y = 0;
        for(int i =0;i<r;i++){
            for(int j = 0;j<c;j++){
                deg = 0;
                for(int k =0;k<4;k++){
                    if(inside(i+dx[k],j+dy[k])){
                        deg++;
                    }
                }
                if((i+j)&1){
                    dex[x++] = deg;
                }else{
                    dey[y++] = deg;
                }
            }
        }
        if(n<=x||n<=y) ans = 0;
        else{
            sort(dex,dex+x);
            sort(dey,dey+y);
            int tmp =0;
            for(int i =0;i<n-x;i++){
                tmp+=dey[i];
            }
            ans =0;
            for(int i =0;i<n-y;i++){
                ans+=dex[i];
            }
            ans = min(ans,tmp);
        }
        printf("Case #%d: %d\n",_,ans);
    }
    return 0;
}