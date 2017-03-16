#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define MAX(a,b)				((a)>(b)?(a):(b))
#define MIN(a,b)				((a)<(b)?(a):(b))
#define ABS(x)					((x)<0?-(x):(x))

int main()
{
    FILE *fin,*fout;
    fin=fopen("A-large.in","r");
    fout=fopen("output1.txt","w");
    int i,x,t,n,j,len,k,flag,countt,min,c;
    char arr[101][110],str[101][110];
    int count[101][110];
    fscanf(fin,"%d",&t);
    for(x=1;x<=t;x++)
    {
        fscanf(fin,"%d",&n);
        for(i=0;i<n;i++)
        {
            fscanf(fin,"%s",arr[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<110;j++)
            count[i][j]=0;
        }

        for(i=0;i<n;i++)
        {
            len=strlen(arr[i]);
            j=0;k=1;
            str[i][j]=arr[i][j];
            count[i][j]++;
            while(k<len)
            {
                if(arr[i][k]==arr[i][k-1])
                {
                    count[i][j]++;
                }
                else
                {
                    j++;
                    str[i][j]=arr[i][k];
                    count[i][j]++;
                }
                k++;
            }
            j++;
            str[i][j]='\0';

        }
        /*for(i=0;i<n;i++)
        {
            for(j=0;j<strlen(str[i]);j++)
            printf("%c ",str[i][j]);
            printf("\n");
            for(j=0;j<strlen(str[i]);j++)
            printf("%d ",count[i][j]);
            printf("\n");
        }*/

        char sstr[110];
        for(i=0;i<strlen(str[0]);i++)
        sstr[i]=str[0][i];
        sstr[i]='\0';

        flag=1;
        for(i=1;i<n;i++)
        {
            if(strcmp(sstr,str[i]))
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            fprintf(fout,"Case #%d: Fegla Won\n",x);
            continue;
        }
        countt=0;c=0;min=100000000;

        len=strlen(str[0]);

        for(j=0;j<len;j++)
        {
            min=100000000;
            for(k=0;k<=100;k++)
            {
                c=0;
                for(i=0;i<n;i++)
                {
                    c+=ABS(count[i][j]-k);
                }
                min=MIN(min,c);
            }
            countt+=min;
        }

        fprintf(fout,"Case #%d: %d\n",x,countt);
    }
    return(0);
}
