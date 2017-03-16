#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_SIZE 16

struct point{
    int x;
    int y;
};

struct point p[MAX_SIZE];

int main(void)
{
    FILE *in = fopen("input.txt","r");
    FILE *out = fopen("output.txt","w");

    int c,t,n,i,j,k;
    int64_t x1,x2,y1,y2,v;
    int l,r,min;

    fscanf(in,"%d",&t);

    for (c=1; c<=t; c++)
    {
        fscanf(in,"%d",&n);
        for (i=0; i<n; i++)
            fscanf(in,"%d %d",&p[i].x,&p[i].y);

        fprintf(out,"Case #%d:\n",c);

        for (i=0; i<n; i++)
        {
            min = 0x7fffffff;
            for (j=0; j<n; j++)
            {
                if (i==j)
                    continue;

                l=0; r=0;
                for (k=0; k<n; k++)
                {
                    if (k==i || k==j)
                        continue;

                    x1 = p[k].x - p[i].x;
                    x2 = p[j].x - p[i].x;
                    y1 = p[k].y - p[i].y;
                    y2 = p[j].y - p[i].y;

                    v = x2*y1 - y2*x1;

                    if (v>0)
                        l++;
                    else if (v<0)
                        r++;
                }

                if (l==0 && r==0){

                    for (k=0; k<n; k++)
                    {
                        if (k==i)
                            continue;

                        x1 = p[k].x - p[i].x;
                        x2 = (p[j].y - p[i].y)*(-1);
                        y1 = p[k].y - p[i].y;
                        y2 = p[j].x - p[i].x;

                        v = x2*y1 - y2*x1;

                        if (v>0)
                            l++;
                        else if (v<0)
                            r++;
                    }

                }

                if (min>l)
                    min = l;
                if (min>r)
                    min = r;
            }

            if (n==1)
                min = 0;

            fprintf(out,"%d\n",min);
        }
    }

    return 0;
}
