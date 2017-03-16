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

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0; i<n; i++) cin>>a[i];
		int case1 = 0;
		int maxDiff = 0;
		for(int i=1; i<n; i++){
			if(a[i-1]>a[i]){
				case1+=(a[i-1]-a[i]);
				maxDiff = max(maxDiff, a[i-1]-a[i]);
			}
		}
		int case2 = 0;
		for(int i=0; i<n-1; i++){
			case2+=(min(a[i],maxDiff));
		}
		cout<<"Case #"<<testnum+1<<": "<<case1<<" "<<case2<<endl;
	}
	return 0;
}
