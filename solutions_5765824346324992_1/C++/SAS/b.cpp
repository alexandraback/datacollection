#include<stdio.h>
#include<stdlib.h>
int m[1024];
int B;
int N;
long long int binarysearch(long long int maxMinute)
{
    long long int l = 0;
    long long int h = maxMinute;
    long long int mid;

    while (l < h)
    {
        mid = (l + h) / 2;
        
        long long int s = 0;
        for(int i=0;i<B;i++){
            s += (mid / m[i]) + 1;
        }
        //printf("%lld %lld %lld %lld\n",s, l,mid,h);

        if (s >= N){
            h = mid;
        }
        else if (s < N){
            l = mid + 1;
        }
        //printf("%lld %lld %lld\n",l,mid,h);
    }
    return (l + h) / 2;

}
int max(int a,int b){
    return a > b ? a : b;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int ca =0; ca < T; ca++){
        scanf("%d %d",&B,&N);
        long long int maxMinute = 0;
        for(int i=0;i<B;i++){
            scanf("%d",&m[i]);
            maxMinute = max(maxMinute, m[i]);
        }
        long long int minute = binarysearch(maxMinute * N);
        //printf("minute = %lld\n",minute);
        long long int cusSum = 0;
        int index = -100;
        for(int i=0;i<B;i++){
            if(minute % m[i] == 0){
                cusSum += (minute / m[i]); 
            }else{
                cusSum += (minute / m[i]) + 1; 
            }
        }
        long long int remain = N;
        remain -= cusSum;
        //printf("cusSum = %lld remain = %lld\n", cusSum, remain);
        for(int i=0;i<B;i++){

            if(minute % m[i] == 0){
                remain --;
                if(remain == 0){
                    index = i;
                    break;
                }
            }
        }
        //printf("index = %d\n",index);
        printf("Case #%d: %d\n", ca + 1,index + 1);
        
    }
    return 0;
}
