#include <cstdio>
#include <cstring>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end() 
#define MAXN 20
using namespace std;
int K,M,N,S,res,vis;
int C[MAXN];
int A[MAXN][MAXN];
void rec(int x)
{
	if( x == K )
	{
		int i,j,sum(0);
		vis++;
		FOR2(i,K) A[ C[i]/N ][ C[i]%N ] = vis;
		
		FOR2(i,M)
			FOR2(j,N)
				if( A[i][j] == vis )
					sum += ( A[i][j+1] == vis ) + ( A[i+1][j] == vis );
		
		if( sum < res )
		{
			res = sum;
		}
		
		return;
	}
	int i;
	int bas = (x) ? C[x-1] + 1 : 0;
	for( i = bas; i < S; i++ )
	{
		C[x] = i;
		rec(x+1);
	}
}
int solve()
{
	scanf("%d %d %d" , &M , &N , &K );
	S = M * N;
	res = 2147000000;
	rec(0);
	return res;
}

int main()
{
	freopen( "input.txt" , "r" , stdin );
	freopen( "output.txt" , "w" , stdout );
	int T,i;
	
	scanf("%d" , &T );
	
	FOR(i,1,T)
		printf("Case #%d: %d\n" , i , solve() );
	
	return 0;
}
