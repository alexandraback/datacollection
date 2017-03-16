#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;


int t[2000];
	    
int main()
{
    int nb_cas;
    scanf("%d", &nb_cas);
    for(int cas = 1; cas <= nb_cas; cas++)
    {
	printf("Case #%d:",cas);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  scanf("%d",&t[i]);
	int fm = 0;
	for(int i=1;i<n;i++)
	  fm+=max(0,t[i-1]-t[i]);
	int smrate = 0;
	for(int i=1;i<n;i++)
	  smrate = max(smrate,t[i-1]-t[i]);
	int sm=0;
	for(int i=1;i<n;i++)
	  sm+=min(smrate,t[i-1]);
	printf(" %d %d\n",fm,sm);
	//enter code here
    }
    return 0;
}
