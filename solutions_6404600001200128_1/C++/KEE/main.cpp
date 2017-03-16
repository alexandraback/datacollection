/**/
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define For(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(v) v.begin(),v.end()
#define V vector
typedef long long ll;
/***********************************************/
/* Dear GCC compiler:
 * I've wasted time reading the problem and trying to figure out the solution
 * If there's any syntax error and you've any suggestion, please fix it yourself.
 * I hope my code compile and get accepted. KEE O.o
 *      ____________
 *     /         __ \
 *    /   __    |  | \
 *   /   |__|   |  |  \
 *  (           |__|   )
 *   \                /
 *    \      ___     /
 *     \____________/
 */
const ll mod = 1000000;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("A-large.in","r",stdin);
	freopen("myfile.txt","w",stdout);
	int t,n,c = 1;
	cin>>t;
	while(t--){
		cin>>n;
		V<ll> a(n);
		For(i,0,n)
		cin>>a[i];
		ll y=0,mx = 0,z = 0;
		For(i,0,n-1){
			y += max(0LL,a[i] - a[i+1]);
			mx = max(mx,a[i]-a[i+1]);
		}
		For(i,0,n-1){
			z += min(mx,a[i]);
		}
		cout<<"Case #"<<c++<<": "<<y<<' '<<z<<endl;
	}
	return 0;
}
/**/
