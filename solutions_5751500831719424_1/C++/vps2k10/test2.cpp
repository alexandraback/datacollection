#include<stdio.h>
#include<iostream>
#include<fstream>
#include <string.h>
#include<math.h>
#define R return
#define FR(i,a,b) for(int i=a;i<b;i++)
#define RFR(i,a,b) for(int i=a;i>=b;i--)
#define SC(x) scanf("%d",&x)
#define SSC(x) scanf("%s",x)
#define LSC(x) scanf("%lld",&x)
#include<sstream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<utility>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define IN(i,j) a[i][j]
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define FUN(x) x==true)?1:0
#define SWAP(x,y,z) {z=x;x=y;y=z;}
#define mod 1000000003
using namespace std;
typedef long long int L;
int main()
{
    int t;
    FILE *ifile  = fopen("input.txt", "r");
    FILE *ofile = fopen("output.txt", "w");
    fscanf(ifile,"%d",&t); 
    //SC(t);
    FR(h,1,t+1)
    {
              int n;
              fscanf(ifile, "%d",&n); 
              char s[n][101];
              L ans=0;
              FR(i,0,n)fscanf(ifile, "%s",s[i]);
              vector<char>c[n];
              vector<int>v[n];
              int l[n],cntv[n];
              int j,k,cnt;
              FR(i,0,n)
              {
               j=0;
               l[i]=strlen(s[i]);
              while(j<l[i])
              {
               c[i].push_back(s[i][j]);
               cnt=1;k=j+1;
               while(k<l[i] && s[i][j]==s[i][k]){cnt++;k++;}
               j=k;
               v[i].push_back(cnt);
               }
               cntv[i]=v[i].size();
              }
              bool f=true;
              //FR(i,0,n)cout<<cntv[i]<<" ";cout<<endl;
              FR(i,0,n)
              {
               if(cntv[i]!=cntv[0]){f=false;goto falsecond;}
              }
              
              FR(i,0,n)
              {
               FR(j,0,cntv[0])
               {
                if(c[i][j]!=c[0][j])
                {
                  {f=false;goto falsecond;}
                }
               }
              }
    
              FR(j,0,cntv[0])
              {
               L sum=mod;
               int minv=v[0][j],maxv=v[0][j];
               FR(i,1,n)
               {
                if(v[i][j]<minv)minv=v[i][j];
                if(v[i][j]>maxv)maxv=v[i][j];
               }
               FR(k,minv,maxv+1)
               {
                L tsum=0;
                FR(i,0,n)
                {
                 int tmp=v[i][j]-k;
                 if(tmp<0)tmp*=-1;
                 tsum+=tmp;
                }
                if(tsum<sum)sum=tsum;
               }
               ans+=sum;
              }
    fprintf(ofile, "Case #%d: %lld\n",h,ans);
    falsecond:
              if(!f)fprintf(ofile, "Case #%d: Fegla Won\n",h);
    }
    fclose(ifile);
    fclose(ofile); 
    //system("pause");
     R 0;
}
