#include<iostream>
#include<cstdio>
#include<memory.h>
#include<algorithm>
#define s(n) scanf("%d",&n)
using namespace std;
#define lint long long int
#define max 10000001
int arr[max];

int main()
{
  freopen("B-small-attempt1.in","r",stdin);
 freopen("op2.txt","w",stdout);
    int t,i,j,k,ans,num=1,temp,r,c,n;

    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d %d %d",&r,&c,&n);
        int tot=(c*(r-1))+(r*(c-1));
        if(n<=(((r*c)+1)/2))
        {
                       printf("Case #%d: 0\n",k);
                       continue;

        }
        else
        {
            int req=(r*c)-n;
            int d=(((r-2)*(c-2))+1)/2;
            temp=4*d;
            //cout<<req;
            if(req<=d)
            {
                temp=req*4;
            printf("Case #%d: %d\n",k,tot-temp);
            continue;
            }
            else
            {
                req-=d;
                //cout<<endl<<req<<endl;
                temp+=6*d;
                if(req<= 2*d)
                {
                    temp-=6*d;
                    temp+=3*req;
                    //cout<<temp<<endl;
                    printf("Case #%d: %d\n",k,tot-temp);
                    continue;
                }
                else
                {
                    req-=2*d;
                    temp+=req;
                  //  cout<<temp<<endl;
                   printf("Case #%d: %d\n",k,tot-temp);
                   continue;
                }
            }

        }
      //  printf("Case #%d: %d\n",k,arr[n]);
    }
    return 0;
}
