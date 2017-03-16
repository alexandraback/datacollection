#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>

using namespace std;

long long int gcd(long long int a, long long int b){
	return b?gcd(b,a%b):a;
}

int main()
{
	ifstream ifs("B-small-attempt0 (8).in");
    ofstream ofs("answer_B_small");
	int T;
	ifs >> T; cout << "T= " << T <<endl;
   
   for(int t=0;t<T;t++){  // test cases
	int B;
    ifs >> B; cout << "B= " << B << endl;
	long long int N;
	ifs>>N; cout<<"N= " <<N<<endl;

	vector<int>VB;
    int tmp;
	VB.push_back(-999);
		for(int i=0;i<B;i++){
          ifs>>tmp; VB.push_back(tmp); //cout <<tmp<<" ";
		}
		//cout<<endl;

	long long int P=1;

	for(int i=1;i<=B;i++){
         P=P*VB[i]/gcd(P,VB[i]);
	}

	cout<<"P= " <<P<<endl;

	long long int Cycle=0;

	for(int i=1;i<=B;i++){
       Cycle+=P/VB[i];
	}
	cout<<"Cycle= " <<Cycle<<endl;

	N=N%Cycle;
	if(N==0){N=Cycle;}
	cout<<"N(reduced)= " <<N<<endl;

	int ans;

	if(N<=B){
        ans=int(N);
	}
	else{ //  N-B>0 //

	vector<pair<long long int,int> > vBQ;

	long long int TIME=0;

	for(int i=1;i<=B;i++){
       vBQ.push_back(pair<long long int,int> (VB[i],i)); //cout <<VB[i]<<" " <<i <<endl;
	}

	   
	int I;
	while(N-B>0){
        sort(vBQ.rbegin(),vBQ.rend());
		TIME=vBQ[B-1].first;
		I=vBQ[B-1].second;
		vBQ.pop_back();
		vBQ.push_back(pair<long long int,int> (VB[I]+TIME, I));
		//cout<<TIME<<"  "<< I <<endl;
		N--;
	}
     ans=I;
	}//else fin
		




	cout << "Case #" <<t+1<<": " << ans <<endl;
    ofs << "Case #" <<t+1<<": " << ans <<endl;

   } // end of test cases

 return 0;
}