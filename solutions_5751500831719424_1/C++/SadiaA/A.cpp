#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
char inp[105][105];
char trim[105][105];
int oc[105][105];
int L[105];
int mx[105];
void func(int ind)
{
    int i,j,l=strlen(inp[ind]);
    int k=0;char prev;
    for(i=0; i<l; i++)
    {
        if(i==0){
           prev=inp[ind][0];
           trim[ind][0]=inp[ind][0];
           oc[ind][0]=1;
           continue;
        }
        if(inp[ind][i]==prev){
            oc[ind][k]++;
        }
        else{
            k++;
            trim[ind][k]=inp[ind][i];
            oc[ind][k]=1;
            prev=inp[ind][i];
        }
    }
    L[ind]=k;
}
bool vallid(int N)
{
    int i,j;
    for(i=1; i<N; i++)
    {
        if(L[0]!=L[i])  return false;
    }
    for(i=1; i<N; i++)
    {
        for(j=0; j<=L[i]; j++)
        {
            if(trim[0][j]!=trim[i][j])  return false;
        }
    }

    return true;
}
int cost(int N)
{
    int i,j,k,l,x,tmp,cst,ret=0;
    l=L[0];
    for(i=0; i<=l; i++) mx[i]=0;
    for(i=0; i<=l; i++)
    {
        for(j=0; j<N; j++)  mx[i]=max(mx[i],oc[j][i]);
    }
    //for(i=0; i<=l; i++)  printf("%d\n",mx[i]);
    ret=0;
    for(i=0; i<=l; i++)
    {
        tmp=-1;
        for(j=1; j<=mx[i]; j++)
        {
           cst=0;
           for(k=0; k<N; k++) {
              x=j-oc[k][i];
              if(x<0) x=-x;
              cst+=x;
           }
           if(tmp==-1)  tmp=cst;
           else tmp=min(tmp,cst);
        }
        ret+=tmp;
    }
    return ret;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,it,i,j,a,b,N,l,Ans;
    scanf("%d",&T);
    for(it=1; it<=T; it++)
    {
        scanf("%d",&N);
        for(i=0; i<N; i++)  scanf("%s",inp[i]);
        for(i=0; i<N; i++)  func(i);
        /*for(i=0; i<N; i++){
            for(j=0; j<=L[i]; j++)  printf("%c %d\n",trim[i][j],oc[i][j]);
            printf("\n");
        }*/
        printf("Case #%d: ",it);
        if(!vallid(N)){
            puts("Fegla Won");
            continue;
        }
        Ans=cost(N);
        printf("%d\n",Ans);
    }
    return 0;
}
