#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<climits>
#include<stack>
#include<vector>
#include<algorithm>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define KEY_NOT_FOUND -1
#ifndef ONLINE_JUDGE
    #undef gc
    #undef pc
    #define gc getchar
    #define pc putchar
#endif // ONLINE_JUDGE
#define MAX 110
char a[MAX][MAX],b[MAX],c;
int length[MAX],position[MAX],temp[MAX];
void msort(int a[],int start,int end);
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;
inline int readInt();
inline void writeInt(int a);
long long readLongLong();
void writeLongLong(long long res);
LL power(LL base,LL exp,LL x);
LL mulmod(LL a,LL b,LL c);

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    int i,j,x,n,ans,t,T,flag,temp1,median,y;
    T=readInt();
    for(t=1;t<=T;t++)
    {
        n=readInt();
        for(i=0;i<n;i++)
        {
            scanf("%s",a[i]);
            length[i]=strlen(a[i]);
            position[i]=0;
        }
        ans=flag=x=0;
        while(1)
        {
            for(i=0;i<n;i++)
            {
                b[i]=a[i][position[i]];
            }
            c=b[0];
            for(i=1;i<n;i++)
            {
                if(b[i]!=c)
                {
                    flag=1;
                    break;
                }
            }
            for(i=0;i<n;i++)
            {
                temp1=position[i];
                while(a[i][position[i]]==b[i])
                {
                    position[i]++;
                    if(position[i]==length[i])
                    {
                        x=1;
                        break;
                    }
                }
                temp[i]=position[i]-temp1;
            }
            msort(temp,0,n-1);
            median=temp[n/2];
            for(i=0;i<n;i++)
            {
                y=median-temp[i];
                if(y<0)
                    y=-y;
                ans=ans+y;
            }
            if(x==1)
            {
                for(i=0;i<n;i++)
                {
                    if(position[i]!=length[i])
                        break;
                }
                if(i<n)
                    flag=1;
                else
                    break;
            }
            if(flag==1)
                break;
        }
        if(flag==1)

            printf("Case #%d: Fegla Won\n",t);
        else

            printf("Case #%d: %d\n",t,ans);
    }


    return 0;
}
void writeInt(int a)
{
    char s[11];
    register int t = -1;
    do
    {
        s[++t] = a % 10 + '0';
        a /= 10;
    }while(a > 0);
    while(t >= 0)pc(s[t--]);
    //pc('\n');
}
int readInt()
{
    char c=gc();
    int ans=0;
    while(c<'0'||c>'9')c=gc();
    while(c>='0'&& c<='9')
    {
        ans=ans*10+c-'0';
        c=gc();
    }
    return ans;
}
long long readLongLong()
{
   long long res=0;
   char ch;
   ch=gc();
   while(ch<'0' || ch>'9')
       ch=gc();
   while(ch>='0' && ch<='9')
   {
       res=(res*10)+ch-48;
       ch=gc();
   }
   return res;
}
void writeLongLong(long long res)
{
   long long rev,count=0,n;
   rev=res;
   if(res==0)
   {
       pc('0');
       pc('\n');
       return;
   }
   while(rev%10==0)
   {
       rev=rev/10;
       count++;
   }
   rev=0;
   n=res;
   while(n)
   {
       rev=(rev*10)+(n%10);
       n=n/10;
   }
   while(rev)
   {
       pc((rev%10)+48);
       rev=rev/10;
   }
   while(count--)
   pc('0');
   //pc('\n');
}
LL power(LL base,LL exp,LL x)
{
         long long ans=0;
         if(exp==0)
                   return 1;
         ans=power(base,exp>>1,x);
         ans=(ans*ans)%x;
         if(exp & 1)
                ans=(ans*base)%x;
         return ans;
}

LL mulmod(LL a,LL b,LL c){
    LL x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

void msort(int a[],int start,int end)
{
    int mid,i,j,k=0,temp[end-start+1];
    if(start<end)
    {
        mid=(start+end)/2;
        msort(a,start,mid);
        msort(a,mid+1,end);
    }
    mid=(start+end)/2;
    i=start;
    j=mid+1;
    while((i<=mid)&&(j<=end))
    {
        if(a[i]<=a[j])temp[k++]=a[i++];
        if(a[i]>a[j])temp[k++]=a[j++];
    }
    while(i<=mid)temp[k++]=a[i++];
    while(j<=end)temp[k++]=a[j++];
    for(i=0;i<k;i++)a[i+start]=temp[i];
}
