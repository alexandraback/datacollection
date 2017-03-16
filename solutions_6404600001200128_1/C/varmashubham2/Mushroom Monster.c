#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,t,i,j,inc,maxv,s1,s2;
    int *a;
    FILE *fp,*fp1;
    fp = fopen ("A-large.in", "r");
    fp1 = fopen ("output.txt", "w+");

    fscanf(fp,"%d\n",&t);
    for(i=0;i<t;i++)
    {
        fscanf(fp,"%d\n",&n);
        a=(int *)malloc(n*sizeof(int));

        for(j=0;j<n;j++)
            fscanf(fp,"%d",&a[j]);

        maxv=0;
        s1=0;
        s2=0;
        for(j=0;j<n-1;j++)
        {
            if(a[j+1]>=a[j])
                continue;
            else
            {
                inc=(a[j]-a[j+1]);
                s1+=inc;
                if(inc>maxv)
                    maxv=inc;
            }
        }

        for(j=0;j<n-1;j++)
        {
            if(a[j]<maxv)
                inc=a[j];
            else
                inc=maxv;
            s2+=inc;
        }

        fprintf(fp1,"Case #%d: %d %d\n",i+1,s1,s2);
    }

    return 0;
}
