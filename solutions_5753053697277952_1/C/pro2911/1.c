#include<stdio.h>

int main()
{
    int t,n,i,j,pos,max;
    int cnt[26],cntsum;
    char c,d;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        cntsum=0;
        for(j=0;j<n;j++){
            scanf("%d",&cnt[j]);
            cntsum += cnt[j];
        }
        printf("Case #%d: ",i);
        while(cntsum > 0){
            max = cnt[0];
            pos = 0;
            for(j=1;j<n;j++){
                if(max<cnt[j])
                {
                    max = cnt[j];
                    pos = j;
                }
            }
            cnt[pos]--;
            c = 'A' + pos;
            cntsum--;
            printf("%c",c);
            max = cnt[0];
            pos = 0;
            for(j=1;j<n;j++){
                if(max<cnt[j])
                {
                    max = cnt[j];
                    pos = j;
                }
            }
            cntsum--;
            cnt[pos]--;
            d = 'A' + pos;
            for(j=0;j<n;j++){
                if(cnt[j] > cntsum/2){
                    cntsum++;
                    cnt[pos]++;
                    d='\0';
                    break;
                }
            }
            if(d!='\0'){
                printf("%c ",d);
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}


