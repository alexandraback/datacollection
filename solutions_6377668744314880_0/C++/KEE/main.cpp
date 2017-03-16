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
struct point{
	ll x,y;
	point(int _x,int _y){
		x = _x;
		y = _y;
	}
};
ll cross(point o,point a,point b) {
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
bool cmp(pair<point,int> a,pair<point,int> b){
	if(a.first.x!=b.first.x)
		return a.first.x < b.first.x;
	return a.first.y < b.first.y;
}
V<bool> use;
int res;
V<pair<point,int> > points;
void backtrack(int i,int ind,int cres){
	if(ind == (int)use.size()){
		/*cout<<i<<endl;
		cout<<points[i].x<<' '<<points[i].y<<endl;
		For(j,0,use.size()){
			cout<<boolalpha<<use[j]<<" \n"[j==use.size()-1];
		}*/
		V<point> lower,upper;
		For(j,0,points.size()){
			if(!use[j])
				continue;
			while (lower.size() >= 2 && cross(lower[lower.size() - 2], lower[lower.size() - 1], points[j].first) < 0LL) {
				lower.pop_back();
			}
			lower.pb(points[j].first);
		}
		For(j,points.size(),0) {
			if(!use[j])
				continue;
			while (upper.size() >= 2 && cross(upper[upper.size() - 2], upper[upper.size() - 1], points[j].first) < 0LL) {
				upper.pop_back();
			}
			upper.pb(points[j].first);
		}
		//upper.pop_back();
		//lower.pop_back();
		/*For(j,0,upper.size()){
			cout<<upper[j].x<<' '<<upper[j].y<<endl;
		}
		For(j,0,lower.size()){
			cout<<lower[j].x<<' '<<lower[j].y<<endl;
		}*/
		bool can = false;
		For(j,0,upper.size()){
			if(upper[j].x == points[i].first.x && upper[j].y == points[i].first.y){
				can = true;
				break;
			}
		}
		if(!can){
			For(j,0,lower.size()){
				if(lower[j].x == points[i].first.x && lower[j].y == points[i].first.y){
					can = true;
					break;
				}
			}
		}
		if(can)
			res = min(res,cres);
		return;
	}
	use[ind] = true;
	if(res == 0)
		return;
	backtrack(i,ind+1,cres);
	if(res == 0)
		return;
	if(ind != i){
		use[ind] = false;
		backtrack(i,ind+1,cres+1);
		use[ind] = true;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("C-small-attempt1.in","r",stdin);
	freopen("myfile.txt","w",stdout);
	int t,c = 1;
	cin>>t;
	while(t--){
		points.clear();
		int n,x,y;
		cin>>n;
		For(i,0,n){
			cin>>x>>y;
			points.pb({point(x,y),i});
		}
		sort(all(points),cmp);
		V<int> ans(n);
		cout<<"Case #"<<c++<<":"<<endl;
		use = V<bool>(n,true);
		For(i,0,points.size()){
			res = INT_MAX;
			backtrack(i,0,0);
			ans[points[i].second] = res;
		}
		For(i,0,n)
		cout<<ans[i]<<endl;
	}
	return 0;
}
/**/
