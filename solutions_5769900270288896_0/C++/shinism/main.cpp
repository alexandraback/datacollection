#include<fstream>
#define oo 0x7fffffff
#define N 10000
using namespace std;
int r,c,m,n,dap,pp,test;
int a[N];
void solve(int x,int y,int z);

int main()
{
    int i;

    FILE *in,*out;
    in=fopen("input.txt","r");
    out=fopen("output.txt","w");

    fscanf(in,"%d",&pp);
    for(i=1;i<=pp;i++){
        fscanf(in,"%d %d %d",&r,&c,&m);
        n=r*c;
        dap=oo;
        test=i;
        solve(0,0,0);
        fprintf(out,"Case #%d: %d\n",i,dap);
    }

    return 0;

}

void solve(int x,int y,int z)
{
    int p=0;

    if(y==m){
        dap=dap<z?dap:z;
        return;
    }
    if(x>=n){
        return;
    }

    p=(x%c!=0 && a[x-1]==test)?1:0;
    p+=(x>=c && a[x-c]==test)?1:0;
    a[x]=test;
    solve(x+1,y+1,z+p);
    a[x]=0;

    if(m-y<n-x){
        solve(x+1,y,z);
    }
}
