#include<cstdio>
using namespace std;

int pro[5], pro2[5], a;

int main(){

    int t, ca=1;
    scanf("%d", &t);

    for(; t>0; t--){
        printf("Case #%d: ", ca++);
        scanf("%d", &a);
        for(int i=1; i<=4; i++){
            if(i==a)
                for(int j=0; j<4; j++)
                    scanf("%d", &pro[j]);
            else
                scanf("%*d%*d%*d%*d");
        }
        int ans = -1;
        scanf("%d", &a);
        for(int i=1; i<=4; i++){
            if(i==a)
                for(int j=0; j<4; j++){
                    scanf("%d", &pro2[j]);
                    for(int k=0; k<4; k++){
                        if(pro2[j]==pro[k]){
                            if(ans==-1)
                                ans = pro2[j];
                            else
                                ans = 17;
                        }
                    }
                }
            else
                scanf("%*d%*d%*d%*d");
        }
        if(ans==-1)
            printf("Volunteer cheated!\n");
        else if(ans==17)
            printf("Bad magician!\n");
        else
            printf("%d\n", ans);

    }

    return 0;
}

