#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctype.h>
#include <stack>
#include <queue>
#include <limits.h>
#include <fstream>
#include <map>
#include <set>

#define rep(i, a) for(long long int i = 0; i < a; i++)
#define rep1(i, a) for(long long int i = 1; i <= a; i++)
#define fo(i, a, b) for(long long int i = a; i < b; i++)
#define defo(i, a, b) for(long long int i = a; i >= b; i--)
#define ll long long
#define Int long long int
#define pr(i) printf("Case #%lld: ",i)
#define pb push_back
#define sz(a) ((long long int)(a.size()))
#define x first
#define y second
#define mp make_pair
#define SET(x, a) memset(x, a, sizeof(x));
#define pi  3.1415926535897
#define mod 1000000007
using namespace std;
struct node {
	int val;
	pair<int,int> p;
};
/*int main(){
	//freopen("input.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m,ans = 0,per;
	scanf("%d%d%d",&n,&m,&pe);
	pe = (n*m)-pe;
	set<struct node> s;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(i==0||i==n-1){
				if(j==0||j==m-1){
					pair<int,int> pa;
					pa.x = i;
					pa.y = j;
					struct node st;
					st.p = pa;
					st.val = 2;
					ans+=2;
					s.insert(st);
				}
				else{
					pair<int,int> pa;
					pa.x = i;
					pa.y = j;
					struct node st;
					st.p = pa;
					st.val = 3;
					ans+=3;
					s.insert(st);
				}
			}
			else if(j==0||j==m-1){
				pair<int,int> pa;
				pa.x = i;
				pa.y = j;
				struct node st;
				st.p = pa;
				st.val = 3;
				ans+=3;
				s.insert(st);
			}
			else{
				pair<int,int> pa;
				pa.x = i;
				pa.y = j;
				struct node st;
				st.p = pa;
				st.val = 4;
				ans+=4;
				s.insert(st);
			}
		}
	}
	while(pe--){

	return 0;
}*/
int r,c,p;
int ans = -1;
int vis[20][20];int co = 0;
void rec(int i1,int i2,int pe,int val){
	//cout<<co<<"\n";
	if(i1==r-1&&i2==c-1){
		int in = i1;
		int jn = i2;
		if(pe==p-1){
			int c1 = 0;
			if(in-1>=0&&vis[in-1][jn]==1){
				c1++;
			}
			if(jn-1>=0&&vis[in][jn-1]==1){
				c1++;
			}
			if(in+1<r&&vis[in+1][jn]==1){
				c1++;
			}
			if(jn+1<c&&vis[in][jn+1]==1){
				c1++;
			}
			//cout<<c1<<"\n";
			val = val+c1;
			if(ans==-1){
				ans = val;
			}
			else{
				ans = min(ans,val);
			}
			return;
		}
		if(pe!=p){
			return;
		}
		if(ans==-1){
			ans = val;
			return;
		}
		ans = min(ans,val);
		return;
	}
	int jn = i2,in = i1;
	int c1 = 0;
	int ip,jp;
	jp = jn+1;
	ip = in;
	if(jp==c){
		jp = 0;
		ip++;
	}
	rec(ip,jp,pe,val);
	if((in-1)>=0&&vis[in-1][jn]==1){
		c1++;
	}
	if((jn-1)>=0&&vis[in][jn-1]==1){
		c1++;
	}
	if((in+1)<r&&vis[in+1][jn]==1){
		c1++;
	}
	if((jn+1)<c&&vis[in][jn+1]==1){
		c1++;
	}
	vis[in][jn] = 1;
	rec(ip,jp,pe+1,val+c1);
	vis[in][jn] = 0;
	return;
}
int main(){
	freopen("ab.in","r",stdin);
	freopen("out.txt","w",stdout);
	int test;
	cin>>test;
	Int l = 0;
	while(test--){
		ans = -1;
		memset(vis,0,sizeof(vis));
		l++;
		cin>>r>>c>>p;
		rec(0,0,0,0);
		pr(l);
		cout<<ans<<"\n";
	}
	return 0;
}
