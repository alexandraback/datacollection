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
		int lcm = nos[0];
		fore(i,1,b)
		{
		    int gcdf = gcd(lcm,nos[i]);
		    lcm = (lcm/gcdf)*nos[i];
		}
		//cout<<lcm<<endl;
		vi cust;
		cust.pb(-1);
		fore(i,1,b+1)
            cust.pb(i);
        fore(i,1,lcm)
        {
            fore(j,0,b)
            {
                if(i%nos[j]==0)
                    cust.pb(j+1);
            }
        }
        int tot = cust.sz;
        tot--;
        cust[0] = cust[tot];
        n%=tot;
        cout<<cust[n]<<endl;
	}
	return 0;
}
