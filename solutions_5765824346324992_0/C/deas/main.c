#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *in , *out;
    int count=0;
    if((in=fopen("B-small-attempt1.in","rt"))==NULL){
        printf("Cannot open in file exit!");
        exit(1);
    }
    if((out=fopen("Haircut.out","wt+"))==NULL){
        printf("Cannot open out file exit!");
        exit(1);
    }
    fscanf(in,"%d\n",&count);
    int i = 0;
    for(; i<count ;i++) {
        int b, n;
        int m[1000][2];
        int cB;
        fscanf(in,"%d %d\n", &b, &n);
        int j = 0;
        for(;j<b-1;j++) {
            fscanf(in, "%d ", &m[j][0]);
            m[j][1] = 0;
        }
        fscanf(in, "%d\n", &m[j][0]);
        m[j][1]=0;
        if(b == 1){
            fprintf(out, "Case #%d: 1\n", i+1);
            i++;
            continue;
        }
        int gcd = gcdfun(m[0][0], m[1][0]);
        for(j = 2;j<b;j++) {
            gcd = gcdfun(gcd, m[j][0]);
        }
        int mul = 1;
        for(j = 0;j<b;j++) {
            mul*=m[j][0];
        }
        mul/=gcd;
        int coun = 0;
        for(j = 0;j<b;j++) {
            coun += mul/m[j][0];
        }
        while(n > coun) {
            n-=coun;
        }
        for(j = 1;j <= n; j++) {
            int k=0;
            cB = k;
            for(;k<b;k++) {
                if(m[cB][1] > m[k][1]){
                    cB = k;
                }
            }
            int time = m[cB][1];
            for(k=0;k<b;k++) {
                m[k][1]-=time;
            }
            m[cB][1] = m[cB][0];
        }
        fprintf(out, "Case #%d: %d\n", i+1, cB+1);
    }
    fclose(out);
    fclose(in);
    return 0;
}

int gcdfun(int a, int b)
{
   if (a == 0)
        return b;
   if (b == 0)
       return a;
   if (a < b)
   {
      int tmp = a;
      a = b;
      b = tmp;
   }
   while (b != 0)
   {
      int tmp = a % b;
      a = b;
      b = tmp;
   }
  return a;
}
