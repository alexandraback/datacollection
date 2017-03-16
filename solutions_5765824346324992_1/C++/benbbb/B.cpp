#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int T,ca,N,i,M;
int b[2000];

long long dv(long long R,long long  L)
{
    if (R==L) return R;
    long long mid,cnt;
    int i;
    cnt=0;
    mid=(R+L)/2;
    for (i=1;i<=M;i++)
    cnt+=(mid)/b[i]+1;
    if (cnt<N) return dv(mid+1,L);
    return dv(R,mid);
}

int main()
{
     freopen("B-large.in","r",stdin);
     freopen("B-large.out","w",stdout);
     int i,j;
     long long tt,cn;
     cin>>T;
     for (ca=1;ca<=T;ca++)

        {
            cin>>M>>N;
           // cout<<N<<' '<<M<<endl;
            int ans;
            for (i=1;i<=M;i++)
            cin>>b[i];
            if (N<=M) {printf("Case #%d: %d\n",ca,N);continue;}
            tt=dv(0,100000999999999);
           // cout<<"!"<<endl;
            //cout<<tt<<endl;
            cn=0;
            ans=-1;
            for (i=1;i<=M;i++)
            cn+=(tt)/b[i]+1;
             //cout<<cn<<endl;
            if (cn==N)
            for (i=M;i>=1;i--)
            if  (tt%b[i]==0) {ans=i;break;}

            if (cn>N) { cn=cn-N+1;

                        //cout<<cn<<endl;
                        for (i=M;i>=1&&cn>0;i--)
                        if  (tt%b[i]==0) {ans=i;cn--;}
                        }

             printf("Case #%d: %d\n",ca,ans);
        }
    return 0;
}
