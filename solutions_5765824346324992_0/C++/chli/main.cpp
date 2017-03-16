#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;


// use multimap



long long nonQued(vector<int>& timeB, long long t){
	long long acc=0;
	if(t==0)return 0;
	for(int i = 0 ; i < timeB.size() ; i++){
		acc+= t/timeB[i]+1;
	}
	return acc;
}


#define MAXT 10e16


long long binSearch( long long minT, long long maxT, vector<int>& timeB, long long N){
	long long targetT = (minT+maxT)/2;
	
	if( nonQued(timeB,targetT)<N ){
		if(nonQued(timeB, targetT+1)>=N){
//			cout<< nonQued(timeB,targetT)<<" "<<nonQued(timeB,targetT+1)<<endl;
			return targetT;
		}else{
			return binSearch(targetT+1,maxT,timeB,N);
		}
	}else{
		return binSearch(minT, targetT-1,timeB,N);
	}
}


int execute(){

	int Bnum;
	long long N;

	cin>> Bnum>>N;
	vector<int> timeB(Bnum);


	for(int i =0 ; i<Bnum;i++){
		cin>> timeB[i];
	}
	

	long long targetT= binSearch(0,MAXT,timeB,N);
	long long nonQ   = nonQued(timeB,targetT); 
//	cout<<"targetT "<< targetT<<endl;
//	cout<<"nonQ    "<< nonQ<<endl;	
	
	for(int i = 0 ; i < Bnum ; i++){
		if((targetT+1)%timeB[i] ==0  )nonQ++;
		if(nonQ==N) return i+1;
	}

}


int main(){
	int T;
	cin>>T;
	for(int i = 0 ; i < T ; i++){
		cout<<"Case #"<<i+1<<": "<<execute()<<endl;
	}
	return 0;
}
