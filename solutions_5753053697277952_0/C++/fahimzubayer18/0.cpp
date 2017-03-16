#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ar[100];

int main()
{
    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);

    int a,b,c,d,e,x,y,z,t,n;

    scanf("%d",&t);

    for(int te=1;te<=t;te++)
    {
        printf("Case #%d:",te);

        scanf("%d",&n);

        for(a=0;a<n;a++)
        {
            scanf("%d",&ar[a]);
        }

        if(n==2)
        {
            for(a=0;a<ar[0];a++) printf(" AB");
            printf("\n");
            continue;
        }

        while(1)
        {
            x=-1;
            z=0;
            for(a=0;a<n;a++)
            {
                if(ar[a]>x)
                {
                    x=ar[a];
                    y=a;
                }
                z=z+ar[a];
            }
            if(!x) break;

            if(x==1)
            {
               z=0;
               for(a=0;a<n;a++)
               {
                   if(ar[a]) z++;
               }
               vector<char>v; v.clear();
               for(a=0;a<n;a++)
               {
                   if(ar[a]) v.push_back('A'+a);
               }
               for(a=0;a<v.size()-2;a++) printf(" %c",v[a]);
               printf(" %c%c",v[ z-2 ],v[z-1]);
               break;
            }
            else
            {
                printf(" %c",'A'+y);
                ar[y]--;
            }
        }
        printf("\n");
    }


    return 0;
}
