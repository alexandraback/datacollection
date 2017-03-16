#include <iostream>
#include <vector>


using namespace std;




int way1(vector<int>& seq){

}

int way2(vector<int>& seq){

}

int execute(){
	int N;
	cin>>N;
	vector<int> seq(N);
	int tmp;

	int way1Sol=0;
	int way2Sol=0;
	int way2MaxSlope=0;
	for(int i = 0 ; i < N ; i++){
		cin>>seq[i];
		if(i!=0){
			int diff = seq[i]-seq[i-1];
			if(seq[i]-seq[i-1]<0){
				way1Sol+=(0-diff);
				if(0-diff>way2MaxSlope)way2MaxSlope = 0-diff;
			}
		}
	}

	int currentRemains=0;
	for(int i = 0 ; i < N ; i++){
		if(i==0){
			currentRemains = seq[i] ;
		}else{
			if(currentRemains - way2MaxSlope <0){
				way2Sol += currentRemains ;
			}else{
				way2Sol += way2MaxSlope;
			}
			currentRemains = seq[i];
		}
	}
	cout<<way1Sol<<" "<<way2Sol<<endl;
}

int main(){
	int T;


	cin>> T;
	for(int i = 0 ; i < T ; i++){
		cout<<"Case #"<<i+1<<": ";execute();
	}
	return 0;
}
