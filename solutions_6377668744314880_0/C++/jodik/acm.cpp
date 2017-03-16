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
		long long n, a, b;
		vector<pair<long long, long long> > trees;
		cin>>n;
		while(n--){
			cin>>a>>b;
			trees.push_back(make_pair(a,b));			
		}
		cout<<"Case #"<<c<<":"<<endl;
		for(int i = 0; i < trees.size(); i++){
			if(trees.size() <= 3)
				cout<<0<<endl;
			else{
			long long najm = trees.size();
			for(int j = 0; j < trees.size(); j++){
				if(j == i)
					continue;
				pair<long long, long long> vec (trees[j].first - trees[i].first, trees[j].second - trees[i].second);
				pair<long long, long long> vec2; 
				long long jedni = 0;
				long long druhe = 0;
				for(int k = 0; k < trees.size(); k++){
					if(k == j || k == i )
						continue;
					vec2.first = trees[k].first - trees[i].first;
					vec2.second = trees[k].second - trees[i].second;
					long long vysl = vec.first * vec2.second - vec.second * vec2.first;
					//cout<<vysl<<endl;
					if(vysl > 0)
						jedni++;
					else if (vysl < 0)
						druhe++;
				}
				if(jedni < najm)
					najm = jedni;
				if(druhe < najm)
					najm = druhe;
			}
			cout<<najm<<endl;
			}
		}
				
	}
}