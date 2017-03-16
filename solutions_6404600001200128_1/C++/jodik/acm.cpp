#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

#define MAXM 1100000


int main() {
	int t;
	cin>>t;
	for(int c = 1; c <= t; ++c){
		int number, a;
		cin>>number;
		vector<int> sequence;
		while(number--){
			cin>>a;
			sequence.push_back(a);
		}
		int first = 0, second = 0, maxdif = 0;
		for(int i = 1; i < sequence.size(); i++){
			if(sequence[i] < sequence[i-1]){
				first-=sequence[i] - sequence[i-1];
				maxdif = max(maxdif, -sequence[i] + sequence[i-1]);
			}
		}
		for(int i = 0; i < sequence.size()-1; i++){
			if(sequence[i] > maxdif){
				second+=maxdif;
			}
			else {
				second+=sequence[i];
			}
		}
		cout<<"Case #"<<c<<": "<<first<<" "<<second<<endl;
	}
}