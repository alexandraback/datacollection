#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <deque>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <sstream>

#define For(i,a,n) for(int i =a ; i < n ; ++i )
#define all(x) (x).begin(),(x).end()
#define n(x) (int)(x).size()
#define pb(x) push_back(x)
#define fr first
#define sc second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 10000+10;
const ll inf = 1000ll*1000*1000ll+1000;
ll t;
ll r,c,n;
bool a[maxn][maxn];
int  adj(int i , int j){
	int ret = 0;
	if(i)
		ret+=a[i-1][j];
	if(j)
		ret+=a[i][j-1];

	if(i < r-1)
		ret+=a[i+1][j];
	if(j < c-1)
		ret+=a[i][j+1];
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	For(it,0,t){
		cout << "Case #" << it+1 << ": " ;
		cin >> r >> c >> n;
		if(n <= (r*c+1)/2){
			cout << 0 << endl;
			continue;
		}
		if (r > 2 && c > 2 && n >= (r*c)-((r-2)*(c-2)+1)/2){
			cout << r*(c-1)+(r-1)*c-4*(r*c-n) << endl;
			continue;
		}

		ll ans=inf;
		For(p,0,2){

			ll lans=0;
			ll rem=n;
			For(i,0,r)
				For(j,0,c)
					if(rem)
					{
						a[i][j]=((i+j)%2==p);
						if(a[i][j])
							rem--;
					}
			For(nu,0,4){
				For(i,0,r)
					For(j,0,c)
						if(rem && !a[i][j] && adj(i,j)==nu)
						{
							rem--;
							lans+=nu;
						}
			}
			
			ans=min(ans,lans);
		}
		cout << ans << endl;

	}
	return 0;
}

//
// el psy congroo
//

