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

int N,T,B;
int ar[MAXN];

Lint as[MAXN];
Lint as2[MAXN];

int main(){
	
	scanf("%d",&T);
	
	for( int Case=1 ; Case<=T ; Case++ ){
		
		scanf("%d%d",&B,&N);
		
		for( int i=1 ; i<=B ; i++ )
			scanf("%d",ar+i);
		
		Lint lo=1LL,hi=1e14,res,mi;
		
		while( lo<=hi ){
			
			mi=(lo+hi)/2LL;
			Lint cur=0LL;
			
			for( int j=1 ; j<=B ; j++ ){
				cur+=mi/ar[j];
				if( mi%ar[j] )
					cur++;
			}
			
			if( cur>=N ){
				res=mi;
				hi=mi-1;
			}
			else
				lo=mi+1;
		}
		
		Lint cur2=0LL;
			
		for( int j=1 ; j<=B ; j++ ){
				cur2+=(res-1)/ar[j];
				if( (res-1)%ar[j] )
					cur2++;
			}
		
		int cnt=N-cur2;
		
		for( int i=1 ; i<=B ; i++ ){
			if( ar[i]==1 || res%ar[i]==1 )
				cnt--;
			if(!cnt){
				printf("Case #%d: %d\n",Case,i);
				break;
			}
		}
	}
	
	return 0;
}
