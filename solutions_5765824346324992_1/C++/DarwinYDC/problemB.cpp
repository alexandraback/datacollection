#include <iostream>
#include <cassert>

using namespace std;

int64_t M[100005];

int64_t number(int64_t B, int64_t T){
	int64_t sum = 0;
	for (int64_t i=0; i<B; i++){
		sum += T/M[i];
		if (T%M[i]!=0) sum ++;
	}
	return sum;
}

int64_t result(){
	int64_t B,N;
	cin>>B>>N;
	for (int64_t i=0; i<B; i++){
		cin>>M[i];
	}
	int64_t start = 0;
	int64_t end = 1000000000000000;
	int64_t middle;
	int64_t served;
	while(start<end){
		middle = (start+end+1)/2;
		served = number(B, middle);
		if (served <= N-1){
			start = middle;
		}else{
			end = middle-1;
		}
	}
	// cout<<end-start<<endl;
	served = number(B, start);
	int64_t k=N-number(B, start);
	// assert(number(B, start+1)>=N && number(B, start)<N);
	// cout<<number(B, middle+1);
	for (int64_t i=0; i<B; i++){
		if (start%M[i]==0){
			k --;
			if (k==0) return (i+1);
		}
	}
	return -1;

}

int main(){
	int64_t T;
	cin>>T;
	for (int64_t i=0; i<T; i++){
		cout<<"Case #"<<i+1<<": "<<result()<<endl;
	}
}