#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ull;

int b,n;
int m[1000];

int isvalid(ull t)
{
  if(t==0LL && n <= b) return n-1;
  if(t==0LL) return -1; //t too small

  ull prevcut = 0LL;
  for(int i=0;i<b;i++)
    prevcut += 1LL + (t-1LL)/((ull)m[i]);
  if(prevcut >= (ull)n) return -2;//t too big
  for(int i=0;i<b;i++)
    {
      if(t%((ull)m[i])==0LL)
	{
	  prevcut++;
	  if(prevcut==((ull)n))
	      return i;
	}
    }
  return -1;
}

int dicho(ull a, ull b)
{
  ull m = (a+b)/2;
  //printf("m %lld\n",m);
  int isv = isvalid(m);
  if(isv==-1)
    return dicho(m,b);
  else if(isv==-2)
    return dicho(a,m);
  else
    return isv;
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
	    scanf("%d",&m[i]);	  
	printf(" %d\n",1+dicho(-1LL,1LL<<52));
	
    }
    return 0;
}
