#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
#include <cmath>
#include <list>
#include <map>
#include <set>

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define fill(x,y) memset((x),(y) ,sizeof(x))
#define type(x) __typeof(x.begin())
#define sz(x) x.size()
#define o ((f+l)/2)
#define umax(x,y) (x)=max((x),(y))
#define NEW(x) (x *)calloc(1,sizeof(x))
#define umin(x,y) (x)=min((x),(y));
#define tmax(x,y,z) max((x),max((y),(z))) 
#define tmin(x,y,z) min((x),min((y),(z))) 
#define PI (acos(-1)) 

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int Lint;
int N,er[5][5],we[5][5],used[20];

int main ()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&N);
	for( int k=1,a,b ; k<=N ; k++ ){
		scanf("%d",&a);
		for( int i=1 ; i<=4 ; i++ ) 
			for( int j=1 ; j<=4 ; j++ ) 
				scanf("%d",&er[i][j]);
		scanf("%d",&b);
		for( int i=1 ; i<=4 ; i++ ) 
			for( int j=1 ; j<=4 ; j++ ) 
				scanf("%d",&we[i][j]);
		
		int hm=0,ifOne=0;
		for( int i=1 ; i<=4 ; i++ )
			used[er[a][i]]=1;
		for( int i=1 ; i<=4 ; i++ )
			if( used[we[b][i]] ){
				hm++;
				ifOne=we[b][i];
			}
		for( int i=0 ; i<19 ; i++ )
			used[i]=0;
		if( !hm )
			printf("Case #%d: Volunteer cheated!\n",k);
		else if( hm==1 )
			printf("Case #%d: %d\n",k,ifOne);
		else 
			printf("Case #%d: Bad magician!\n",k);
		
	}


	
	return 0;
}
