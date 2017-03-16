#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int main(){
	int t;
	scanf("%d",&t);
	rep1(ppp,t){
		printf("Case #%d: ",ppp);
		int r,c,n;
		scanf("%d%d%d",&r,&c,&n);
		//printf("%d %d %d\n",r,c,n);
		if(r == 1){
			printf("%d\n",max(2*n-c-1,0));
		}
		else if(c == 1){
			printf("%d\n",max(2*n-r-1,0));
		}
		else if(r%2 == 0 || c%2 == 0){
			if(n <= (r*c)/2){
				puts("0");
			}
			else if(r*c-n <= ((r-2)*(c-2))/2){
				printf("%d\n",2*r*c-r-c-4*(r*c-n));
			}
			else if(n >= (r*c)/2+2){
				printf("%d\n",4+3*(n-((r*c)/2+2)));
			}
			else {
				printf("%d\n",2*(n-(r*c)/2));
			}
		}
		else {
			if(n <= (r*c+1)/2){
				puts("0");
			}
			else if(n >= (r*c-5)/2+r+c){
				printf("%d\n",2*r*c-r-c-4*(r*c-n));
			}
			else if(n >= (r*c+7)/2){
				printf("%d\n",8+3*(n-(r*c+7)/2));
			}
			else if(n == (r*c+5)/2){
				puts("6");
			}
			else {
				puts("3");
			}
		}
	}
}
