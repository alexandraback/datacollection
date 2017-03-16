#include<stdio.h>

int r,c,n,best;
int v[20][20];

void gen(int x,int y,int sum) {
    if(x==99) {
        if(sum!=n)
            return;
        /*
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                printf("%d ",v[i][j]);
            printf("\n");
        }
        printf("\n");
        */
        int qqq=0;
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++) {
            if(v[i][j]==0)
                continue;
            if(i!=r-1 && v[i+1][j]==1)
                qqq++;
            if(j!=c-1 && v[i][j+1]==1)
                qqq++;
        }
        if(qqq<best) {
            best=qqq;
        }
        return;
    }
    else {
        if(y!=c-1) {
            gen(x,y+1,sum);
            v[x][y]=1;
            gen(x,y+1,sum+1);
            v[x][y]=0;
        }
        else {
            if(x==r-1) {
                gen(99,99,sum);
                v[x][y]=1;
                gen(99,99,sum+1);
                v[x][y]=0;
            }
            else {
                gen(x+1,0,sum);
                v[x][y]=1;
                gen(x+1,0,sum+1);
                v[x][y]=0;
            }
        }
    }
}

int main()
{
    FILE* fin = fopen("B-small-attempt3.in","r");
    FILE* fout = fopen("out.txt","w");
    int t;
    fscanf(fin,"%d",&t);
    for(int tt=1;tt<=t;tt++) {
        fscanf(fin,"%d %d %d",&r,&c,&n);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                v[i][j]=0;
        best = 1000000;
        gen(0,0,0);
        fprintf(fout,"Case #%d: %d\n",tt,best);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
