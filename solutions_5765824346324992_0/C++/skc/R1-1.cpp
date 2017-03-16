#include "stdio.h"

#if 1

#define F	"B-small-attempt1"
#ifndef F
#define TEST	1
#define F	"B"
#endif
//#define TEST	1

#define P	printf

#define N	1000

int s[N+1];

int hcf_function(int m,int n)
{
    int temp,remainder;
    if(m<n)
    {
        temp=m;
        m=n;
        n=temp;
    }
    while(1)
    {
            remainder=m%n;
            if(remainder==0)
            return n;
            else
            m=n;
            n=remainder;
    }
}

int lcm_function(int m,int n)
{

    int lcm;
    lcm=m*n/hcf_function(m,n);
    return lcm;
}

int main(void)
{
	freopen("IO/"F".in","r",stdin);
#ifndef TEST
	freopen("IO/"F".out.txt","w",stdout);
#endif
	int t,tst;
	scanf("%d", &tst);
	for(t=1 ; t<=tst ; ++t)
	{
		int b,n,i,j,c,m,sum,lcm;
		scanf("%d %d", &b, &n);
		scanf("%d", &s[0]);
		lcm = s[0];
#ifdef TEST
		P("%d %d\n%d ", b, n,lcm);
#endif
		for(i=1 ; i<b ; ++i)
		{
			scanf("%d", &s[i]);
#ifdef TEST
			P("%d ", s[i]);
#endif
			lcm=lcm_function(lcm,s[i]);
		}

		m = 0;
		for(i=0 ; i<b ; ++i)
			m += lcm/s[i];

		n--;
		n %= m;
#ifdef TEST
		P("\n%d %d %d\n",lcm,m,n);
#endif
		if(n < b)
			n++;
		else
		{
			c = 0;
			while(1)
			{
				for(i=0 ; i<b ; ++i)
				{
					if(!(c%s[i]))
					{
						if(!(n))
							goto DOWN;
						n--;
					}
				}
				c++;
			}
DOWN:
			n = i+1;
		}

		P("Case #%d: %d\n",t,n);
	}
	return 0;
}



#if 0
#define SIZE N

int main2()
{
     int array[SIZE],n,i,choice,lcm,hcf;
     printf("Enter No of Elements\n");
     scanf("%d",&n);
     printf("Enter Elements\n");
     for(i=0;i<n;i++)
     scanf("%d",&array[i]);
     do
     {
           printf("\n\nEnter Choice\n\n1.HCF\n2.LCM\n3.Exit\n");
           scanf("%d",&choice);
           switch(choice)
           {

                      case 1:
                      hcf=array[0];
                      for(i=1;i<n;i++)
                      hcf=hcf_function(hcf,array[i]);
                      printf("\nHCF = %d",hcf);
                      break;

                      case 2:
                      lcm=array[0];
                      for(i=1;i<n;i++)
                      lcm=lcm_function(lcm,array[i]);
                      printf("\nLCM = %d",lcm);
                      break;

                      case 3:
                      break;
                      default:
                      printf("Wrong Choice");
           }
    }while(choice!=3);
}
#endif
#endif


