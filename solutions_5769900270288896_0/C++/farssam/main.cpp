#include<cstdio>
#define oo 0x7fffffff
#define N 10000


int r,c,m,n,dap;
int a[N];
int pp,test;

void solve(int x,int y,int z){
    int p=0;

    if(y==m){
        dap=dap<z?dap:z;
        return;
    }
    if(x>=n){
        return;
    }


    //alloc
    p=(x%c!=0 && a[x-1]==test)?1:0;
    p +=(x>=c && a[x-c]==test)?1:0;
    a[x]=test;
    solve(x+1,y+1,z+p);
    a[x]=0;

    if(m-y<n-x)
        solve(x+1,y,z);
}

int main(void){
    int i,j,x,y,z,k;

    char ss[N+5];
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
