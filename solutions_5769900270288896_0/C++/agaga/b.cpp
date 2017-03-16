#include<cstdio>
using namespace std;
int tab[10005][10005];
int f ( int r, int c, int n )
{
  int sum = ( r*c + 1 ) / 2;
  if ( n <= sum ) return 0;
  int ans = r * ( c - 1 ) + c * ( r - 1 );
  int all = r * c;
  if ( n == all ) return ans;
  
  for ( int k = 4; k; k -- )
  {
	for ( int i = 1; i <= r; i ++ )
	  for ( int j = 1; j <= c; j ++ )
	  {
		sum = tab[i-1][j] + tab[i+1][j] + tab[i][j - 1] + tab[i][j + 1];
		if ( sum == k and tab[i][j] )
		{
		  ans -= k;
		  tab[i][j] = 0;
		  all --;
		  if ( n == all ) return ans;
		}
	  }
  }
  return ans;
}
int main ()
{
  int t;
  scanf ( "%d", &t );
  for ( int tt = 1; tt <= t; tt ++ )
  {
	int r, c, n;
	scanf ( "%d %d %d", &r, &c, &n );
	for ( int i = 0; i <= r + 1; i ++ )
	  for ( int j = 0; j <= c + 1; j ++ ) tab[i][j] = 0;
	  
	for ( int i = 1; i <= r; i ++ )
	  for ( int j = 1; j <= c; j ++ ) tab[i][j] = 1;
	printf ( "Case #%d: %d\n", tt, f(r,c,n) );
  }
}