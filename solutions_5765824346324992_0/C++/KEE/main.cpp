/**/
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define For(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(v) v.begin(),v.end()
#define V vector
typedef unsigned long long ll;
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
	freopen("B-small-attempt0.in","r",stdin);
	freopen("myfile.txt","w",stdout);
	int t,c = 1;
	cin>>t;
	while(t--){
		int B,N;
		cin>>B>>N;
		if(N == 1){
			cout<<"Case #"<<c++<<": "<<1<<endl;
			continue;
		}
		V<ll> b(B);
		For(i,0,B)
		cin>>b[i];
		ll lcm = 1;
		For(i,0,B)
		lcm = (lcm * b[i])/__gcd(lcm,b[i]);
		ll num = 0;
		For(i,0,B)
		num += lcm/b[i];
		N=(N-1)%num;
		if(N == 0){
			cout<<"Case #"<<c++<<": "<<1<<endl;
			continue;
		}
		int cur = 1;
		V<int> busy(B,0);
		bool f = false;
		For(i,0,N+1){
			if(!f && cur < B){
				busy[cur-1] = b[cur-1];
				if(i!=N)
					cur++;
			}else{
				f = true;
				int mn = *min_element(all(busy));
				bool foo = false;
				For(j,0,busy.size()){
					busy[j]-=mn;
					if(!foo && busy[j] == 0){
						cur = j+1;
						foo = true;
						busy[j] = b[j];
					}
				}
			}
		}
		cout<<"Case #"<<c++<<": "<<cur<<endl;
	}
	return 0;
}
/**/
