#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int M[100000];
int Moccupy[100000];

int GCD( int a, int b )
{
  int c;
  while ( a != 0 ) 
  {
     c = a;
     a = b%a;
     b = c;
  }
  return b;
}

int LCM(int a,int b)
{
	return a*b/GCD(a,b);
}



int main()
{
	int temp,temp2;
	int T,B;
	long int N;
	int lcmValue;
	int LCMcustomer;
	
	scanf("%d",&T);

	for(temp = 0 ; temp != T ; temp++)
	{
		scanf("%d",&B);
		scanf("%ld",&N);

		for(temp2 = 0 ; temp2 != B ; temp2++)
		{
			scanf("%d",&M[temp2]);
			Moccupy[temp2] = 0;
		}
		
		lcmValue = M[0];
		for(temp2 = 1 ; temp2 != B ; temp2++)
		{
			lcmValue = LCM(lcmValue,M[temp2]);
		}

		LCMcustomer = 0;
		for(temp2 = 0 ; temp2 != B ; temp2++)
		{
			LCMcustomer += lcmValue/M[temp2];
		}

		N = N % LCMcustomer;
		if(N == 0)
			N = LCMcustomer;
		while(N!=0)
		{
			//printf("before #%ld: %d\n",N,temp2);
			for(temp2 = 0 ; temp2 != B ; temp2++)
			{
				if(Moccupy[temp2] == 0)
				{
					Moccupy[temp2] = M[temp2];
					N--;
				}

				if(N==0)
				{
					break;
				}
			}
			//printf("after #%ld: %d\n",N,temp2);
			if(N==0)
			{
				break;
			}

			for(temp2 = 0 ; temp2 != B ; temp2++)
				--Moccupy[temp2];
		}

		printf("Case #%d: %d\n",temp+1,temp2+1);
	}/**/
	
	return 0;
}
