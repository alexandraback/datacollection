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

const int MAXN=1024;
const int MAXM=1e4;

int N,M,T;
int ar[MAXN];

int main(){
	
	scanf("%d",&T);
	
	for( int Case=1 ; Case<=T ; Case++ ){
		
		scanf("%d",&N);
		
		for( int i=1 ; i<=N ; i++ )
			scanf("%d",ar+i);
		
		int fi=0,se=1e9;
		
		for( int i=2 ; i<=N ; i++ )
			if( ar[i]<ar[i-1] )
				fi+=ar[i-1]-ar[i];
		
		for( int i=0 ; i<=MAXM ; i++ ){
			
			int eaten=0;
			
			for( int j=1 ; j<N ; j++ ){
				eaten+=min(ar[j],i);
				if( ar[j]-min(ar[j],i)>ar[j+1] ){
					eaten=1e8;
					break;
				}
			}
			
			se=min(se,eaten);
		}
		
		printf("Case #%d: %d %d\n",Case,fi,se);
	}
	
	return 0;
}
