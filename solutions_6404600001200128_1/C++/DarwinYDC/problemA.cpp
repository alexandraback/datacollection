#include <iostream>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

int64_t t[10001];
string result(){
	int64_t N;
	cin>>N;
	for (int64_t i=0; i<N; i++){
		cin>>t[i];
	}
	int64_t sum1 = 0;
	for(int64_t i=0; i<N-1; i++){
		if (t[i]-t[i+1]>0){
			sum1+=(t[i]-t[i+1]);
		}
	}
	int64_t x = 0;
	for (int64_t i=0; i<N-1; i++){
		if (t[i]-t[i+1]>0){
			x = max(x,(t[i]-t[i+1]));
		}
	}
	int64_t sum = 0;
	for (int64_t i=0; i<N-1; i++){
		if (t[i]>0){
			sum += min(t[i], x);
		}
	}
	return to_string(sum1)+" "+to_string(sum);
}

int main(){
	int64_t T;
	cin>>T;
	for (int64_t i=0; i<T; i++){
		cout<<"Case #"<<i+1<<": "<<result()<<endl;
	}
}