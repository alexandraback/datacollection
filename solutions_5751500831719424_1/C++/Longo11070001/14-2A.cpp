#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

char pic[110][110],mask[110][110];
int cntmax[110],cntmin[110],currentcnt[110];
int pointer[110];
int N;


int main()
{
    int T,kase,i,j,k,flag,cnttmp,ans,currentmax;
    scanf("%d",&T);
    for(kase = 1; kase <= T; kase++)
    {
        scanf("%d",&N);
        flag = 1;
        ans = 0;
        memset(pointer,0,sizeof(pointer));
        for(i=0;i<110;i++)
        {
            cntmax[i]=cntmin[i]=1;
        }
        for(i=0;i<N;i++)
        {
            scanf("%s",pic[i]);
            mask[i][0]=pic[i][0];k=1;
            for(j=1;j<strlen(pic[i]);j++)
            {
                if(pic[i][j]!=mask[i][k-1])
                    mask[i][k++]=pic[i][j];
            }
            mask[i][k]='\0';
        }
        for(i=0;i<N-1;i++)
        {
            if(strcmp(mask[i],mask[i+1]))
            {
                flag = 0;
                break;
            }
        }
        cout<<"Case #"<<kase<<": ";
        if(!flag)
        {
            cout<<"Fegla Won"<<endl;
            continue;
        }
        for(i=0;i<strlen(mask[0]);i++)
        {
            
            for(j=0;j<N;j++)
            {
                k=0;
                while(pic[j][pointer[j]]==mask[0][i])
                {
                    pointer[j]++;
                    k++;
                }
                cntmax[i] = max(k,cntmax[i]);
                currentcnt[j] = k;
            }
            currentmax = 1<<30;
            for(j=1;j<=cntmax[i];j++)
            {
                cnttmp = 0;
                for(k=0;k<N;k++)
                    cnttmp += abs(currentcnt[k]-j);
                currentmax = min(currentmax,cnttmp);
            }
            ans += currentmax;
        }
        cout<<ans<<endl;
    }
    return 0;
}
