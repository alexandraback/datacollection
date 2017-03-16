#include <iostream>
#include <sstream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){

	freopen("q1.txt", "r", stdin);
	freopen("q1.out", "w", stdout);

	int cases;
	cin>>cases;

	for(int i=0;i<cases;i++){
		
		int n = 0, n_;
		cin>>n;
		int v[4];
		for(int j=0;j<(n-1)*4;j++)	cin>>n_;
		for(int j=0;j<4;j++){
			cin>>n_;
			v[j] = n_;
		}
		for(int j=0;j<(4-n)*4;j++)	cin>>n_;

		int m = 0, m_;
		cin>>m;
		int v_[4];
		for(int j=0;j<(m-1)*4;j++)	cin>>m_;
		for(int j=0;j<4;j++){
			cin>>m_;
			v_[j] = m_;
		}
		for(int j=0;j<(4-m)*4;j++)	cin>>m_;

		vector<int> v__;

		sort(v, v+4);
		sort(v_, v_+4);

		std::set_intersection (v, v+4, v_, v_+4, std::back_inserter(v__));

		cout<<"Case #"<<i+1<<": ";

		if(v__.size() == 0)
			cout<<"Volunteer cheated!"<<endl;
		else if(v__.size() == 1)
			cout<<v__[0]<<endl;
		else
			cout<<"Bad magician!"<<endl;

	}
	return 0;
}