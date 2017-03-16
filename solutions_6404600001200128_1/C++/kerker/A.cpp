#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[1003];

int main(){
    
    int T;
    scanf(" %d",&T);
    for(int t=0,N;t<T && scanf(" %d",&N)==1;t++){
        int lim = 0;
        int ans1=0,ans2=0,gap = 0;
        for(int i=0;i<N;i++){
            scanf(" %d",&a[i]);
            lim = max(lim,a[i]);
            ans2 += a[i];
            if(i>0){
                if(a[i-1]>a[i]) gap = max(a[i-1]-a[i],gap);
            }
        }
        for(int i=0;i<N-1;i++)
            if(a[i+1] < a[i])
                ans1 += (a[i]-a[i+1]);

        for(int i=gap;i<=gap;i++){
            int tmp = 0, eat = gap,left = 0;
            for(int j=0;j<N;j++){
//                printf("%d %d\n",j,left);
                if(a[j]>left)   left = a[j];
                if(left > a[j]){
                    tmp = -1;
                    break;
                }
  //              printf("%d %d\n",j,left);
                if(j==N-1)  break;
                if(left >= eat){
                    left -= eat;
                    tmp += eat;
                }else{
                    tmp += left;
                    left = 0;
                }
            }
            if(tmp!=-1){
                ans2 = min(tmp,ans2);
            }
        }
        printf("Case #%d: %d %d\n",t+1,ans1,ans2);
    }

    return 0;
}
