#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <set>
#include <cstring>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	freopen("gcj1.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,c=1;
	cin>>t;
	while(t--){
		cout<<"Case #"<<c++<<": ";

		long long ans1=0, ans2=0, intervals, arr[1005];
		long long speed = 0,i;

		cin>>intervals;
		for(i=0;i<intervals;i++){
			cin>>arr[i];
		}

		for(i=0;i<intervals-1;i++){
			ans1 += max(0LL,arr[i]-arr[i+1]);
			speed = max(speed,arr[i]-arr[i+1]);
		}

		long long ate = 0;
		for(i=0;i<intervals-1;i++){
			ate += min(speed, arr[i]);
		}
		cout<<ans1<<" "<<ate<<endl;

	}

	return 0;
}