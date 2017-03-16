#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int caso=1; caso<=t; caso++)
    {
        int n;
        scanf("%d",&n);

        int vet[n],maior=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&vet[i]);
            if(i>0 && vet[i] < vet[i-1]) maior = max(maior,abs(vet[i]-vet[i-1]));
        }

        int a = 0;
        for(int i=1; i<n; i++) if(vet[i] < vet[i-1]) a += abs(vet[i]-vet[i-1]);

        int b = 0;
        for(int i=0; i<n-1; i++) b += min(maior, vet[i]);

        printf("Case #%d: %d %d\n",caso,a,b);
    }
    return 0;
}
