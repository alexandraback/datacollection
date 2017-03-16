#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int t;
    cin >> t;
    for(int zz=1;zz<=t;zz++){
        int c;
        cin >> c;
        char a[105],b[105];
        char aa[105],bb[105];
        int ca[105],cb[105];
        int backa=0,backb=0;
        scanf("%s%s",&a[1],&b[1]);
        for(int i=1;a[i];i++){
            if(a[i]!=a[i-1]){
                backa++;
                aa[backa] = a[i];
                ca[backa] = 1;
            }else{
                ca[backa]++;
            }
        }
        for(int i=1;b[i];i++){
            if(b[i]!=b[i-1]){
                backb++;
                bb[backb] = b[i];
                cb[backb] = 1;
            }else{
                cb[backb]++;
            }
        }
        if(backa!=backb) printf("Case #%d: Fegla Won\n",zz);
        else {
            bool check=true;
            for(int i=1;i<=backa;i++){
                if(aa[i]!=bb[i]){
                    printf("Case #%d: Fegla Won\n",zz);
                    check=false;
                    break;
                }
            }
            if(check){
                int ans=0;
                for(int i=1;i<=backa;i++){
                    ans+=abs(ca[i]-cb[i]);
                }
                printf("Case #%d: %d\n",zz,ans);
            }

        }
    }

    return 0;
}
