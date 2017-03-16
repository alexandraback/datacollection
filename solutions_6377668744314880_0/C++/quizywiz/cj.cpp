#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;++i)
#define repi(i,a,b) for(int i=a;i<b;++i)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pii pair<long long int,long long int>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define vi vector<int>
#define sc(a) scanf("%d",&a)
#define lli long long int
#define INF 1000000000
int t,itt;
int n;
pii a[1001];
bool used[1001];
bool notthere[1001];
int ans[1001];
pii c[1001];
void convexHull()
{
		int p=-1;
		repi(i,0,n)if(!notthere[i])p=i;
        if(p==-1)return;
        repi(i,0,n)used[i]=false;
        repi(i,1,n)
        {
            if(a[i] < a[p] && !notthere[i])
                p = i;
        }
        int start = p;
        do
        {
            lli k = -1;
            lli dist = INF;
            repi(i,0,n){
            if(i==p)continue;
                if(used[i] || notthere[i])continue;
                if(k == -1)k = i;
                pii te1 = mp(a[i].first-a[p].first,a[i].second-a[p].second);
                pii te2 = mp(a[k].F-a[p].F,a[k].S-a[p].S);
                lli cross = te1.F*te2.S - te1.S*te2.F;

                lli d = te1.F*te1.F + te1.S*te1.S;
                if(cross < 0){
			         k = i;
                    dist = d;
                }else if(cross == 0){
                   if(d < dist){
                        dist = d;
                        k = i;
                    }
                }
            }
            p = k;
            used[p] = true;
        }while(start!=p);
    }
void solve(int i=0)
{
	
	if(i==n)
	{
	//	repi(i,0,n)cout<<(!notthere[i]?"1 ":"0 ");
	//	cout<<endl;

		int numn = 0;
		repi(i,0,n)if(!notthere[i])numn++;
		convexHull();
		repi(i,0,n)if(used[i])ans[i] = min(ans[i],n-numn);
		return;
	}
	else
	{
		notthere[i]=false;
		solve(i+1);
		notthere[i]=true;
		solve(i+1);
	}
	
}
int main() 
{
	// your code goes here
	sc(t);
	rep(itt,1,t+1)
	{
		cout<<"Case #"<<itt<<": ";
		cin>>n;
		repi(i,0,n)
		{
			cin>>a[i].first>>a[i].second;
			ans[i]=n+10;
		}

		cout<<"h"<<endl;
		solve(0);
		repi(i,0,n)cout<<ans[i]<<endl;
	}
	return 0;
}