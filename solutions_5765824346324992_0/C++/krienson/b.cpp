#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>

using namespace std;

int M[1001];

int main(){
	int kases; cin>>kases;
	for(int kase = 1; kase <= kases; kase++){
		int B;
		long long N; cin>>B>>N;
		for(int i=0;i<B; i++) cin>>M[i];

		long long total_time = 1000000000000000000LL;
		long long a = 0, b = total_time, mid;
		long long current = 0;

		while(a < b){
			mid = (a+b)/2;
			current = 0;
			for(int i=0;i<B;i++){
				current += (1 + (mid/M[i]));
			}
			if(current < N) a = mid + 1;
			else b = mid;
		}
		//cout<<a<<endl;
		vector<int> p;
		current = 0;
		for(int i = 0;i<B;i++){
			current += 1+(a/M[i]);
			if(a%M[i] == 0){ current--;
				p.push_back(i);
				//cout<<"Insert barber: "<<i+1<<endl;
			}
		} //cout<<"N: "<<N<<" CU: "<<current<<endl;
		//cout<<"Final current served: "<<current<<endl;
		cout<<"Case #"<<kase<<": "<<p[N-(current+1)]+1<<endl;	
	}
}
