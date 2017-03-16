#include<algorithm>
#include<string.h>
#include<vector>
#include<cmath>
#include<climits>
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main(){
    int test,num,M[4][4],T[4][4];

    freopen("in.txt","r",stdin);
    freopen("send.txt","w",stdout);
    scanf("%d",&test);
    int c=1;
    while(c<=test){
        int ans1,ans2;
        scanf("%d",&ans1);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%d",&M[i][j]);
            }
        }
        scanf("%d",&ans2);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%d",&T[i][j]);
            }
        }

        int ot = 0;
        int count = 0;
        for(int i=0;i<4;i++){
            if(M[ans1-1][i]==T[ans2-1][i]){
                ot = M[ans1-1][i];
                count++;
            }
        }
        if(count==1){
            printf("Case #%d: %d\n",c,ot);
        }
        else if(count>1){
            printf("Case #%d: Bad magician!\n",c);
        }
        else{
            printf("Case #%d: Volunteer cheated!\n",c);
        }
        c++;
    }
    return 0;

}
