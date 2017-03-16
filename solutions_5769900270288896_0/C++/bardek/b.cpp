#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

#define fru(j,n) for(int j=0;j<(n);++j)
#define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define x first
#define y second

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long LL;

const int MAXN = 1001;
int W[2][65][1<<16];
int main()
{
	int o;
	scanf("%d",&o);
	fru(oo,o)
	{
		 printf("Case #%d: ",oo+1);
		 int n,m,kk;
		 scanf("%d%d%d",&n,&m,&kk);
		 bool tu=1,pr=0;
		 int ma=1<<m;
		 int inf=1<<30;
		 fru(k,65)  fru(i,ma) W[pr][k][i]=inf;
		 W[pr][0][0]=0;
		 fru(ii,n) fru(jj,m){
			 fru(i,65) fru(j,ma) W[tu][i][j]=inf;
			 fru(i,65) fru(j,ma) if(W[pr][i][j]!=inf){
				int e=j;
				e|=1<<jj;
				e^=1<<jj;//wyzeruj jj-ty bit
				fru(w,2){
					e|=w<<jj;
					int q=W[pr][i][j];
					if(w && jj && (j&(1<<(jj-1)))) ++q;
					if(w && (j&(1<<jj))) ++q;
					W[tu][i+w][e]=min(W[tu][i+w][e],q);
//					printf("w =%d nowa to %d\n",w,e);
				}
			 }
			 swap(tu,pr);
		 }
		 int ret=inf;
		 fru(i,ma) ret=min(ret,W[pr][kk][i]);
		 printf("%d\n",ret);
	}
    return 0;
}
