#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int order[2][17];

int main(){
	int t, i, j, k, r1, r2, ans;

	cin>>t;
	for (i = 0; i < t; ++i){
		cin>>r1;
		for (j=0; j<16; ++j){
			cin>>k;
			order[0][k] = j/4+1;
		}
		cin>>r2;
		for (j=0; j<16; ++j){
			cin>>k;
			order[1][k] = j/4+1;
		}

		ans = -2;
		for (j=1; j<=16; ++j){
			if (r1==order[0][j] && r2==order[1][j]){
				if (ans==-2){
					ans = j;
				} else if (ans>0){
					ans = -1;
					break;
				}
			}
		}

		cout<<"Case #"<<i+1<<": ";
		if (ans>=0){
			cout<<ans<<endl;
		} else if (ans==-1){
			cout<<"Bad magician!"<<endl;
		} else if (ans==-2){
			cout<<"Volunteer cheated!"<<endl;
		}
	}
	
	return 0;
}