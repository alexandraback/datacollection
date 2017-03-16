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

bool check(long long mid,int N,vector <int> &bar){
	long long tmp=0;
	for(int i=0;i<bar.size();i++){
		tmp+=mid/bar[i]+1LL;
	}
	if(tmp>=N) return 1;
	return 0;
}

int main() {
	io();
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		int B,N;
		cin>>B>>N;
		vector <int> bar(B);
		for(int i=0;i<B;i++){
			cin>>bar[i];
		}

		long long l=-1;
		long long r=1101010101010101010;
		while(l+1<r){
			long long mid=(l+r)/2;
			if(check(mid,N,bar)){
				r=mid;
			}else{
				l=mid;
			}
		}

		long long now=0;
		for(int i=0;i<B;i++){
			now+=r/bar[i]+1LL;
		}

		long long res=now-N;
		int ret=0;
		for(int i=B-1;i>=0;i--){
			if(r%bar[i]==0){
				res--;
				ret=i;
			}
			if(res==-1) break;
		}

		cout<<"Case #"<<t+1<<": "<<ret+1<<endl;
	}


	return 0;
}