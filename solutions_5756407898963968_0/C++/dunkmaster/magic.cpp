#include <set>
#include <iostream>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int r1;
		cin >> r1;
		int a[4][4];
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cin >> a[i][j];
			}
		}
		set<int> s;
		for(int i=0;i<4;i++){
			s.insert(a[r1-1][i]);
		}
		set<int> s2;
		int r2;
		cin >> r2;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cin >> a[i][j];
			}
		}
		for(int i=0;i<4;i++){
			if(s.count(a[r2-1][i]))
				s2.insert(a[r2-1][i]);
		}
		cout<<"Case #"<<t+1<<": ";
		if(s2.size()==1){
			cout<<*s2.begin();
		} else if(s2.size()>1){
			cout<<"Bad magician!";
		} else {
			cout<<"Volunteer cheated!";
		}
		cout<<endl;
	}
}
