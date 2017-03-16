#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int M[1005];
int N,B;
long long num(long long x)
{
    long long res=0;
    for(int i=0;i<B;i++)
        res+=1+x/M[i];
    return res;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;

    scanf("%d",&T);
    int c=T;
    while(T--)
    {
        scanf("%d %d",&B,&N);
        //cout<<B<<ends<<N<<endl;
        for(int i=0;i<B;i++)
            scanf("%d",&M[i]);
        long long left=0,right=(long long)M[0]*N;
        long long res=right;
        //cout<<left<<ends<<right<<endl;
        while(left<=right)
        {
            long long mid=(left+right)/2;
            //cout<<mid<<endl;
            long long sum=num(mid);
           // cout<<mid<<ends<<sum<<endl;
            if(sum>=N)
            {
                res=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        int ans;
        long long cut=num(res);
       // cout<<res<<ends<<cut<<ends<<cut-num(res)<<endl;
        cut-=N;
        for(int i=B-1;i>=0;i--)
        {
            if(res%M[i]==0)
            {
                if(!cut)
                {
                    ans=i+1;
                    break;
                }
                cut--;
            }
        }
        printf("Case #%d: %d\n",c-T,ans);
    }
    return 0;
}
