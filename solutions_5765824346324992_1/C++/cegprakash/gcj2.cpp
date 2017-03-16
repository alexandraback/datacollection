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

long long customers, barbers, mins[100005];

long long getStartTimeForLastCustormer(long long start, long long end){
	if(start > end)
		return 1000000000000000000LL;
	long long mid = (start+end)/2;

	long long pplGotCut = 0;
	for(int i=0;i<barbers;i++){
		pplGotCut += mid/mins[i] + 1;
	}

	if(pplGotCut >= customers)
		return min(mid, getStartTimeForLastCustormer(start,mid-1));

	return getStartTimeForLastCustormer(mid+1,end);
}

int main(){
	ios::sync_with_stdio(false);
	freopen("gcj2.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,c=1,i;
	cin>>t;
	while(t--){
		cout<<"Case #"<<c++<<": ";
		cin>>barbers>>customers;
		for(i=0;i<barbers;i++)
			cin>>mins[i];

		long long myEntry = getStartTimeForLastCustormer(0, 1000000000000000000LL);

		long long enteredBeforeMe= 0, enteredWithMe = 0, soFar = 0;
		for(i=0;i<barbers;i++)
			enteredBeforeMe += (myEntry-1)/mins[i]+1;
		enteredWithMe = customers - enteredBeforeMe;
		for(i=0;i<barbers;i++){
			if(myEntry%mins[i] == 0)
				soFar++;
			if(soFar == enteredWithMe)
				break;
		}
		
		cout<<i+1<<endl;
	}

	return 0;
}