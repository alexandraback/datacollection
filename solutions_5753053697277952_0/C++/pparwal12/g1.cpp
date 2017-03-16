#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int > pii;
typedef pair<int,pii > piii;
//input
#define sc1(x) scanf("%d",&x);
#define sc2(x,y) scanf("%d%d",&x,&y);
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z);

/*
#define sc1(x) scanf("%lld",&x);
#define sc2(x,y) scanf("%lld%lld",&x,&y);
#define sc3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z);
*/

#define pb push_back
#define mp make_pair
#define ini(x,val) memset(x,val,sizeof(x));

#define fs first
#define sc second

//some constants
#define MOD 1000000007
#define inf 99999999
#define linf 99999999999999999ll	//long long inf
#define PI 3.1415926535897932384626
const double eps=0.000000000000001 ;

#define gcd __gcd
#define tr(container, it)  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define all(v) v.begin(),v.end()

#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";

#define LIM 100005

int main(int argc, char const *argv[])
{
	int t,temp;
	sc1(t);
	temp=t;
	while(t--)
	{

		int i,j,n;
		sc1(n);
		int sum=0;;
		pii p[50];
		for(i=0;i<n;++i)
		{
			int x;
			sc1(x);
			p[i]=mp(x,i);
			sum+=x;
		}
		printf("Case #%d: ",temp-t);
		
		for(i=0;sum>0;++i)
		{
		/*	for(j=0;j<n;++j)
			{
				printf("%d ",p[j].fs);
			}
			cout<<"\n";
*/			sort(p,p+n);
			int x,y,a,b;

			
			x=p[n-1].fs;
			y=p[n-2].fs;
			/*printf("\nhi\n");
			debug2(x,y);
			debug(sum);
*/			
			if(sum==3)
			{
				a=p[n-1].sc;
				p[n-1].fs--;
				printf("%c ",a+'A');
				sum--;
			}
			else
			if(x==y)
			{
				a=p[n-1].sc;
				b=p[n-2].sc;
				p[n-1].fs--;
				p[n-2].fs--;
				printf("%c%c ",a+'A',b+'A');
				sum-=2;
			}
			else if(x>y+1)
			{
				a=b=p[n-1].sc;
				p[n-1].fs-=2;
				printf("%c%c ",a+'A',b+'A');
				sum-=2;
			}
			else 
			{
				a=p[n-1].sc;
				p[n-1].fs--;
				printf("%c ",a+'A');
				sum--;
			}	

		}
		printf("\n");
	}	
	return 0;
}