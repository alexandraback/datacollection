#include<stdio.h>
#include<algorithm>
using namespace std;
char in[105][105];
int tid[105][105],temp[105];
int abss(int a)
{
   if(a < 0) return -a;
   return a;
}
int main(){
    
    int n,m,i,j,k,a,b,t,x,ans,cur,sum,k1,k2;
    bool can;
    
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    
    
    scanf("%d",&x);
    
    for(t=1;t<=x;t++)
       {
        scanf("%d",&n);
        ans = 200000;
        
        for(i=1;i<=n;i++)
           {
            scanf("%s",in[i]);
           }
        
        for(i=1;i<=n;i++)
           {
            can = true;
            sum = 0;
            for(j=1;j<=n;j++)
               {
                k1 = k2 = 0;
                for(k=0; in[i][k1] != '\0' || in[j][k2] != '\0' ; )
                   {
                    if(in[i][k1] == '\0' || in[j][k2] == '\0') 
                       {
                        can = false; break;
                       }
                    a = b = 0;
                    while(in[i][k1] == in[i][k1+1]) {k1++; a++;}
                    while(in[j][k2] == in[j][k2+1]) {k2++; b++;}
                    
                    
                    
                    if(in[i][k1] != in[j][k2]) 
                       {
                        can = false;
                        break;
                       }
                    sum += abss(a-b);
                    k1++; k2++;
                   }
                if(!can) break;
               }
            if(can)
               ans = min(ans,sum);
            else break;
            
           }
        
        
        if(can)
           {
            for(i=1;i<=n;i++)
               {
                for(k=0,k1=0;in[i][k1]!= '\0';k1++,k++)
                   {
                    a=1;
                    while(in[i][k1] == in[i][k1+1]) {k1++; a++;}
                    tid[i][k] = a;
                   }
               }
            ans=0;
            for(i=0;i<k;i++)
               {
              //  printf(" -- %d -- \n",i);
                for(j=1;j<=n;j++)
                   {
                    temp[j] = tid[j][i];
                   }
                sort(temp+1,temp+n+1);
                a = temp[(n+1)/2];
                //printf("a = %d n = %d\n",a,n);
                for(j=1;j<=n;j++)
                   ans += abss(a-temp[j]);
            //    printf("ans = %d\n",ans);
               }
            
           }
        
        printf("Case #%d: ",t);
        if(can) printf("%d",ans);
        else printf("Fegla Won");
        printf("\n");
       }
    
    
    
    
    
    
 scanf(" ");
 return 0;
}
