#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <cstdio>
 
#define FOR(i,x,y) for(int i=(x);i<(y);i++)
#define RFOR(i,x,y) for(int i=(x);i>=(y);i--)
#define ABS(x) ((x)>0?(x):-(x))
#define SQ(x) ((x)*(x))
#define mset(x,y) memset(x,y,sizeof(x))
#define INF 1000000000
#define MOD 1000000007
#define pb(X) push_back(X) 

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<double> vd;


int main()
{
	//#ifndef ONLINE_JUDGE
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    //#endif
    int t,r,c;
    int arr[10][10];
    scanf("%d",&t);
    for(int tt=0;tt<t;tt++)
    {
    	set<int> a1,a2;
    	scanf("%d",&r);
    	r--;
    	for(int i=0;i<4;i++)
    		for(int j=0;j<4;j++)
    			scanf("%d",&arr[i][j]);
    	for(int i=0;i<4;i++) a1.insert(arr[r][i]);

    	scanf("%d",&r);
    	r--;
    	for(int i=0;i<4;i++)
    		for(int j=0;j<4;j++)
    			scanf("%d",&arr[i][j]);
    	for(int i=0;i<4;i++) if(a1.find(arr[r][i])!=a1.end()) a2.insert(arr[r][i]);

    	if(a2.size()==0) printf("Case #%d: Volunteer cheated!\n",tt+1);
    	else if(a2.size()>1) printf("Case #%d: Bad magician!\n",tt+1);
    	else printf("Case #%d: %d\n",tt+1,*a2.begin());
    }
    return 0;
    
}