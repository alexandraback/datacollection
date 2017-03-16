#include<stdio.h>

int m,n,k,q,a,s;

int main(){
    scanf("%d",&q);
    for(k=1;k<=q;k++){
        scanf("%d %d %d",&m,&n,&a);
        a=(m*n)-a;
        s=m*(n-1)+(m-1)*n;
        if(m==1){
            if(n==1)printf("Case #%d: %d\n",k,0);
            else{
                if(a>=n/2)printf("Case #%d: %d\n",k,0);
                else printf("Case #%d: %d\n",k,s-a*2);
            }
        }
        else{
            if(n==1){
                if(a>=m/2)printf("Case #%d: %d\n",k,0);
                else printf("Case #%d: %d\n",k,s-a*2);
            }
            else{
                if(a<=((m-2)*(n-2)+1)/2){
                    printf("Case #%d: %d\n",k,s-a*4);
                    continue;
                }
                a-=((m-2)*(n-2)+1)/2;
                s-=((m-2)*(n-2)+1)/2*4;
                if(m%2==1&&n%2==1){
                    if(a<=(m-3)+(n-3)){
                        printf("Case #%d: %d\n",k,s-a*3);
                        continue;
                    }
                    a-=(m-3)+(n-3);
                    s-=((m-3)+(n-3))*3;
                    if(a<=1)printf("Case #%d: %d\n",k,s-2);
                    else if(a<=2)printf("Case #%d: %d\n",k,3);
                    else printf("Case #%d: %d\n",k,0);
                }
                else{
                    if(a<=(m-2)+(n-2)){
                        printf("Case #%d: %d\n",k,s-a*3);
                        continue;
                    }
                    a-=(m-2)+(n-2);
                    s-=((m-2)+(n-2))*3;
                    if(a==1)printf("Case #%d: %d\n",k,s-2);
                    else printf("Case #%d: %d\n",k,0);
                }
            }
        }
    }
}
