#include<iostream>
#include<fstream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<climits>
#include<ctime>
#include<sstream>
#define mp       	make_pair
#define pb       	push_back
#define st       	first
#define nd       	second
#define wait     	getchar();getchar();
#define lint     	long long
#define KARE(a)	 	( (a)*(a) )
#define MAX(a,b) 	( (a)>(b) ? (a) : (b) )
#define MIN(a,b) 	( (a)<(b) ? (a) : (b) )
#define MAX3(a,b,c)	( MAX( a,MAX(b,c) ) )
#define MIN3(a,b,c)	( MIN( a,MIN(b,c) ) )
#define FILL(ar,a)	memset( ar,a,sizeof ar )
#define oo	 		1e9
#define pii       	pair<int,int>
#define pll			pair<lint,lint>
#define pdd			pair<double,double>
#define y1			yy1
#define eps      	(1e-9)
#define esit(a,b)  	( abs( (a)-(b) ) < eps )
#define sol(a)		( (a)<<1 )
#define sag(a)		( sol(a)|1 )
#define orta(a,b)	( ( (a)+(b) )>>1 )
#define mxn       	105
using namespace std;

int id,test,n;
string str[mxn];

void read(){

	scanf( "%d" , &n );
	for( int i=1 ; i<=n ; i++ )		cin>>str[i];
	
	return;

}

string del( string s ){
	
	string ret;
	int i,j;
	
	for( i=0 ; i<s.size() ; i=j ){
		
		j = i+1;
		while( j<s.size() && s[j]==s[i] )	j++;
		
		ret += s[i];
		
	}
	
	return ret;
	
}

int count( string s , int r ){
	
	int i,j,cnt=0;
	
	for( i=0 ; i<s.size() ; i=j ){
		
		j = i+1;
		while( j<s.size() && s[j]==s[i] )	j++;
		
		if( cnt==r )	return j-i;
		cnt++;
		
	}
	
	return -1e7;
	
}

void solve(){
	
	int i,j,k,mn,ans=0;
	
	string rs = del( str[1] );
	
	for( i=2 ; i<=n ; i++ )
	if( del( str[i] ) != rs ){
		
		puts( "Fegla Won" );
		return;
		
	}
	
	for( i=0 ; i<rs.size() ; i++ ){
		
		vector<int>vec;
		
		for( j=1 ; j<=n ; j++ )		vec.pb( count( str[j] , i ) );
		
		mn = 1e9;
		
		for( j=1 ; j<=100 ; j++ ){
			
			int sum = 0;
			for( k=0 ; k<vec.size() ; k++ )		sum += abs( vec[k]-j );
			mn = MIN( mn,sum );
			
		}
		
		ans += mn;
		
	}
	
	printf( "%d\n" , ans );
	
	return;
	
}

int main(){
	
	freopen( "input.txt" , "r" , stdin );
	freopen( "output.txt" , "w" , stdout );
	scanf( "%d" , &test );
	for( id=1 ; id<=test ; id++ ){
		read();
		printf( "Case #%d: " , id );
		solve();
	}
	return 0;
}
