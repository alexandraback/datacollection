#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

long long calc(const vector<long long>& a, long long t, long long maxK){
	int n = a.size();
	long long sum = 0;
	for(int i=0; i<n; i++){
		sum += t/a[i]+1L;
		if(sum>maxK){
			return maxK + 10;
		}
	}
	return sum;
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		long long n, k;
		cin>>n>>k;
		vector<long long> a(n);
		for(int i=0; i<n; i++) cin>>a[i];
		if(k<=n){
			cout<<"Case #"<<testnum+1<<": "<<k<<endl;
			continue;
		}
		long long maxLen = *max_element(a.begin(),a.end());
		long long start = 0, end = maxLen*k+1;
		while(start<=end){
			long long cur = (start+end)/2;
			if(calc(a, cur, k)>=k){
				end = cur-1;
			}else{
				start = cur+1;
			}
//			cerr<<start<<' '<<end<<endl;
		}
		long long tt = start;
		long long prev = calc(a, tt-1, k);
		assert(prev<k);
		int rez = -1;
		for(int i=0; i<n && prev<k; i++){
			if(tt%a[i]==0){
				rez = i+1;
				prev++;
			}
		}
//		cerr<<tt<<' '<<prev<<' '<<k<<endl;
		assert(prev==k);
		cout<<"Case #"<<testnum+1<<": "<<rez<<endl;
	}
	return 0;
}
