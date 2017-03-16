#include <iostream>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

int t[10001];
string result(){
	int N;
	cin>>N;
	for (int i=0; i<N; i++){
		cin>>t[i];
	}
	int sum1 = 0;
	for(int i=0; i<N-1; i++){
		if (t[i]-t[i+1]>0){
			sum1+=(t[i]-t[i+1]);
		}
	}
	int x = 0;
	for (int i=0; i<N-1; i++){
		if (t[i]-t[i+1]>0){
			x = max(x,(t[i]-t[i+1]));
		}
	}
	int sum = 0;
	for (int i=0; i<N-1; i++){
		sum += max(0, min(t[i], x));
	}
	return to_string(sum1)+" "+to_string(sum);
}

int main(){
	int T;
	cin>>T;
	for (int i=0; i<T; i++){
		cout<<"Case #"<<i+1<<": "<<result()<<endl;
	}
}