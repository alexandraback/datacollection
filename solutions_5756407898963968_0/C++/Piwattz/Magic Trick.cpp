#include<stdio.h>
#include<string.h>
bool buck[20];
int p[20], pl=0;
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j ,k, t;
    scanf("%d", &t);
    for(int tt=1; tt<=t; tt++){
        scanf("%d", &k);k--;
        pl=0;
        memset(buck,0,sizeof(buck));
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                int a;
                scanf("%d", &a);
                if(i!=k)continue;
                buck[a]=1;
            }
        }
        scanf("%d", &k);k--;
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                int a;
                scanf("%d", &a);
                if(i!=k)continue;
                if(buck[a]==1)p[pl++]=a;
            }
        }
        switch(pl){
        case 0 : printf("Case #%d: Volunteer cheated!\n", tt);break;
        case 1 : printf("Case #%d: %d\n", tt,p[0]);break;
        default : printf("Case #%d: Bad magician!\n", tt);break;
        }
    }
    return 0;
}
