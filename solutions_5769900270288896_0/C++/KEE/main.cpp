/**/
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define For(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(v) v.begin(),v.end()
#define V vector
typedef long long ll;
/***********************************************/
/* Dear MinGW compiler:
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
const ll mod = 1000000007;
V<V<bool> > grid;
int res = INT_MAX;
bool vaild(int i,int j){
	if(i < 0 || j < 0 || i >= (int)grid.size() || j >= (int)grid[i].size())
		return false;
	return true;
}
void bt(int i,int j,int c,int cur){
	if(c == 0){
		res = min(res,cur);
		return;
	}
	if(!vaild(i,j))
		return;
	grid[i][j] = false;
	if(j + 1 == (int)grid[i].size())
		bt(i+1,0,c,cur);
	else
		bt(i,j+1,c,cur);
	int to = 0;
	if(j > 0 && grid[i][j-1])
		to++;
	if(i > 0 && grid[i-1][j])
		to++;
	grid[i][j] = true;
	if(j + 1 == (int)grid[i].size())
		bt(i+1,0,c-1,cur+to);
	else
		bt(i,j+1,c-1,cur+to);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("B-small-attempt1.in","r",stdin);
	freopen("myfile.txt","w",stdout);
	int t,r,c,ca = 1,x;
	cin>>t;
	while(t--){
		res = INT_MAX;
		cin>>r>>c>>x;
		if(x <= ((r*c) >> 1) + ((r*c) &1) ){
			cout<<"Case #"<<ca++<<": 0"<<endl;
			continue;
		}
		grid = V<V<bool> >(r,V<bool>(c,false));
		bt(0,0,x,0);
		cout<<"Case #"<<ca++<<": "<<res<<endl;
	}
	return 0;
}
/**/
