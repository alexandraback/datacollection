#include "cstdio"
#include "iostream"
#include "vector"
#include "algorithm"
#include "cstring"
#include "set"
#include "map"
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define rep(i, n) for(int i=0; i<n; i++)
#define repp(i, a, b) for(int i=a; i<a+b; i++)
using namespace std;
inline int getint(){
  char c = getchar();
  for(;c<'0'||c>'9';) c = getchar();
  int x = 0;
  for(;c>='0' && c<='9'; c = getchar()) x*=10, x+=c-'0';
  return x;
}
const int maxn = 100010, maxm = 1000010;
int n,m,k,a[100],x;
int main(int argc, char const *argv[])
{
	int cass = getint();
	repp(cas,1,cass){
		memset(a, 0, sizeof(a));
		n = getint();
		n--; 
		rep(i, 4)rep(j, 4){
			x = getint();
			if(i==n){
				a[x] = 1;
			}
		}
		n = getint();
		n--;
		m = 0;
		rep(i, 4)rep(j, 4){
			x = getint();
			if(i==n && a[x]){
				m+=a[x], k = x;
			}
		}
		printf("Case #%d: ", cas);
		if(m==1) printf("%d\n", k);
		if(m==0) printf("Volunteer cheated!\n");
		if(m>1) printf("Bad magician!\n");
	}
	return 0;
}