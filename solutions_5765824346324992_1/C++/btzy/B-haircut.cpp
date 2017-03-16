#include<cstdio>
using namespace std;
int arr[1000];
int tc,b,n;
long long low,mid,high,ch;
int main(){
    scanf("%d",&tc);
    for(int ct=1;ct<=tc;++ct){
        scanf("%d%d",&b,&n);
        for(int i=0;i<b;++i){
            scanf("%d",&arr[i]);
        }
        low=0ll;
        high=100000ll*n;
        while(true){
            if(low+1ll>=high)break;
            mid=((low+high)>>1);
            ch=0ll;
            for(int i=0;i<b;++i){
                ch+=mid/arr[i];
                if(mid%arr[i]!=0ll)++ch;
            }
            if(ch<(long long)n)low=mid;
            else high=mid;
        }
        ch=0ll;
        for(int i=0;i<b;++i){
            ch+=low/arr[i];
            if(low%arr[i]!=0ll)++ch;
        }
        for(int i=0;i<b;++i){
            if(low%arr[i]==0ll){
                ++ch;
                if(ch==n){
                    printf("Case #%d: %d\n",ct,i+1);
                    break;
                }
            }
        }
    }
}
