#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
 
using namespace std;

const string sCheat = "Volunteer cheated!";
const string sBadMagican = "Bad magician!";

void input(vector<int> & a)
{
	int x; cin>>x;
	for(int i=1; i<5; ++i)
		for(int j=0, y; j<4; ++j)
		{
			cin>>y;
			if(x==i)
				a[j] = y;
		}
	sort(a.begin(), a.end());
}

void solve()
{
	vector<int> a(4), b(4), intersection;
	input(a); input(b);
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(intersection));
	if(intersection.size()==1)cout<<intersection[0]<<endl;
	else if(intersection.empty())cout<<sCheat<<endl;
	else cout<<sBadMagican<<endl;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("i:/input.txt", "rt", stdin);
	int T; cin>>T;
	for(int t=1; t<=T; ++t)
	{
		cout<<"Case #"<<t<<": ";
		solve();
	}
 
	return 0;
} 