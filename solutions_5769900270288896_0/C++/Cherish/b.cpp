#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < n; ++i)
#define Rep(i,n) for(int i = 1; i <= n; ++i)

int main()
{
	int t,cas=0;
	cin>>t;
	while(cas++ < t){
		int n,r,c,ans;
		cin>>r>>c>>n;
		if(r>c)swap(r,c);{
			if(r==1){
				if(n<=(c+1)/2){
					ans=0;
				}
				else {
					if(c%2==0&&n==c/2+1)ans=1;
					else ans=2*n-c-1;
				}
			}
			else if(r==2){
				if(n<=c){
					ans=0;
				}
				else {
					if(n<=c+2)ans=2*(n-c);
					else ans=3*(n-c-2)+4;
				}
			}
			else if(r==3){
				if(c==3){
					if(n<=5)ans=0;
					else if(n==8)ans=8;
					else ans=(n-5)*3;
				}
				else if(c==4){
					if(n<=6)ans=0;
					else if(n<=8)ans=2*(n-6);
					else if(n==12)ans=17;
					else ans=(n-7)*3+1;
				}
				else if(c==5){
					if(n<=8)ans=0;
					else if(n<=10)ans=3*(n-8);
					else if(n==11)ans=8;
					else if(n<=13)ans=3*(n-9)+2;
					else ans=4*(n-10)+2;
				}
			}
			else {
				if(n<=8)ans=0;
				else if(n<=10)ans=2*(n-8);
				else if(n>=15)ans=4*(n-10);
				else ans=3*(n-10)+4;
			}
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}

