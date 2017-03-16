#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int t,i,j;
    int in[10005];
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0", "w", stdout);
    scanf("%d\n",&t);
    for(int cnt = 1;cnt<=t;cnt++){
        int n;
        scanf("%d",&n);
        int ret = 0, sum =0, ma = 0;
        //printf("%s\n",in);
        for(i=0;i<n;i++)
            scanf("%d",in+i);
        for(i=0;i<n-1;i++)if(in[i+1] < in[i]){
            ret += in[i] - in[i+1];
            ma = max(ma, in[i] - in[i+1]);
        }
        for(i=0;i<n-1;i++){
            sum += min(ma, in[i]);
        }

        printf("Case #%d: %d %d\n", cnt, ret, sum);
    }
    return 0;
}
