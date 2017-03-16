#include<stdio.h>

int n,p[30];

int isvalid(){
    int i,max=0,sum=0;
    for(i=0;i<n;i++){
        if(p[i] > max) max = p[i];
        sum += p[i];
    }
    if(max + max > sum) return 0;
    return 1;
}

void process(){
    int i, cnt = 0, p1, p2;
    for(i=0;i<n;i++) cnt += p[i];
    while(cnt > 0){
        p1 = 0;
        for(i=1;i<n;i++){
            if(p[i] > p[p1]) p1 = i;
        }
        p2 = 0;
        if(p1 == 0) p2 = 1;
        for(i=0;i<n;i++){
            if(i == p1) continue;
            if(p[i] > p[p2]) p2 = i;
        }

        if(p[p2] == 0){
            printf("Fucked\n");
            return;
        }
        p[p1]--; p[p2]--;
        cnt-=2;
        if(isvalid()){
            printf("%c%c ",p1+'A',p2+'A');
            continue;
        }
        p[p2]++;
        cnt++;
        if(!isvalid()){
            printf("Fucked\n");
            return;
        }
        printf("%c ",p1+'A');
    }
    printf("\n");
}

int main(){
    int t,T,i;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        printf("Case #%d: ",t);
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&p[i]);
        process();
    }
    return 0;
}
