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

const int MAXN = 210;

string str[MAXN];

vector<char> pro;

int S[MAXN][MAXN],Mx[MAXN];

int kont(int k,vector<char> &pro){
	
	int j=0;
	
	//~ puts("1");
	
	forn(i,0,SIZE( str[k] )-1)
	{
		//~ printf("%c %c\n",str[k][i],pro[j]);
		if(pro[j]!=str[k][i]){
			//~ dbg(S[k][j]);
			if( S[k][j]==0 )
				return 0;
			j++;
			i--;
		}
		else
		{
			S[k][j]++;
			Mx[j]=max(Mx[j],S[k][j]);
		}
	}
	//~ puts("1");
	
	//~ dbg(j);
		
	if( j<SIZE(pro)-1 )	return 0;
	
	//~ puts("1");
	
	return 1;
	
}

int main(){
	
	int n;
	
	int mn,tmp,res=0;
	
	int T;
	
	scanf(" %d",&T);
	
	forn(test,1,T){
		
		printf("Case #%d: ",test);
		
		SET(S,0);
		SET(Mx,0);
		pro.clear();
		
		scanf(" %d",&n);
		
		forn(i,1,n)
			cin >> str[i];
		
		forn( i,0,SIZE(str[1])-1 )
			if(i==0 || *pro.rbegin()!=str[1][i] )
				pro.pb(str[1][i]);
		
		forn(i,1,n)
			if( !kont(i,pro) )
			{
				printf("Fegla Won\n");
				goto end;
			}
		
		res=0;
		
		forn(i,0,SIZE(pro)-1)
		{
			mn=1e9;
			forn(j,1,Mx[i]){
				tmp=0;
				forn(t,1,n)
					tmp+=abs( j-S[t][i] );
				mn=min(mn,tmp);
			}
			//~ dbg(mn);
			res+=mn;
		}
		
		printf("%d\n",res);
					
		
		end:;
	}
	
	return 0;
	
}
