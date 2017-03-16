#include<stdio.h>
#include<stdlib.h>

int gcd(unsigned long long int a, unsigned long int b)
{
  if (b == 0) return a;
  return gcd(b, a%b);
}

unsigned long long int lcm(unsigned long int *a, int n)
{
  unsigned long long int res = 1;
  int i;
  for (i = 0; i < n; i++) {
    res = res*a[i]/gcd(res, a[i]);
  }
  return res;
}

int main()
{
    int t,i,j,b,ans=0,freeb,empt;
    unsigned long int n,mint;
    unsigned long long int mult;
    unsigned long int *a,*rem;
    int num[1000];
    FILE *fp,*fp1;
    fp = fopen ("B-small-attempt3.in", "r");
    fp1 = fopen ("output.txt", "w+");

    fscanf(fp,"%d\n",&t);
    for(i=0;i<t;i++)
    {
        ans=0;
        fscanf(fp,"%d %lu\n",&b,&n);
        a=(unsigned long int *)malloc(b*sizeof(unsigned long int));
        rem=(unsigned long int *)malloc(b*sizeof(unsigned long int));

        for(j=0;j<b;j++)
        {
            fscanf(fp,"%lu",&a[j]);
            rem[j]=a[j];
        }

        mult=lcm(a,b);

        empt=0;
        for(j=0;j<b;j++)
        {
            empt+=(mult/a[j]);
        }
        n=(n%empt)+empt;
        if(n==0)
        {
            ans=b;
        }
        else
        {

        freeb=b;
        if(n<=freeb)
            ans=n;
        n-=freeb;
        freeb=0;
        }

        while(ans==0)
        {
            if(n<=freeb)
            {
                ans=num[n-1];
                break;
            }
            n-=freeb;
            freeb=0;

            mint=rem[0];

            for(j=0;j<b;j++)
            {
                if(rem[j]<mint)
                    mint=rem[j];
            }

            for(j=0;j<b;j++)
            {
                if(rem[j]-mint==0)
                {
                    num[freeb]=j+1;
                    freeb++;
                    rem[j]=a[j];
                }
                else
                    rem[j]-=mint;
            }

        }

        fprintf(fp1,"Case #%d: %d\n",i+1,ans);
    }

    return 0;
}
