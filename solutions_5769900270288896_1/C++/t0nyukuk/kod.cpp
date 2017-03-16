#pragma comment(linker,"/STACK:10000000")

//TC

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>

#define forn(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define forr(a,b,c) for(int (a)=(b);(a)>=(c);(a)--)
#define foreach(a,b) for( typeof( (b).begin() ) a=(b).begin(); (a)!=(b).end() ; (a)++ )
#define foreachr(a,b) for( typeof( (b).rbegin() ) a=(b).rbegin(); (a)!=(b).rend() ; (a)++ )
#define dg(x)  cerr <<#x<<':'<<x<<" "
#define dbg(x)  cerr <<#x<<':'<<x<<endl
#define SET(A,b) memset(A,b,sizeof (A) )
#define SIZE(A) ((int)(A).size())
#define ALL(A) (A).begin(),(A).end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define num(a) (1LL<<(a))
using namespace std;

typedef double dbl;
typedef long long Lint;
typedef pair<int,int> ii;
typedef pair<Lint,Lint> Lii;

const Lint mod = 1e9;

const int MAXN = 17;
const int powN = num(16)+1;

vector< vector<int> > ar;

int R,C,N;

int fill(int R,int C,int N,int t){

	forn(i,0,R-1)
		forn(j,0,C-1)
			if( N>0 && (i+j)%2==t )
				ar[i][j]=1,N--;

	if( !ar[0][C-1] && N>0 )
		ar[0][C-1]=1,N--;
	if( !ar[R-1][C-1] && N>0 )
		ar[R-1][C-1]=1,N--;
	if( !ar[R-1][0] && N>0 )
		ar[R-1][0]=1,N--;
	

	forn(i,0,C-1)
	{
		if( !ar[0][i] && N>0 )
			ar[0][i]=1,N--;
		if( !ar[R-1][i] && N>0 )
			ar[R-1][i]=1,N--;
	}

	forn(i,0,R-1)
	{
		if( !ar[i][0] && N>0 )
			ar[i][0]=1,N--;
		if( !ar[i][C-1] && N>0 )
			ar[i][C-1]=1,N--;
	}

	forn(i,0,R-1)
		forn(j,0,C-1)
			if(!ar[i][j] && N>0)
				ar[i][j]=1,N--;

	int rev=0;

	forn(i,0,R-1){
		forn(j,0,C-1)
			if( ar[i][j] )
			{
				if(i>0 && ar[i-1][j])
					rev++;
				if(j>0 && ar[i][j-1])
					rev++;
			}
	}

	forn(i,0,R-1)
		forn(j,0,C-1)
			ar[i][j]=0;

	return rev;

}

int main(){

	int T;

	scanf(" %d",&T);

	forn(test,1,T)
	{
		scanf("%d %d %d",&R,&C,&N);

		ar.resize(R);
		forn(i,0,R-1)
		{
			ar[i].resize(C);
			forn(j,0,C-1)
				ar[i][j]=0;
		}

		cout << "Case #" << test << ": " << min(fill(R,C,N,0),fill(R,C,N,1)) << endl;

		/*forn(i,0,R-1)
		{
			forn(j,0,C-1)
				printf("%d ",ar[i][j]);
			puts("");
		}*/

	}

	return 0;

}

