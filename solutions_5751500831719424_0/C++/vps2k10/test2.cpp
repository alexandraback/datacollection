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
              char s[101];
              fscanf(ifile, "%s",s);
              vector<char>c;
              vector<int>v;
              int j=0,k,cnt;
              int l1=strlen(s);
              while(j<l1)
              {
               c.push_back(s[j]);
               cnt=1;k=j+1;
               while(k<l1 && s[j]==s[k]){cnt++;k++;}
               j=k;
               v.push_back(cnt);
               }
               int cntv=v.size();
               //FR(i,0,cntv)cout<<c[i]<<" "<<v[i]<<endl;
              
              char s1[101];
              fscanf(ifile, "%s",s1);
              vector<char>c1;
              vector<int>v1;
              l1=strlen(s1);
              j=0;
              while(j<l1)
              {
               c1.push_back(s1[j]);
               cnt=1;k=j+1;
               while(k<l1 && s1[j]==s1[k]){cnt++;k++;}
               j=k;
               v1.push_back(cnt);
               }
               
               int cntv1=v1.size(),sum=0;
               //FR(i,0,cntv1)cout<<c1[i]<<" "<<v1[i]<<endl;
               bool f=true;
               //cout<<cntv<<" "<<cntv1<<endl<<endl;
               if(cntv==cntv1)
               {
                FR(i,0,cntv1)
                {
                 if(c[i]!=c1[i])
                 {
                  f=false;
                  break;
                  }
                  else
                  {
                   k=v[i]-v1[i];
                   if(k<0)k=-1*k;
                   sum+=k;
                   }
                 }
                }
                else f=false;
              if(!f)fprintf(ofile, "Case #%d: Fegla Won\n",h);
              else fprintf(ofile, "Case #%d: %d\n",h,sum);
    }
    fclose(ifile);
    fclose(ofile); 
    //system("pause");
     R 0;
}
