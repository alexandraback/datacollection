#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define pi 2*acos(0)
#define SF scanf
#define SFd1(a) scanf("%d",&a)
#define SFd2(a,b) scanf("%d%d",&a,&b)
#define SFd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define PF printf
#define inf 99999999
#define eps 0.00000001
#define ll long long
#define ull long long unsigned
#define fr(i,n) for(i=0;i<n;i++)
#define dist(x1,y1,x2,y2) sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) )
using namespace std;
//int rr[]={1,2,-1,-2,1,2,-1,-2};
//int cc[]={2,1,2,1,-2,-1,-2,-1};

int a,ans,t,p,i,j,k,flag[110],cse,in;

main()
{
    FILE *read,*write;
    read=fopen("codejam_a_input.txt","r");
    write=fopen("codejam_a_output.txt","w");
    fscanf(read," %d",&t);
    for(p=1; p<=t; p++)
    {
        memset(flag,0,sizeof(flag));
        cse=0;
        for(k=1; k<=2; k++)
        {
            fscanf(read," %d",&a);
            for(i=1; i<=4; i++)
            {
                for(j=1; j<=4; j++)
                {
                    fscanf(read," %d",&in);
                    if(i==a)
                    {
                        if(cse==0&&flag[in]==1)
                            cse=1,flag[in]++,ans=in;
                        else if(cse==1&&flag[in]==1)
                            cse=2;
                        else flag[in]++;
                    }
                }
            }
        }
        if(cse==0)
            fprintf(write,"Case #%d: Volunteer cheated!\n",p);
        else if(cse==1)
            fprintf(write,"Case #%d: %d\n",p,ans);
        else
            fprintf(write,"Case #%d: Bad magician!\n",p);
    }
    fclose(read);
    fclose(write);
    return 0;
}
