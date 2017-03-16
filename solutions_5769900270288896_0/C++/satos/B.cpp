#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reg(i,a,b) for(int i=(a);i<=(b);i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=(b);i>=(a);i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX



int main(void){
	int qn;
	scanf("%d",&qn);
	reg(qq,1,qn){
		int w,h,n;
		scanf("%d%d%d",&w,&h,&n);
		int s=w*h;
		int haf=(s+1)/2;
		int ans=0;
		for(;;){
			if(n<=haf)break;
			n-=haf;
			
			if(w+h<=3){
				if(w*h==1)break;
				if(w*h==2 && n==2){
					ans=1;
					break;
				}
			}
			if(w>h)swap(w,h);
			if(w==1){
				ans=max(0,n*2);
				if(h%2==0)ans--;
				break;
			}
			
			if((w*h)%2==0){
				ans+=min(n,2)*2; n-=2;
				if(n<=0)break;
				int wn=w+h-4;
				ans+=min(n,wn)*3; n-=wn;
				if(n<=0)break;
				ans+=n*4;
				break;
			}
			else{
				int a1=0,a2=0;
				int n1=n,n2=n;
				
				a1+=max(0,min(n1,w+h-2))*3; n1-=(w+h-2);
				a1+=max(0,n1)*4;
				
				n2++;
				a2+=max(0,min(n2,4))*2; n2-=4;
				a2+=max(0,min(n2,w+h-6))*3; n2-=(w+h-6);
				a2+=max(0,n2)*4;
				
				ans=min(a1,a2);
			}
		}
		
		
		printf("Case #%d: %d\n",qq,ans);
	}
	return 0;
}




