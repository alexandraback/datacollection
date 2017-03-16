#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *in , *out;
    int count=0;
    if((in=fopen("A-small-attempt1.in","rt"))==NULL){
        printf("Cannot open in file exit!");
        exit(1);
    }
    if((out=fopen("Mushroom.out","wt+"))==NULL){
        printf("Cannot open out file exit!");
        exit(1);
    }
    fscanf(in,"%d\n",&count);
    int i = 0;
    for(; i<count ;i++) {
        int n, maxc = 0;
        int m[1000];
        int r1=0, r2=0;
        fscanf(in,"%d\n", &n);
        int j = 0;
        for(;j<n-1;j++) {
            fscanf(in, "%d ", &m[j]);
        }
        fscanf(in, "%d\n", &m[j]);
        for(j=0;j<n-1;j++) {
            if(m[j] > m[j+1]){
                r1+=m[j]-m[j+1];
                if(m[j]-m[j+1] > maxc){
                    maxc = m[j]-m[j+1];
                }
            }
        }
        for(j = 0;j<n-1;j++) {
            if(m[j]<maxc){
                r2+=m[j];
            } else {
                r2+=maxc;
            }
        }
        fprintf(out, "Case #%d: %d %d\n", i+1, r1, r2);
    }
    fclose(out);
    fclose(in);
    return 0;
}
