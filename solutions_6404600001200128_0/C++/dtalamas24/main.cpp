#include <bits/stdc++.h>

using namespace std;

int A[100005], casos, ctos, uno, dos, grande;

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&casos);
    for(int v=1; v<=casos; v++){
        scanf("%d",&ctos);
        for(int i=1; i<=ctos; i++){
            scanf("%d",&A[i]);
        }
        uno=dos=0;
        grande=0;
        for(int i=1; i<ctos; i++){
            if(A[i+1]<A[i]){
                uno+=A[i]-A[i+1];
                if(A[i]-A[i+1]>grande)
                    grande=A[i]-A[i+1];
            }
        }
        for(int i=1; i<ctos; i++){
            dos = dos + min(grande, A[i]);
        }
        printf("Case #%d: %d %d\n",v,uno,dos);
    }
    return 0;
}
