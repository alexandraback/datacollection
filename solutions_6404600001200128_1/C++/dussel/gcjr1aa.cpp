/* attention to overflow */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <queue>
#include <sstream>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <tuple>
#include <iomanip>

#define dump(x) cerr<< #x << " = " << x <<endl
#define ALL(container) (container).begin(),(container).end()

using namespace std;
const int INF = 1 << 25;
void io() { cin.tie(0); ios::sync_with_stdio(false);}
template <class S,class T> ostream& operator<<(ostream& os, const pair <S,T> &s){return os<<'('<<s.first<<','<<s.second<<')';}
/*printf("%.9Lf\n",cf);*/
const int MOD = 1000000007;
const double EPS=1e-8;


int main() {
	io();
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n;
		cin>>n;
		vector <int> mash(n);
		for(int j=0;j<n;j++){
			cin>>mash[j];
		}
		int st_a=0;
		int st_b=0;

		int mx=0;
		for(int j=1;j<n;j++){
			if(mash[j-1]-mash[j]>0){
				st_a+=mash[j-1]-mash[j];
				mx=max(mx,mash[j-1]-mash[j]);
			}
		}

		for(int j=0;j<n-1;j++){
			st_b+=min(mash[j],mx);
		}

		cout<<"Case #"<<i+1<<": "<<st_a<<' '<<st_b<<endl;
	}


	return 0;
}