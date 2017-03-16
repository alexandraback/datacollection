#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXR (10000+10)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}

int main()
{
//	freopen("B-small-attempt1.in","r",stdin);
//	freopen("B-small-attempt1.out","w",stdout);
	
	int T;
	cin>>T;
	For(kcase,T)
	{
		ll r,c,k;
		cin>>r>>c>>k;
		
		if (r<c) swap(r,c); 
		if (r%2==1&&c%2==0) swap(r,c);
		
		ll t1=r*c/2,S=r*c;
		ll t2=r*c-t1;
		
		if (t1>t2) swap(t1,t2);
		
		ll ans=0;
		ll k2=S-k;
		ll allsid=(r-1)*c+(c-1)*r;
			
		if (k<=t2) ans=0;
		else if (c==1)
		{
			ans=2*k2;
			ans=allsid-ans;
		}
		else 
		{
			
			if (r%2==0&&c%2==0)
			{
				ll p4=(r-2)*(c-2)/2,p3=r+c-4,p2=2;
				
				if (k2<=p4)
					ans=k2*4;
				else if (k2<=p4+p3)
					ans=p4*4+(k2-p4)*3;
				else 
					ans=p4*4+p3*3+(k2-p4-p3)*2;
				
				ans=allsid-ans;
			}
			else if (r%2==1&&c%2==1)
			{
				
					ll p4=(r-2)*(c-2)/2+1,p3=(r-2)/2*2+(c-2)/2*2,p2=4;
					
					if (k2<=p4)
						ans=k2*4;
					else if (k2<=p4+p3)
						ans=p4*4+(k2-p4)*3;
					else 
						ans=p4*4+p3*3+(k2-p4-p3)*2;
					ans=allsid-ans;
				
					{
						ll p4=(r-2)*(c-2)/2,p3=(r-2+1)/2*2+(c-2+1)/2*2,p2=0;
						ll ans2=0; 
						if (k2<=p4)
							ans2=k2*4;
						else if (k2<=p4+p3)
							ans2=p4*4+(k2-p4)*3;
						else 
							ans2=p4*4+p3*3+(k2-p4-p3)*2;
						ans2=allsid-ans2;
						
						ans=min(ans,ans2);
					}
									
			}
			else if (r%2==0&&c%2==1)
			{
				ll p4=(r-2)*(c-2)/2,p3=(r-2)+(c-2),p2=2;
				
				if (k2<=p4)
					ans=k2*4;
				else if (k2<=p4+p3)
					ans=p4*4+(k2-p4)*3;
				else 
					ans=p4*4+p3*3+(k2-p4-p3)*2;
				ans=allsid-ans;
			
			}
			
		}


		printf("Case #%d: %lld\n",kcase,ans);
	}
	
	
	return 0;
}

