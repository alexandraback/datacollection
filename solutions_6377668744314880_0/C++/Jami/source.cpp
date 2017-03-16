#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>

using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid
#define clrgt rgt,mid+1,ed
#define inf (1<<29)
#define i64 long long
#define MX 1000002

typedef pair<int,int> pii;


struct point { // Creates normal 2D point
	i64 x, y;
	point() {}
	point( i64 xx, i64 yy ) { x = xx, y = yy; }
};

inline i64 sq_Distance( point a, point b ) {
	return ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y );
}


inline i64 isleft( point p0, point p1, point p2 ) {
	return( ( p1.x - p0.x ) * ( p2.y - p0.y ) - ( p2.x - p0.x ) * ( p1.y - p0.y ) );
}

// compare Function for qsort in convex hull
point Firstpoint;
int cmp(const void *a,const void *b) {
	i64 x,y;
	point aa,bb;
	aa = *(point *)a;
	bb = *(point *)b;
	x = isleft( Firstpoint, aa, bb );
	if( x > 0 ) return -1;
	else if( x < 0 ) return 1;
	x = sq_Distance( Firstpoint, aa );
	y = sq_Distance( Firstpoint, bb );
	if( x  < y ) return -1;
	return 1;
}


// 'P' contains all the points, 'C' contains the convex hull
// 'nP' = total points of 'P', 'nC' = total points of 'C'
void ConvexHull( point P[], point C[], int &nP, int &nC ) {
	int i, j, pos = 0; // Remove duplicate points if necesary
	for( i = 1; i < nP; i++ )
		if( P[i].y < P[pos].y || (  P[i].y == P[pos].y  && P[i].x > P[pos].x) )
			pos = i;
	swap( P[pos], P[0] );
	Firstpoint = P[0];
	qsort( P + 1, nP - 1, sizeof( point ), cmp );
	C[0] = P[0]; C[1] = P[1];
	i = 2, j = 1;
	while( i < nP ) {
		if( isleft( C[j-1], C[j], P[i] ) >= 0 ) C[++j] = P[i++];
		else j--;
	}
	nC = j + 1;
}

int nP,nC;
point P[4010],C[4010],tmp[4010];

bool check(int n,int idx){
    int i;
    C[n]=C[0];
    for(i=0;i<n;i++){
            if(C[i].x==P[idx].x && C[i].y==P[idx].y)return true;
            if(isleft(C[i],C[i+1],P[idx])==0)return true;
    }
    return false;
}

int func(int idx){
    int bt,ret=nP-1,cc,i;
    for(bt=0;bt<(1<<nP);bt++){
        if(!(bt&(1<<idx)))continue;
        cc=0;
        for(i=0;i<nP;i++){
            if(bt&(1<<i)){
                tmp[cc++]=P[i];
            }
        }
        ConvexHull(tmp,C,cc,nC);
        if(check(nC,idx))ret=min(ret,nP-cc);
    }
    return ret;
}

int main(){
    int cs,t=1,i,bt,mn;
    cin>>cs;
    while(cs--){
            cin>>nP;
            for(i=0;i<nP;i++)cin>>P[i].x>>P[i].y;
            printf("Case #%d:\n",t++);
            for(i=0;i<nP;i++)printf("%d\n",func(i));
    }

	return 0;
}


