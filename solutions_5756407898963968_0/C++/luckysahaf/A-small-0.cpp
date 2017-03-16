#include <iostream>


using namespace std;

int main(){
	int T,ans[2],arrangements[8],number=0,junk;
	bool bad_magician;
	cin >> T;
	for(int i=0;i<T;i++){
		for(int j=0;j<2;j++){
			cin >> ans[j];
			ans[j]--;
			for(int k=0;k<16;k++){
				if(k>=ans[j]*4 && k<ans[j]*4+4){
					cin >> arrangements[j*4 + k%4];
				}
				else
					cin >> junk;
			}
		}
		bad_magician = false;
		number = 0;
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				if(arrangements[j] == arrangements[4 + k]){
					if(number == 0){
						number = arrangements[j];
					}
					else{
						bad_magician = true;
						break;
					}
				}
			}
			if(bad_magician)
				break;
		}
		if(bad_magician){
			cout << "Case #" << i+1 << ": Bad magician!" << endl;
		}
		else if(number == 0){
			cout << "Case #" << i+1 << ": Volunteer cheated!" << endl;
		}
		else{
			cout << "Case #" << i+1 << ": " << number << endl;
		}
	}
}