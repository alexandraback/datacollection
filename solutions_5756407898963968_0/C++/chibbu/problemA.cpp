#include <iostream>
#include <vector>
using namespace std;

int main(){

	int t;
	cin>> t;
	for(int k=1; k<=t; k++){
		int r1, r2;
		vector<bool> v(16,false);
		vector<int> ans;
		int arr[4][4];
		cin>> r1;
		r1 -= 1;
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				cin>> arr[i][j];
				if(i==r1) v[arr[i][j]-1]= true;
			}
		}
	
		cin >> r2;
		r2 -= 1;
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				cin>> arr[i][j];
				if(i==r2 && v[arr[i][j]-1]==true) ans.push_back(arr[i][j]);
			}
		}

		if(ans.size()==0) cout<<"Case #"<<k<<": Volunteer cheated!\n";
		if(ans.size()>1) cout<<"Case #"<<k<<": Bad magician!\n";
		if(ans.size()==1) cout<<"Case #"<<k<<": "<<ans[0]<<endl;
	}
	return 0;

}

