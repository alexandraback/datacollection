#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1005];
int main ()
{
    int T;
    int n;
    scanf("%d",&T);
    for(int _ = 1;_<=T;_++){
        scanf("%d",&n);
        for(int i  =0 ;i<n;i++){
            scanf("%d",&a[i]);
        }
        int a0 = 0,a1 = 0;
        int mx = 0;
        for(int i = 1;i<n;i++){
            if(a[i]<a[i-1] ) {
                a0+=a[i-1]-a[i];
                mx = max(mx,a[i-1]-a[i]);
            }
        }
        for(int i =0;i<n-1;i++){
            a1+=min(mx,a[i]);
        }
        printf("Case #%d: %d %d\n",_,a0,a1);
    }
    return 0;
}