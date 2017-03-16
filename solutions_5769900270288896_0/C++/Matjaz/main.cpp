

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int T;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main() {
    scanf("%d",&T);
    for (int case_n=1;case_n<=T;case_n++){
        int R,C,N;
        scanf("%d %d %d",&R,&C,&N);
        
        int res=200000;
        
        int grid[200][200];
        
        
        for (int g=0;g<1<<(R*C);g++){
            
            if (__builtin_popcount(g)!=N) continue;
            memset(grid, 0, sizeof(grid));
            int tmp=0;
            for (int i=1;i<=R;i++)
                for (int j=1;j<=C;j++){
                    if ((g&(1<<((i-1)*C+(j-1))))!=0) grid[i][j]=1;
                    
                    
                    if (grid[i][j]==1) for (int k=0;k<4;k++) tmp+=grid[i+dx[k]][j+dy[k]];
                    
                }
            
            res=min(res,tmp);
            
        }
        
        printf("Case #%d: %d\n",case_n,res);
        
        
    }
  
    return 0;
}
