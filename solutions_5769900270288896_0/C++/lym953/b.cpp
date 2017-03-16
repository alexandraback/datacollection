#include<iostream>
#include<set>
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<list>
#include<valarray>
#include<numeric>
#include<sstream>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define clr(a,val) memset(a,val,sizeof(a))
#define forn(i,n) for(int i=0;i<n;i++)
#define forv(i,v) forn(i,(v).size())
#define sz(v) v.size()
#define enter printf("\n")
#define space printf(" ")

typedef long long int LL;
typedef vector<int> VI;
typedef pair<int,int> pii;

int t,r,c,n;

int solve(int rr,int cc,int nn){
	if(nn<=(rr*cc+1)/2) return 0;
	
	if(rr==1) {
		int n1;
		if(cc%2==0) {
			n1=nn-cc/2;
			if(n1==1)
				return 1;
			else {
				n1--;
				return 2*n1+1;
			}
		}
		else {
			n1=nn-(cc+1)/2;
			return 2*n1;
		}
	}		

	int ans;
	int angle,side,center;
	if(rr%2==0 || cc%2==0) {
		ans=0;
		int n1=nn;
		angle=2;
		side=(rr+cc)-4;
		center=rr*cc/2 - angle - side;
		n1 -= rr*cc/2;

		if(n1<=2)
			return 2*n1;
		n1-=2;
		ans+=2*2;

		if(n1<=side)
			return ans+3*n1;
		n1-=side;
		ans+=3*side;

		return ans+4*n1;
	}
	else {
		int ans1=0,ans2=0;
		// +1
		int n1 = nn - (rr*cc+1)/2;
		side = (rr-3)+(cc-3);

		if(n1<=side)
			ans1= 3*n1;
		else {
			n1-=side;
			ans1 = 3*side+4*n1;
		}

		// -1
		n1= nn - (rr*cc-1)/2;
		side=(rr-3)+(cc-3);

		if(n1<=4)
			ans2=2*n1;
		else {
			n1-=4;
			ans2+=2*4;

			if(n1<=side)
				ans2 = ans2+3*n1;
			else {
				n1-=side;
				ans2+=3*side;

				ans2+= 4*n1;
			}
		}
		return min(ans1,ans2);
	}
}

int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("B-small-attempt2.out","w",stdout);
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++) {
		scanf("%d%d%d",&r,&c,&n);
		if(r>c){
			int tmp=r;
			r=c;
			c=tmp;
		} // r<=c
		printf("Case #%d: %d\n",ca,solve(r,c,n));
	}
	return 0;
}
