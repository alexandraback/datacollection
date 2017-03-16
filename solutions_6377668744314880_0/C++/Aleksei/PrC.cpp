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

struct Point{
	long long x, y;
	Point(long long xx=0, long long yy=0){
		x = xx; y = yy;
	}
};

inline bool bitSet(const int mask, const int k){
	return (mask & (1<<k))!=0;
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int n;
		cin>>n;
		vector<Point> a(n);
		for(int i=0; i<n; i++) cin>>a[i].x>>a[i].y;
		int end = (1<<n);
		vector<bool> use(n);
		vector<int> result(n, n);
		for(int mask = 1; mask<end; mask++){
			int removed = 0;
			for(int i=0; i<n; i++){
				bool st = bitSet(mask,i);
				use[i] = st;
				if(!st) removed++;
			}
			if(n-removed<=3){
				for(int i=0; i<n; i++){
					if(use[i]){
						result[i] = min(result[i],removed);
					}
				}
			}else{
				for(int i=0; i<n; i++){
					if(!use[i]) continue;
					for(int j=i+1; j<n; j++){
						if(!use[j]) continue;
						long long lastSign = 0;
						long long A = a[i].y - a[j].y;
						long long B = a[j].x - a[i].x;
						long long C = a[i].x*a[j].y - a[j].x*a[i].y;
						bool ok = true;
						for(int k=0; k<n && ok; k++){
							if(!use[k]) continue;
							long long newSign = A*a[k].x + B*a[k].y + C;
							if(newSign!=0){
								if(lastSign==0) lastSign=newSign;
								else if((lastSign>0 && newSign<0) || (lastSign<0 && newSign>0)) ok = false;
							}
						}
						if(ok){
							result[i] = min(result[i],removed);
							result[j] = min(result[j],removed);
						}
					}
				}
			}
		}
		cout<<"Case #"<<testnum+1<<":"<<endl;
		for(int i=0; i<n; i++) cout<<result[i]<<endl;
	}
	return 0;
}
