#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int b,n;
int m[5];
int taken[5];

int gcd(int a, int b)
{
  if(a>b) return gcd(b,a);
  if(a==0) return b;
  return gcd(a, b%a);
}
	    
int main()
{
    int nb_cas;
    scanf("%d", &nb_cas);
    for(int cas = 1; cas <= nb_cas; cas++)
    {
	printf("Case #%d:",cas);
	//enter code here
	scanf("%d%d",&b,&n);
	ull ppcm = 1LL;
	for(int i=0;i<b;i++)
	  {
	    scanf("%d",&m[i]);
	    ppcm = ppcm * ((ull) m[i]) / gcd((int)ppcm,m[i]);
	  }
	//fprintf(stderr,"ppcm %lld\n",ppcm);
	int nserved = 0;
	for(int i=0;i<b;i++)
	  nserved+=ppcm/m[i];
	n = (n % nserved == 0)?nserved:(n%nserved);
	int time=0;
	for(int i=0;i<b;i++)taken[i]=0;
	for(int c = 0;c<n;c++)
	  {
	    int tmin = ppcm+10;
	    for(int i=0;i<b;i++)
	      tmin=min(tmin,taken[i]);
	    for(int i=0;i<b;i++)
	      if(taken[i]==tmin)
		{
		  taken[i]+=m[i];
		  if(c==n-1)
		    printf(" %d\n",i+1);
		  break;
		}
	    time = tmin;
	  }
    }
    return 0;
}
