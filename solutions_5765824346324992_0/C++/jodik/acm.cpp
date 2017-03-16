#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

#define MAXM 1100000

long long AT_MOST = 1000000000000000;
long long N;

vector<long long> barbers;

long long binarne(long long l, long long r){
	//cout<<l<<" "<<r<<endl;
	long long s = (l+r)/2;
	long long odbavenych = 0;
	vector<int> volnych;
	for(int i = 0; i < barbers.size(); i++){
		odbavenych += s/barbers[i];
		if(s % barbers[i] == 0){
			volnych.push_back(i+1);
		}
		else if(s%barbers[i] > 0){
			odbavenych++;
		}
	}
	if (odbavenych > N-1){
		return binarne(l, s);
	}
	else if (odbavenych <= N-1 && odbavenych + volnych.size() >= N){
		long long kolky = N - odbavenych - 1;
		return volnych[kolky];
	}
	else{
		return binarne(s, r);
	}
}

int main() {
	int t;
	cin>>t;
	for(int c = 1; c <= t; ++c){
		long long b,n;
		cin>>b>>n;
		N = n;
		barbers.resize(b);
		for(int i = 0; i < b; i++){
			cin>>barbers[i];
		}
				
		cout<<"Case #"<<c<<": "<<binarne(0, AT_MOST)<<endl;
	}
}