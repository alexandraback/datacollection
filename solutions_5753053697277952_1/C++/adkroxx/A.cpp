#include<bits/stdc++.h>

#define MOD 1000000007
#define MAX 100005
#define ll long long
#define slld(t) scanf("%lld",&t)
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)
#define plld(t) printf("%lld\n",t)
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define mp(a,b) make_pair(a,b)
#define FF first
#define SS second
#define pb(x) push_back(x)
#define vi vector<int>

using namespace std;

int p[27];

int main(){
//	freopen("A-small-attempt0.in","r",stdin);
//	freopen("A1.out","w",stdout);
//	
	freopen("A-large.in","r",stdin);
	freopen("A2.out","w",stdout);

	int t;
	sd(t);
	for(int tt=1;tt<=t;tt++){
		
		int n;
		sd(n);
		
		int mx=0;
		
		for(int i=1;i<=n;i++){
			sd(p[i]);
			mx+=p[i];
		}
		cout<<"Case #"<<tt<<": ";
		
		while(mx!=0){
			mx--;
			
			bool ok=0;
			
			for(int j=1;j<=n;j++){
				if(p[j]){
					p[j]--;
					int s=0;
					for(int x=1;x<=n;x++) s=max(s,p[x]);
					if(2*s>mx){
						p[j]++;
						continue;
					}
					else{
						cout<<char('A'+(j-1))<<" ";ok=1;break;
					}
				}
			}
			
			if(ok) continue;
			
			mx--;
			
			bool flag=0;
			
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j){
						if(p[i]!=2) continue;
					}
					if(p[i]&&p[j]){
						p[i]--;p[j]--;
						
						int s=0;
						for(int x=1;x<=n;x++) s=max(s,p[x]);
						
						if(2*s>mx){
							p[i]++;p[j]++;continue;
						}
						else{
							cout<<char('A'+(i-1))<<char('A'+(j-1))<<" ";flag=1;break;
						}
					}
				}
				if(flag) break;
			}
		}
		
		cout<<endl;
	}
}
