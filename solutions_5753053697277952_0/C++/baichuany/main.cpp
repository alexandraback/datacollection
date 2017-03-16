#include <iostream>

using namespace std;
int ten[10];
int digit(int x,int i)
{
    return x/ten[i]%10;
}

int digit_sum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=x%10;
        x/=10;
    }
    return ret;
}

int arr[37][10000];
int an[37];
int v[6];
int ans=0;
void dfs(int depth,int sum)
{
    if(depth==3)
    {
        if(v[0]!=v[5])return;
        if(v[3]!=v[4])return;
        if(v[0]+v[1]+v[2]+v[3]!=3*sum)return;
        for(int i=0;i<4;i++)
            if(sum-v[i]<0||sum-v[i]>9)return;
        ans++;
        return;
    }
    for(int i=0;i<6;i++)if(v[i]>sum)return;
    for(int i=0;i<an[sum];i++)
    {
        for(int j=0;j<4;j++)
        {
            v[j]+=digit(arr[sum][i],j);
        }
        v[4]+=digit(arr[sum][i],depth);
        v[5]+=digit(arr[sum][i],3-depth);

        dfs(depth+1,sum);

        for(int j=0;j<4;j++)
        {
            v[j]-=digit(arr[sum][i],j);
        }
        v[4]-=digit(arr[sum][i],depth);
        v[5]-=digit(arr[sum][i],3-depth);

    }
}
int main()
{
    ten[0]=1;
    for(int i=1;i<10;i++)ten[i]=ten[i-1]*10;

    for(int i=0;i<10000;i++)
    {
        int t=digit_sum(i);
        arr[t][an[t]++]=i;
    }

    for(int i=0;i<=36;i++)
    {
        cout<<i<<' '<<an[i]<<endl;
        dfs(0,i);
        cout<<ans<<endl;
    }
    return 0;
}
