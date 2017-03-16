#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include<iomanip>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define pb push_back
#define sz size()
#define ln length()
#define fore(i,a,b) for(int i=a;i<b;i++)
#define fores(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%d",&a)
#define md 1000000007

int main() {
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	fore(z,0,t)
	{
		printf("Case #%d: ",z+1);
		int n;
		cin>>n;
		vector<ll> a;
		fore(i,0,n)
		{
		    ll tt;
		    cin>>tt;
		    a.pb(tt);
		}
		ll mi = 0,ma = 0;
		fore(i,0,n-1)
		{
		    if(a[i]>a[i+1])
                mi+=a[i]-a[i+1];
		}
		ll diff = 0;
		fore(i,0,n-1)
		{
		    if(a[i]<=a[i+1])
                continue;
            diff = max(diff,a[i]-a[i+1]);
		}
		ll cur = 0;
		fore(i,0,n-1)
		{
		    cur = a[i];
		    ma+=min(cur,diff);
		    cur = 0;
		}
		cout<<mi<<" "<<ma<<endl;
	}
	return 0;
}
