#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>

#define fi first
#define se second
#define pb push_back
#define sz(a) ((int)a.size())
#define dist(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))

using namespace std;

typedef long long int Lint;
typedef pair<int,int> ii;

const int MAXN=22;

int N,T,R,C,res=1e8;

bool ar[MAXN][MAXN];

inline void dfs( int r , int c , int cur ){
	
	if( !cur || (r==R+1 && c==1 && !cur ) ){
		
		int sum=0;
		
		for( int i=1 ; i<=R ; i++ )
			for( int j=1 ; j<=C ; j++ ){
				
				if( ar[i][j] && ar[i+1][j] )
					sum++;
				if( ar[i][j] && ar[i-1][j] )
					sum++;
				if( ar[i][j] && ar[i][j+1] )
					sum++;
				if( ar[i][j] && ar[i][j-1] )
					sum++;
			}
		
		res=min(res,sum/2);
		return;
	}
	
	if( r>R || c>C )
		return;
	
	ar[r][c]=1;
	if( c==C )
		dfs(r+1,1,cur-1);
	else
		dfs(r,c+1,cur-1);
	
	ar[r][c]=0;
	if( c==C )
		dfs(r+1,1,cur);
	else
		dfs(r,c+1,cur);
}

int main(){
	
	scanf("%d",&T);
	
	for( int Case=1 ; Case<=T ; Case++ ){
		
		scanf("%d%d%d",&R,&C,&N);
		
		dfs(1,1,N);
		
		printf("Case #%d: %d\n",Case,res);
		res=1e8;
	}
	
	return 0;
}
