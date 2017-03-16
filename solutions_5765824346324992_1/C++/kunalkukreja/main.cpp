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
#define md 100000000000007
int gcd(int m, int n)
{
	int temp = 0;
	if(m < n)
	{
		temp = 	m;
		m = n;
		n = temp;
	}
	while(n != 0)
	{
		temp = m % n;
		m = n;
		n = temp;
	}
	return m;
}
int main() {
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	fore(z,0,t)
	{
		printf("Case #%d: ",z+1);
		int b,n;
		cin>>b>>n;
		vi nos;
		fore(i,0,b)
		{
		    int tt;
		    cin>>tt;
		    nos.pb(tt);
		}
		ll low = 0,high = (ll)1000000000000007;
		ll ans = -1;
        while(low<=high)
        {
            int fa = -1;
            ll mid = (low+high)/2;
            ll totl = 0,toth = 0;
            //cout<<mid<<endl;
            fore(i,0,b)
            {
                toth+=(mid/nos[i])+1;
                //cout<<toth<<" ";
            }
            //cout<<endl;
            fore(i,0,b)
            {
                if(mid%nos[i]==0)
                    totl+=(mid/nos[i]);
                else
                    totl+=(mid/nos[i])+1;
                //cout<<totl<<" ";
            }
            //cout<<endl;
            bool yes = false;
            if(totl!=toth)
            {
                totl++;
                yes = true;
            }
            if(totl>n)
            {
                high = mid - 1;
                continue;
            }
            if(toth<n)
            {
                low = mid+1;
                continue;
            }
            bool found = false;
            if(yes)
            {
                fa = n-totl+1;
                fore(i,0,b)
                {
                    if(mid%nos[i]==0)
                    {
                        fa--;
                        if(fa==0)
                        {
                            ans = i+1;
                            found = true;
                            break;
                        }
                    }
                }
                if(found)
                    break;
            }
            else
                high = mid-1;;
        }
        cout<<ans<<endl;
	}
	return 0;
}
