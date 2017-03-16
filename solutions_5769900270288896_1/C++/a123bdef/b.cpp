#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    FILE *fr=fopen("b.in","r");
    FILE *fw=fopen("b.out","w");
    int cas1;fscanf(fr,"%d",&cas1);
    for (int cas=1;cas<=cas1;cas++)
    {
        int r,c,n;
        fscanf(fr,"%d%d%d",&r,&c,&n);
        if (r>c) {int t=r;r=c;c=t;}
        vector <vector <int> > a; a.clear();
        a.resize(r+2);
        for (int i=0;i<=r+1;i++) a[i].resize(c+2);
        
        for (int i=1;i<=r;i++)
            for (int j=1;j<=c;j++)
                if ((i+j)%2==0) a[i][j]=1; else a[i][j]=0;
                
        int cnt[5];for (int i=0;i<5;i++) cnt[i]=0;
        for (int i=1;i<=r;i++) for (int j=1;j<=c;j++) 
        {int tot=a[i-1][j]+a[i][j-1]+a[i+1][j]+a[i][j+1]; cnt[tot]++;}
        
        int ans=0;
        int n1=n-cnt[0];
        if (n1>0)
        {
            if (n1>=cnt[1]) {n1=n1-cnt[1]; ans=ans+cnt[1];} else {ans=ans+n1; n1=0;}
            if (n1>=cnt[2]) {n1=n1-cnt[2]; ans=ans+cnt[2]*2;} else {ans=ans+n1*2; n1=0;}
            if (n1>=cnt[3]) {n1=n1-cnt[3]; ans=ans+cnt[3]*3;} else {ans=ans+n1*3; n1=0;}
            if (n1>=cnt[4]) {n1=n1-cnt[4]; ans=ans+cnt[4]*4;} else {ans=ans+n1*4; n1=0;}
        }
        int ans1=ans;
        
        for (int i=1;i<=r;i++)
            for (int j=1;j<=c;j++)
                if ((i+j)%2==0) a[i][j]=0; else a[i][j]=1;
                
        for (int i=0;i<5;i++) cnt[i]=0;
        for (int i=1;i<=r;i++) for (int j=1;j<=c;j++) 
        {int tot=a[i-1][j]+a[i][j-1]+a[i+1][j]+a[i][j+1]; cnt[tot]++;}
        
        ans=0;
        n1=n-cnt[0];
        if (n1>0)
        {
            if (n1>=cnt[1]) {n1=n1-cnt[1]; ans=ans+cnt[1];} else {ans=ans+n1; n1=0;}
            if (n1>=cnt[2]) {n1=n1-cnt[2]; ans=ans+cnt[2]*2;} else {ans=ans+n1*2; n1=0;}
            if (n1>=cnt[3]) {n1=n1-cnt[3]; ans=ans+cnt[3]*3;} else {ans=ans+n1*3; n1=0;}
            if (n1>=cnt[4]) {n1=n1-cnt[4]; ans=ans+cnt[4]*4;} else {ans=ans+n1*4; n1=0;}
        }
        if (ans1<ans) ans=ans1;
        fprintf(fw,"Case #%d: %d\n",cas,ans);
        
        
    }
//    system("pause");
    return 0;
}
