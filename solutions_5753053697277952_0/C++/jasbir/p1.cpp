#include<cstdio>
#include<algorithm>
#include<string.h>
#include<map>
#include<vector>
#include<set>
#include<iostream>
#include<cmath>
using namespace std;
long long mod = 1000000007;

int ar[26];
int main()
{
	int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		for(int i=0;i<26;i++) ar[i] = 0;
		printf("Case #%d: ",tc);
	  int N; cin>>N;
	  int c=0;
	  for(int i=0;i<N;i++)
	  {
	  	cin>>ar[i]; c+=ar[i];
      }
	 
	 
	int h,sh;
	while(c)
	{
		
		
		h = 0;
	//	 printf("here\n");
		 
		for(int i=1;i<N;i++) if(ar[i]>ar[h]) h = i;
		
		if(c%2 == 1)
		{
			printf("%c ",'a'+h); c--;
			ar[h]--; continue;
		}
	//	 printf("N = %d c = %d\n",N,c);
		if(h==0) sh=1; else sh = 0;
		for(int i=0;i<N;i++)
		{
			//printf("inside i =%d sh = %d\n");
			 if(ar[i]>ar[sh]&& i != h) sh = i;
			 //printf("inside\n");
		}
	//	 printf("c1 = %d h = %d\n",c,h);
		if(ar[h]!=0) 
		{
			printf("%c",'a'+h); c--;
			ar[h]--;
		}
 // printf("c2 = %d sh = %d\n",c,sh);
		if(ar[sh]!=0) 
		{
			printf("%c",'a'+sh); c--; ar[sh]--;
		} printf(" ");
//	  printf("c3 = %d\n",c);
	  
		
	}
	printf("\n");
}
} 

